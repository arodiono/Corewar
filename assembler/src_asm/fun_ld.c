/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_ld.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 20:13:15 by sprotsen          #+#    #+#             */
/*   Updated: 2017/06/20 20:13:17 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head_asm.h"

int		error_input(t_algo *lst)
{
	ft_printf(RED"");
	write(2, "ERROR: incorrect input format:\n", 31);
	ft_printf("%s\n", lst->origin);
	ft_printf("Number line with error: %d\n"RESET, lst->length);
	return (FALSE);
}

/*
** variant1 - T_IND, T_REG
*/

int		variant1(t_algo *lst, char **mass, t_algo *list)
{
	if (parsing_t_ind_v2(lst, mass[0], list) == FALSE)
	{
		ft_strdel_char_mass(mass);
		return (FALSE);
	}
	if (parsing_t_reg_v2(lst, mass[1]) == FALSE)
	{
		ft_strdel_char_mass(mass);
		return (FALSE);
	}
	ft_strdel_char_mass(mass);
	return (TRUE);
}

/*
** variant2 - T_DIR, T_REG
*/

int		variant2(t_algo *lst, char **mass, t_algo *list)
{
	if (parsing_t_dir_4_byte_v2(lst, mass[0], list) == FALSE)
	{
		ft_strdel_char_mass(mass);
		return (FALSE);
	}
	if (parsing_t_reg_v2(lst, mass[1]) == FALSE)
	{
		ft_strdel_char_mass(mass);
		return (FALSE);
	}
	ft_strdel_char_mass(mass);
	return (TRUE);
}

int		parsing_ld(t_algo *lst, t_algo *list, int n)
{
	char	*str;
	char	**mass;
	int		i;

	str = lst->origin;
	i = pass_space_opcode_space(str, 0, n);
	mass = ft_strsplit(str + i, SEPARATOR_CHAR);
	if (type_search(mass, lst, n) == FALSE)
	{
		ft_strdel_char_mass(mass);
		return (FALSE);
	}
	if (ft_strncmp(lst->hex + 2, "90", 2) == 0)
		return (variant2(lst, mass, list));
	else if (ft_strncmp(lst->hex + 2, "d0", 2) == 0)
		return (variant1(lst, mass, list));
	else
	{
		ft_strdel_char_mass(mass);
		return (error_input(lst));
	}
	return (TRUE);
}

int		fun_ld(t_algo *list)
{
	t_algo	*lst;

	lst = list;
	while (lst)
	{
		if (lst->content_size == 4000000002)
		{
			lst->hex = ft_strdup("02");
			lst->len_code = 2;
			if (parsing_ld(lst, list, 2) == FALSE)
				return (FALSE);
		}
		lst = lst->next;
	}
	return (TRUE);
}
