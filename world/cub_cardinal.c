/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_cardinal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hportife <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 12:05:13 by hportife          #+#    #+#             */
/*   Updated: 2022/01/04 12:08:33 by hportife         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

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
