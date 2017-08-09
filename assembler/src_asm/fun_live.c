/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_live.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/17 20:02:02 by sprotsen          #+#    #+#             */
/*   Updated: 2017/06/17 20:02:04 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head_asm.h"

/*
** parsing_t_dir_4_byte(t_algo *lst, int len_opcode_name, t_algo *list)
** in - fun_t_dir_4_byte.c
*/

int		fun_live(t_algo *list)
{
	t_algo	*lst;

	lst = list;
	while (lst)
	{
		if (lst->content_size == 4000000001)
		{
			lst->hex = ft_strdup("01");
			lst->len_code = 2;
			if (parsing_t_dir_4_byte(lst, 4, list) == FALSE)
				return (FALSE);
		}
		lst = lst->next;
	}
	return (TRUE);
}
