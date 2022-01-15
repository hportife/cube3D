/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   duarrfree.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hportife <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 11:20:08 by hportife          #+#    #+#             */
/*   Updated: 2022/01/04 11:26:15 by hportife         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

char	**duarrfree(char **arr)
{
	int	i;

	if (!arr || !*arr)
		return (NULL);
	i = 0;
	while (arr[i])
	{
		if (arr[i])
			free(arr[i]);
		arr[i] = NULL;
		i++;
	}
	free(arr);
	arr = NULL;
	return (NULL);
}
