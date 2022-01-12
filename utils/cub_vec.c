/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_vec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hportife <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 12:05:13 by hportife          #+#    #+#             */
/*   Updated: 2022/01/04 12:08:33 by hportife         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

void	normalize(t_vecd *vec, double scale)
{
	double	len;

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
