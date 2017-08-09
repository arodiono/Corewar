/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_lldi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/25 13:55:14 by sprotsen          #+#    #+#             */
/*   Updated: 2017/06/25 13:55:15 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head_asm.h"

int		error_lldi(t_algo *lst, char **mass)
{
	ft_printf(RED"");
	write(2, "ERROR: incorrect input format:\n", 31);
	ft_printf("%s\n", lst->origin);
	ft_printf("Number line with error: %d\n"RESET, lst->length);
	ft_strdel_char_mass(mass);
	return (FALSE);
}

int		parsing_and_block_lldi(t_algo *lst, char **mass, t_algo *list)
{
	if (ft_strncmp(lst->hex + 2, "54", 2) == 0)
		return (FUN_0X54(lst, mass, list));
	else if (ft_strncmp(lst->hex + 2, "94", 2) == 0)
		return (FUN_0X94_2(lst, mass, list));
	else if (ft_strncmp(lst->hex + 2, "d4", 2) == 0)
		return (FUN_0XD4(lst, mass, list));
	else if (ft_strncmp(lst->hex + 2, "64", 2) == 0)
		return (FUN_0X64_2(lst, mass, list));
	else if (ft_strncmp(lst->hex + 2, "a4", 2) == 0)
		return (FUN_0XA4_2(lst, mass, list));
	else if (ft_strncmp(lst->hex + 2, "e4", 2) == 0)
		return (FUN_0XE4_2(lst, mass, list));
	error_lldi(lst, mass);
	return (FALSE);
}

int		parsing_lldi(t_algo *lst, t_algo *list, int n, int len_name)
{
	char	*str;
	char	**mass;
	int		i;

	str = lst->origin;
	i = pass_space_opcode_space(str, 0, len_name);
	mass = ft_strsplit(str + i, SEPARATOR_CHAR);
	if (type_search(mass, lst, n) == FALSE)
	{
		ft_strdel_char_mass(mass);
		return (FALSE);
	}
	if (parsing_and_block_lldi(lst, mass, list) == TRUE)
		return (TRUE);
	else
		return (FALSE);
	return (TRUE);
}

int		fun_lldi(t_algo *list)
{
	t_algo	*lst;

	lst = list;
	while (lst)
	{
		if (lst->content_size == 4000000014)
		{
			lst->hex = ft_strdup("0e");
			lst->len_code = 2;
			if (parsing_lldi(lst, list, 3, 4) == FALSE)
				return (FALSE);
		}
		lst = lst->next;
	}
	return (TRUE);
}
