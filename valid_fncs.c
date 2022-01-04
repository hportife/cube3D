/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_fncs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hportife <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 11:37:06 by hportife          #+#    #+#             */
/*   Updated: 2022/01/04 11:37:08 by hportife         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int valid_src_file(char *file_name, int *file_fd)
{
    if (!(ft_strchr(file_name, '.')))
        return (1);
    if (is_valid_name(file_name))
        return (1);
    *file_fd = open(file_name, O_RDONLY);
    if (*file_fd == -1)
        return (1);
	return (0);
}
