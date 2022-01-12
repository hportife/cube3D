/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_keybinds.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hportife <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 12:05:13 by hportife          #+#    #+#             */
/*   Updated: 2022/01/04 12:08:33 by hportife         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

void	set_keystate(t_keybinds *keybinds, int key, bool pressed)
{
	if (key == ROTATE_LEFT)
		keybinds->rotate_left = pressed;
	else if (key == ROTATE_RIGHT)
		keybinds->rotate_right = pressed;
	else if (key == FORWARD_W_Z)
		keybinds->forwards = pressed;
	else if (key == BACK_S_S)
		keybinds->backwards = pressed;
	else if (key == LEFT_A_Q)
		keybinds->left = pressed;
	else if (key == RIGHT_D_D)
		keybinds->right = pressed;
}

int	key_press(int keycode, t_gen *gen)
{
	set_keystate(&(gen->player.keybinds), keycode, true);
	if (keycode == ESC)
		clean_and_exit(0, gen);
	return (0);
}

int	key_lift(int keycode, t_gen *gen)
{
	set_keystate(&(gen->player.keybinds), keycode, false);
	return (0);
}

t_keybinds	make_keybinds(void)
{
	t_keybinds	keys;

	keys.forwards = false;
	keys.backwards = false;
	keys.left = false;
	keys.right = false;
	keys.rotate_left = false;
	keys.rotate_right = false;
	keys.move.x = 0;
	keys.move.y = 0;
	return (keys);
}

void	update_keybinds(t_gen *gen)
{
	t_keybinds	*keys;

	keys = &(gen->player.keybinds);
	keys->move.x = 0;
	if (!(keys->forwards && keys->backwards))
	{
		if (keys->forwards)
			keys->move.x = 1;
		else if (keys->backwards)
			keys->move.x = -1;
	}
	keys->move.y = 0;
	if (!(keys->left && keys->right))
	{
		if (keys->left)
			keys->move.y = -1;
		else if (keys->right)
			keys->move.y = 1;
	}
	if (gen->player.keybinds.forwards && !gen->player.keybinds.backwards)
		normalize(&(keys->move), 0.0085);
	else
		normalize(&(keys->move), 0.0065);
}
