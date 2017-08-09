/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_backslash_n.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/01 13:56:22 by sprotsen          #+#    #+#             */
/*   Updated: 2017/07/01 13:56:24 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head_asm.h"

int		find_backslash_n(t_algo *lst, int fd)
{
	char	qwe;

	while (lst->next)
		lst = lst->next;
	if (lst->content_size >= 4000000000)
	{
		lseek(fd, -1, SEEK_END);
		read(fd, &qwe, 1);
		if (qwe != 10)
		{
			write(2, "ERROR: line without backslash n\n", 32);
			return (FALSE);
		}
	}
	return (TRUE);
}
