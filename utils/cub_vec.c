/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_vec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttranche <ttranche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 19:55:51 by ttranche          #+#    #+#             */
/*   Updated: 2021/03/19 12:20:22 by ttranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

/*
** Normalizes a vector
*/

void	normalize(t_vecd *vec, double scale)
{
	double len;

	len = sqrt(vec->x * vec->x + vec->y * vec->y);
	if (len < 0.0001)
	{
		vec->x = 0;
		vec->y = 0;
		return ;
	}
	vec->x /= len;
	vec->y /= len;
	vec->x *= scale;
	vec->y *= scale;
}

double	calc_sqrtlen(t_vecd v)
{
	return (sqrt(v.x * v.x + v.y * v.y));
}
