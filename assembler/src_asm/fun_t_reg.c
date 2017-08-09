/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_t_reg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 20:17:08 by sprotsen          #+#    #+#             */
/*   Updated: 2017/06/19 20:17:10 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head_asm.h"

int		add_hex_code_t_reg(t_algo *lst, long long a, char *str)
{
	int		len;
	int		i;

	len = 0;
	i = -1;
	len = find_len_number(a);
	if (a < 1 || a > REG_NUMBER || a >= 256 || len > 3)
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
	lst->len_code += 2;
	return (TRUE);
}

int		parsing_t_reg_v2(t_algo *lst, char *str)
{
	long long	a;
	int			i;

	i = pass_space_opcode_space(str, 0, 0);
	if (str[i] == 'r' && ft_isdigit(str[i + 1]) && str[i + 1] != '0')
	{
		a = ft_atoi_ulli(str + i + 1);
		if (add_hex_code_t_reg(lst, a, str + i + 1) == FALSE)
			return (FALSE);
	}
	else
		return (error_message(lst, NULL));
	return (TRUE);
}

int		parsing_t_reg(t_algo *lst)
{
	char		*str;
	long long	a;
	int			i;

	str = lst->origin;
	i = pass_space_opcode_space(str, 0, 3);
	if (str[i] == 'r' && ft_isdigit(str[i + 1]) && str[i + 1] != '0')
	{
		a = ft_atoi_ulli(str + i + 1);
		if (add_hex_code_t_reg(lst, a, str + i + 1) == FALSE)
			return (FALSE);
	}
	else
		return (error_message(lst, NULL));
	return (TRUE);
}
