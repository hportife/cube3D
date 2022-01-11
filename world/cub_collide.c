/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_collide.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttranche <ttranche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 22:41:01 by ttranche          #+#    #+#             */
/*   Updated: 2021/03/19 13:18:59 by ttranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

void	collidex(t_gen *gen, t_player *player)
{
	int			side;

	side = floor(player->pos.x + player->motion.x);
	if (!map_get(gen->map_srcs, side, floor(player->pos.y)))
		player->pos.x += player->motion.x;
	else
	{
		player->motion.x = 0;
	}
}

void	collidey(t_gen *gen, t_player *player)
{
	int			side;
	side = floor(player->pos.y + player->motion.y);
	if (!map_get(gen->map_srcs, floor(player->pos.x), side))
		player->pos.y += player->motion.y;
	else
	{
		player->motion.y = 0;
	}
}
