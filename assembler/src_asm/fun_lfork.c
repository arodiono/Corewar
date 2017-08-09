/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_lfork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/18 17:40:46 by sprotsen          #+#    #+#             */
/*   Updated: 2017/06/18 17:40:47 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head_asm.h"

/*
** parsing_t_dir_2_byte(t_algo *lst, int len_opcode_name, t_algo *list)
** in - fun_t_dir_2_byte.c
*/

int		fun_lfork(t_algo *list)
{
	t_algo	*lst;

	lst = list;
	while (lst)
	{
		if (lst->content_size == 4000000015)
		{
			lst->hex = ft_strdup("0f");
			lst->len_code = 2;
			if (parsing_t_dir_2_byte(lst, 5, list) == FALSE)
				return (FALSE);
		}
		lst = lst->next;
	}
	return (TRUE);
}
