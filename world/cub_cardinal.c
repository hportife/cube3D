/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_cardinal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttranche <ttranche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 21:27:38 by ttranche          #+#    #+#             */
/*   Updated: 2021/03/19 12:29:31 by ttranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../main.h"

/*
** Gets a cardinal direction based on a raycast hit
*/

t_cardinal	get_cardinal(t_trace trace)
{
	if (trace.ray.ln_cos > trace.ray.ln_sin)
	{
		if (trace.rot.sin > 0)
			return (EAST);
		else
			return (WEST);
	}
	if (trace.rot.cos > 0)
		return (NORTH);
	else
		return (SOUTH);
}
