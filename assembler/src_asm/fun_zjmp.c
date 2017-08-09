/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_zjmp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/18 15:09:26 by sprotsen          #+#    #+#             */
/*   Updated: 2017/06/18 15:14:21 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head_asm.h"

/*
** parsing_t_dir_2_byte(t_algo *lst, int len_opcode_name, t_algo *list)
** in - fun_t_dir_2_byte.c
*/

int		fun_zjmp(t_algo *list)
{
	t_algo	*lst;

	lst = list;
	while (lst)
	{
		if (lst->content_size == 4000000009)
		{
			lst->hex = ft_strdup("09");
			lst->len_code = 2;
			if (parsing_t_dir_2_byte(lst, 4, list) == FALSE)
				return (FALSE);
		}
		lst = lst->next;
	}
	return (TRUE);
}
