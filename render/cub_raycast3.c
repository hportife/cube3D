/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_raycast3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hportife <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 12:05:13 by hportife          #+#    #+#             */
/*   Updated: 2022/01/04 12:08:33 by hportife         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

void	cast_forward(t_ray *ray, t_ray step)
{
	if (ray->ln_cos < ray->ln_sin)
	{
		ray->st_cos.x += step.st_cos.x;
		ray->st_cos.y += step.st_cos.y;
		ray->ln_cos += step.ln_cos;
	}
	else
	{
		ray->st_sin.x += step.st_sin.x;
		ray->st_sin.y += step.st_sin.y;
		ray->ln_sin += step.ln_sin;
	}
}
