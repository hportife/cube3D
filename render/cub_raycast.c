/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_raycast.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hportife <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 12:05:13 by hportife          #+#    #+#             */
/*   Updated: 2022/01/04 12:08:33 by hportife         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

t_ray	get_init_ray(t_rot *rot, double x, double y)
{
	t_ray	ray;

	if (rot->cos > 0)
		ray.st_cos.x = floor(x + 1) - x;
	else
		ray.st_cos.x = ceil(x - 1) - x;
	ray.st_cos.y = ray.st_cos.x * (rot->sin / rot->cos);
	ray.ln_cos = calc_sqrtlen(ray.st_cos);
	if (rot->sin > 0)
		ray.st_sin.y = floor(y + 1) - y;
	else
		ray.st_sin.y = ceil(y - 1) - y;
	ray.st_sin.x = ray.st_sin.y * (rot->cos / rot->sin);
	ray.ln_sin = calc_sqrtlen(ray.st_sin);
	return (ray);
}

double	tex_offset(t_trace trace)
{
	double	offset;

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
