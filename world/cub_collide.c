/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_collide.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hportife <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 12:05:13 by hportife          #+#    #+#             */
/*   Updated: 2022/01/04 12:08:33 by hportife         ###   ########.fr       */
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
	int	side;

	side = floor(player->pos.y + player->motion.y);
	if (!map_get(gen->map_srcs, floor(player->pos.x), side))
		player->pos.y += player->motion.y;
	else
	{
		player->motion.y = 0;
	}
}
