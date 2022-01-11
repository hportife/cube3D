/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttranche <ttranche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 19:58:22 by ttranche          #+#    #+#             */
/*   Updated: 2021/03/22 13:20:44 by ttranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

t_player	make_player(void)
{
	t_player player;

	player.pos.x = 0;
	player.pos.y = 0;
	player.s_pos.x = player.pos.x;
	player.s_pos.y = player.pos.y;
	player.motion.x = 0;
	player.motion.y = 0;
	player.motion_yaw = 0;
	player.yaw = 0;
	player.pitch = -40;
	player.motion_yaw = 0;
	player.motion_pitch = 8;
	player.keybinds = make_keybinds();
	return (player);
}

void		handle_keys(t_player *player)
{
	float ratio;

	ratio = (float)0.68;
	if (player->keybinds.rotate_left && !player->keybinds.rotate_right)
		player->motion_yaw -= 0.002;
	else if (player->keybinds.rotate_right && !player->keybinds.rotate_left)
		player->motion_yaw += 0.002;
	else
		player->motion_yaw *= 0.895;
	player->motion.x *= ratio;
	player->motion.y *= ratio;
}

void		update_render(t_player *player, t_gen *gen)
{
	player->render.x = player->pos.x;
	player->render.y = player->pos.y;
	if (map_get(gen->map_srcs, floor(player->render.x), floor(player->render.y)))
	{
		player->render.x = player->pos.x;
		player->render.y = player->pos.y;
	}
}

void		update_motion(t_player *player, t_gen *gen)
{
	double	cs;
	double	sn;
	t_vecd	move;

	move = player->keybinds.move;
	cs = cos(player->yaw);
	sn = sin(player->yaw);
	player->motion.x += move.x * cs - move.y * sn;
	player->motion.y += move.y * cs + move.x * sn;
	handle_keys(player);
	player->motion_yaw *= 0.914;
	player->motion_pitch *= 0.82;
	collidex(gen, player);
	collidey(gen, player);
	update_render(player, gen);
	player->yaw += player->motion_yaw;
	player->pitch = fmin(gen->resy / 4 - 4, fmax(-gen->resy / 4,
		player->pitch + player->motion_pitch));
}
