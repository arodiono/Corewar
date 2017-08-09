/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_fork.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/18 16:07:43 by sprotsen          #+#    #+#             */
/*   Updated: 2017/06/18 16:10:23 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head_asm.h"

/*
** parsing_t_dir_2_byte(t_algo *lst, int len_opcode_name, t_algo *list)
** in - fun_t_dir_2_byte.c
*/

int		fun_fork(t_algo *list)
{
	t_algo	*lst;

	lst = list;
	while (lst)
	{
		if (lst->content_size == 4000000012)
		{
			lst->hex = ft_strdup("0c");
			lst->len_code = 2;
			if (parsing_t_dir_2_byte(lst, 4, list) == FALSE)
				return (FALSE);
		}
		lst = lst->next;
	}
	return (TRUE);
}
