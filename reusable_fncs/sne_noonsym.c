/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sne_noonsym.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hportife <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 16:52:30 by hportife          #+#    #+#             */
/*   Updated: 2022/01/15 16:52:32 by hportife         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

int	sne_noonsym(char *str, char sym)
{
	if ((!str) || (str[0] != sym) || (str[ft_strlen(str) - 1] != sym))
		return (1);
	return (0);
}
