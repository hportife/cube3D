/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_raycast.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttranche <ttranche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 20:12:03 by ttranche          #+#    #+#             */
/*   Updated: 2021/03/19 11:50:30 by ttranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

t_ray	get_init_ray(t_rot *rot, double x, double y)
{
	t_ray	ray;

	ray.st_cos.x = rot->cos > 0 ? floor(x + 1) - x : ceil(x - 1) - x;
	ray.st_cos.y = ray.st_cos.x * (rot->sin / rot->cos);
	ray.ln_cos = calc_sqrtlen(ray.st_cos);
	ray.st_sin.y = rot->sin > 0 ? floor(y + 1) - y : ceil(y - 1) - y;
	ray.st_sin.x = ray.st_sin.y * (rot->cos / rot->sin);
	ray.ln_sin = calc_sqrtlen(ray.st_sin);
	return (ray);
}

/*
** Calculates the texture offset for the main ray hit
*/

double	tex_offset(t_trace trace)
{
	double offset;

	if (trace.ray.ln_cos < trace.ray.ln_sin)
	{
		offset = trace.ref.x + trace.ref.y + trace.ray.st_cos.x
			+ trace.ray.st_cos.y;
		offset -= (int)offset;
		if (trace.rot.cos < 0)
			offset = 1 - offset;
	}
	else
	{
		offset = trace.ref.x + trace.ref.y + trace.ray.st_sin.x
			+ trace.ray.st_sin.y;
		offset -= (int)offset;
		if (trace.rot.sin > 0)
			offset = 1 - offset;
	}
	return (offset);
}

/*
** Setups the t_shape of the row (x) that'll be drawn to the main buffer,
** and some other stuff like the texture offset for it etc...
*/

void	setup_line(t_gen *gen, t_trace *tr)
{
	tr->card = get_cardinal(*tr);
	tr->len = fmin(tr->ray.ln_cos, tr->ray.ln_sin);
	tr->line.height = gen->resy / (tr->len * cos(tr->newa));
	tr->line.y = (gen->resy - tr->line.height) / 2;
	tr->line.y += gen->player.pitch * 2;
	tr->line.img = get_texture(gen, tr->card);
	tr->offset = tex_offset(*tr);
}

/*
** Handles the casting forward of the ray, and calls the draw functions if it
** does hit
*/

int	do_ray(t_gen *gen, t_trace *tr, t_img *img)
{
	tr->pos = get_collide_pos(*tr);
	if (check_collide(gen, tr->pos))
	{
		setup_line(gen, tr);
		set_img_strip(img, tr->line, tr->offset);
		return (0);
	}
	cast_forward(&(tr->ray), tr->step);
	return (1);
}

/*
** Starts all the ray casting for every row on the screen
*/

void	ray(t_gen *gen, t_img *img)
{
	t_trace	trace;

	trace.line.x = -1;
	while (++trace.line.x < gen->resx)
	{
		trace.newa = atan2((trace.line.x / (double)gen->resx) - .5, gen->fov);
		trace.rot = make_rot(gen->player.yaw + trace.newa);
		trace.ref.x = gen->player.render.x;
		trace.ref.y = gen->player.render.y;
		trace.ray = get_init_ray(&(trace.rot), trace.ref.x, trace.ref.y);
		trace.step = get_init_ray(&(trace.rot), 0, 0);
		trace.i = 0;
		while (do_ray(gen, &trace, img))
			;
	}
}
