/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_sub.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/17 12:45:26 by sprotsen          #+#    #+#             */
/*   Updated: 2017/06/17 12:45:28 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head_asm.h"

/*
** pass_space_opcode_space(char *str, int i, int len_opcode) - for_all_opcode.c
** error_message(t_algo *lst) - fun_add.c
*/

int		parsing_sub(t_algo *lst, int i, int k, long long a)
{
	char	*str;
	char	**mass;

	str = lst->origin;
	i = pass_space_opcode_space(str, 0, 3);
	mass = ft_strsplit(str + i, SEPARATOR_CHAR);
	i = -1;
	lst->hex = ft_strdup("0554");
	while (mass[++i])
	{
		str = mass[i];
		k = pass_space_opcode_space(str, 0, 0);
		if (str[k] == 'r' && ft_isdigit(str[k + 1]) && str[k + 1] != '0')
		{
			a = ft_atoi_ulli(str + k + 1);
			if (add_hex_code_and_check_validation(lst, a, str + k + 1) == 0)
				return (ft_strdel_char_mass_false(mass));
		}
		else
			return (error_message(lst, mass));
	}
	if (i != 3)
		return (error_message(lst, mass));
	ft_strdel_char_mass(mass);
	return (TRUE);
}

int		fun_sub(t_algo *list)
{
	t_algo	*lst;

	lst = list;
	while (lst)
	{
		if (lst->content_size == 4000000005)
		{
			if (parsing_sub(lst, 0, 0, 0) == FALSE)
				return (FALSE);
		}
		lst = lst->next;
	}
	return (TRUE);
}
