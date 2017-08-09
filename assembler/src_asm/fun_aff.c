/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_aff.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/17 13:11:04 by sprotsen          #+#    #+#             */
/*   Updated: 2017/06/17 13:11:06 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head_asm.h"

/*
** pass_space_opcode_space(char *str, int i, int len_opcode) - for_all_opcode.c
** add_hex_code_and_check_validation(t_algo *lst, long long a, char *str)
** - fun_add.c
*/

int		fun_aff(t_algo *list)
{
	t_algo	*lst;

	lst = list;
	while (lst)
	{
		if (lst->content_size == 4000000016)
		{
			lst->hex = ft_strdup("1040");
			lst->len_code = 4;
			if (parsing_t_reg(lst) == FALSE)
				return (FALSE);
		}
		lst = lst->next;
	}
	return (TRUE);
}
