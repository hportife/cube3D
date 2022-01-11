/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_raycast2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttranche <ttranche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 21:45:12 by ttranche          #+#    #+#             */
/*   Updated: 2021/03/19 11:17:35 by ttranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

t_vec		get_collide_pos(t_trace trace)
{
	t_vec pos;

	if (trace.ray.ln_cos > trace.ray.ln_sin)
	{
		pos.x = floor(trace.ref.x + trace.ray.st_sin.x);
		pos.y = floor(trace.ref.y + trace.ray.st_sin.y + trace.rot.sin / 2);
		return (pos);
	}
	pos.x = floor(trace.ref.x + trace.ray.st_cos.x + trace.rot.cos / 2);
	pos.y = floor(trace.ref.y + trace.ray.st_cos.y);
	return (pos);
}

int			check_collide(t_gen *gen, t_vec pos)
{
	return (map_get(gen->map_srcs, pos.x, pos.y));
}

t_img		*get_texture(t_gen *gen, t_cardinal card)
{
	if (card == EAST)
		return (&(gen->data->no));
	if (card == WEST)
		return (&(gen->data->so));
	if (card == NORTH)
		return (&(gen->data->we));
	return (&(gen->data->ea));
}
