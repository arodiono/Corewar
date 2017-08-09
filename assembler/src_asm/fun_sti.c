/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_sti.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/25 14:59:55 by sprotsen          #+#    #+#             */
/*   Updated: 2017/06/25 14:59:59 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head_asm.h"

int		error_sti(t_algo *lst, char **mass)
{
	ft_printf(RED"");
	write(2, "ERROR: incorrect input format:\n", 31);
	ft_printf("%s\n", lst->origin);
	ft_printf("Number line with error: %d\n"RESET, lst->length);
	ft_strdel_char_mass(mass);
	return (FALSE);
}

int		parsing_and_block_sti(t_algo *lst, char **mass, t_algo *list)
{
	if (ft_strncmp(lst->hex + 2, "54", 2) == 0)
		return (FUN_0X54(lst, mass, list));
	else if (ft_strncmp(lst->hex + 2, "64", 2) == 0)
		return (FUN_0X64_2(lst, mass, list));
	else if (ft_strncmp(lst->hex + 2, "74", 2) == 0)
		return (FUN_0X74(lst, mass, list));
	else if (ft_strncmp(lst->hex + 2, "58", 2) == 0)
		return (FUN_0X58_2(lst, mass, list));
	else if (ft_strncmp(lst->hex + 2, "68", 2) == 0)
		return (FUN_0X68_2(lst, mass, list));
	else if (ft_strncmp(lst->hex + 2, "78", 2) == 0)
		return (FUN_0X78_2(lst, mass, list));
	error_sti(lst, mass);
	return (FALSE);
}

int		parsing_sti(t_algo *lst, t_algo *list, int n, int len_name)
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
	if (parsing_and_block_sti(lst, mass, list) == TRUE)
		return (TRUE);
	else
		return (FALSE);
	return (TRUE);
}

int		fun_sti(t_algo *list)
{
	t_algo	*lst;

	lst = list;
	while (lst)
	{
		if (lst->content_size == 4000000011)
		{
			lst->hex = ft_strdup("0b");
			lst->len_code = 2;
			if (parsing_sti(lst, list, 3, 3) == FALSE)
				return (FALSE);
		}
		lst = lst->next;
	}
	return (TRUE);
}
