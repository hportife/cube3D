/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttranche <ttranche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 19:41:24 by ttranche          #+#    #+#             */
/*   Updated: 2021/03/24 13:21:09 by ttranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

void	puterr(char *string)
{
	write(1, string, stringlen(string));
}

void	handle_error(t_gen *gen, char *error, char *trace)
{
	int mid;

	mid = (57 - stringlen(error)) / 2;
	puterr("Error\n");
	puterr("\x1B[31m -----------------------[ \x1B[33mERROR\x1B[31m ]--------"
		"--------------- \n\n\x1B[33m");
	while (mid-- > 0)
		puterr(" ");
	puterr(error);
	if (trace)
	{
		puterr("\n\x1B[36m");
		mid = (57 - stringlen(trace) - 2) / 2;
		while (mid-- > 0)
			puterr(" ");
		puterr("'");
		puterr(trace);
		puterr("'");
	}
	puterr("\n\n\x1B[31m ---------------------------"
		"---------------------------- \n");
//	clean_all(gen);
	exit(0);
}
