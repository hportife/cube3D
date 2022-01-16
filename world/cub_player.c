/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hportife <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 12:05:13 by hportife          #+#    #+#             */
/*   Updated: 2022/01/04 12:08:33 by hportife         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

void	make_player(t_player *player)
{
	player->pos.x = 0;
	player->pos.y = 0;
	player->s_pos.x = player->pos.x;
	player->s_pos.y = player->pos.y;
	player->motion.x = 0;
	player->motion.y = 0;
	player->motion_yaw = 0;
	player->yaw = 0;
	player->motion_yaw = 0;
	player->keybinds = make_keybinds();
}

void	handle_keys(t_player *player)
{
	float	ratio;

	ratio = (float)0.44;
	if (player->keybinds.rotate_left && !player->keybinds.rotate_right)
		player->motion_yaw -= 0.002;
	else if (player->keybinds.rotate_right && !player->keybinds.rotate_left)
		player->motion_yaw += 0.002;
	player->motion.x *= ratio;
	player->motion.y *= ratio;
}

void	update_render(t_player *player, t_gen *gen)
{
	player->render.x = player->pos.x;
	player->render.y = player->pos.y;
	if (map_get(gen->map_srcs,
			floor(player->render.x), floor(player->render.y)))
	{
		player->render.x = player->pos.x;
		player->render.y = player->pos.y;
	}
}

void	update_motion(t_player *player, t_gen *gen)
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
	collidex(gen, player);
	collidey(gen, player);
	update_render(player, gen);
	player->yaw += player->motion_yaw;
}

int	set_player(t_gen *gen, char c, t_vec p)
{
	int	val;

	if (c == 'E')
		val = 0;
	else if (c == 'S')
		val = 1;
	else if (c == 'W')
		val = 2;
	else if (c == 'N')
		val = 3;
	else
		return (0);
	make_player(&gen->player);
	gen->player.pos.x = p.x + 0.50001;
	gen->player.pos.y = p.y + 0.50001;
	gen->player.s_pos.x = gen->player.pos.x;
	gen->player.s_pos.y = gen->player.pos.y;
	gen->player.yaw = M_PI / 2.0 * val;
	return (1);
}
