/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_st.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/24 19:40:50 by sprotsen          #+#    #+#             */
/*   Updated: 2017/06/24 19:44:13 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head_asm.h"

/*
** variant1 - T_REG, T_REG
*/

int		variant1_st(t_algo *lst, char **mass, t_algo *list)
{
	(void)list;
	if (parsing_t_reg_v2(lst, mass[0]) == FALSE)
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
** variant2 - T_REG, T_IND
*/

int		variant2_st(t_algo *lst, char **mass, t_algo *list)
{
	if (parsing_t_reg_v2(lst, mass[0]) == FALSE)
	{
		ft_strdel_char_mass(mass);
		return (FALSE);
	}
	if (parsing_t_ind_v2(lst, mass[1], list) == FALSE)
	{
		ft_strdel_char_mass(mass);
		return (FALSE);
	}
	ft_strdel_char_mass(mass);
	return (TRUE);
}

int		parsing_st(t_algo *lst, t_algo *list, int n)
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
	if (ft_strncmp(lst->hex + 2, "50", 2) == 0)
		return (variant1_st(lst, mass, list));
	else if (ft_strncmp(lst->hex + 2, "70", 2) == 0)
		return (variant2_st(lst, mass, list));
	else
	{
		ft_strdel_char_mass(mass);
		return (error_input(lst));
	}
	return (TRUE);
}

int		fun_st(t_algo *list)
{
	t_algo	*lst;

	lst = list;
	while (lst)
	{
		if (lst->content_size == 4000000003)
		{
			lst->hex = ft_strdup("03");
			lst->len_code = 2;
			if (parsing_st(lst, list, 2) == FALSE)
				return (FALSE);
		}
		lst = lst->next;
	}
	return (TRUE);
}
