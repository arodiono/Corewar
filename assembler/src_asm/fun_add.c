/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_add.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 20:29:38 by sprotsen          #+#    #+#             */
/*   Updated: 2017/06/13 20:29:40 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head_asm.h"

/*
** find_len_number(long long a) - for_all_opcode.c
** create_hex(int n_byte, long long a, t_algo *lst) - for_all_opcode.c
*/

int		error_red(t_algo *lst)
{
	ft_printf(RED"");
	write(2, "ERROR: r1 <-> rx with x = REG_NUMBER and x < 256\n", 50);
	ft_printf("%s\n", lst->origin);
	ft_printf("Number line with error: %d\n"RESET, lst->length);
	return (FALSE);
}

int		add_hex_code_and_check_validation(t_algo *lst, long long a, char *str)
{
	int		len;
	int		i;

	len = 0;
	i = -1;
	len = find_len_number(a);
	if (a < 1 || a > REG_NUMBER || a > 256 || len > 3)
		return (error_red(lst));
	while (str[len + ++i])
	{
		if (str[len + i] != ' ' && str[len + i] != '\t')
		{
			ft_printf(RED"");
			write(2, "ERROR: Lexical error at:\n", 25);
			ft_printf("%s\n", lst->origin);
			ft_printf("Number line with error: %d\n"RESET, lst->length);
			return (FALSE);
		}
	}
	create_hex(1, a, lst);
	lst->len_code = ft_strlen(lst->hex);
	return (TRUE);
}

int		parsing_add(t_algo *lst, int i, int k, long long a)
{
	char	*str;
	char	**mass;

	str = lst->origin;
	i = pass_space_opcode_space(str, 0, 3);
	mass = ft_strsplit(str + i, SEPARATOR_CHAR);
	i = -1;
	lst->hex = ft_strdup("0454");
	while (mass[++i])
	{
		str = mass[i];
		k = pass_space_opcode_space(str, 0, 0);
		if (str[k] == 'r' && ft_isdigit(str[k + 1]) && str[k + 1] != '0')
		{
			a = ft_atoi_ulli(str + k + 1);
			if (add_hex_code_and_check_validation(lst, a, str + k + 1) == FALSE)
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

int		fun_add(t_algo *list)
{
	t_algo	*lst;

	lst = list;
	while (lst)
	{
		if (lst->content_size == 4000000004)
		{
			if (parsing_add(lst, 0, 0, 0) == FALSE)
				return (FALSE);
		}
		lst = lst->next;
	}
	return (TRUE);
}
