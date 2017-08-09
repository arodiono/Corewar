/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_and.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/25 12:36:34 by sprotsen          #+#    #+#             */
/*   Updated: 2017/06/25 12:36:35 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head_asm.h"

int		error_and(t_algo *lst, char **mass)
{
	ft_printf(RED"");
	write(2, "ERROR: incorrect input format:\n", 31);
	ft_printf(RED"%s\n"RESET, lst->origin);
	ft_printf("Number line with error: %d\n"RESET, lst->length);
	ft_strdel_char_mass(mass);
	return (FALSE);
}

int		parsing_and_block(t_algo *lst, char **mass, t_algo *list)
{
	if (ft_strncmp(lst->hex + 2, "54", 2) == 0)
		return (FUN_0X54(lst, mass, list));
	else if (ft_strncmp(lst->hex + 2, "94", 2) == 0)
		return (FUN_0X94(lst, mass, list));
	else if (ft_strncmp(lst->hex + 2, "d4", 2) == 0)
		return (FUN_0XD4(lst, mass, list));
	else if (ft_strncmp(lst->hex + 2, "74", 2) == 0)
		return (FUN_0X74(lst, mass, list));
	else if (ft_strncmp(lst->hex + 2, "b4", 2) == 0)
		return (FUN_0XB4(lst, mass, list));
	else if (ft_strncmp(lst->hex + 2, "f4", 2) == 0)
		return (FUN_0XF4(lst, mass, list));
	else if (ft_strncmp(lst->hex + 2, "64", 2) == 0)
		return (FUN_0X64(lst, mass, list));
	else if (ft_strncmp(lst->hex + 2, "a4", 2) == 0)
		return (FUN_0XA4(lst, mass, list));
	else if (ft_strncmp(lst->hex + 2, "e4", 2) == 0)
		return (FUN_0XE4(lst, mass, list));
	error_and(lst, mass);
	return (FALSE);
}

int		parsing_and(t_algo *lst, t_algo *list, int n, int len_name)
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
	if (parsing_and_block(lst, mass, list) == TRUE)
		return (TRUE);
	else
		return (FALSE);
	return (TRUE);
}

int		fun_and(t_algo *list)
{
	t_algo	*lst;

	lst = list;
	while (lst)
	{
		if (lst->content_size == 4000000006)
		{
			lst->hex = ft_strdup("06");
			lst->len_code = 2;
			if (parsing_and(lst, list, 3, 3) == FALSE)
				return (FALSE);
		}
		lst = lst->next;
	}
	return (TRUE);
}
