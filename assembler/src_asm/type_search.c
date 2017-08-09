/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_search.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 20:52:53 by sprotsen          #+#    #+#             */
/*   Updated: 2017/06/20 20:52:55 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head_asm.h"

int		power(int a, int n)
{
	int		i;
	int		result;

	i = -1;
	result = 1;
	while (++i < n)
		result = result * a;
	return (result);
}

int		recode(char *str)
{
	int		i;
	int		result;

	result = 0;
	i = -1;
	while (++i < 8)
	{
		if (str[i] == 49)
			result = result + power(2, 7 - i);
	}
	return (result);
}

int		type_search_next(char *str, int k, int i, char *res)
{
	if (str[k] == DIRECT_CHAR)
	{
		res[i * 2] = '1';
		res[i * 2 + 1] = '0';
	}
	else if (str[k] == 'r' && ft_isdigit(str[k + 1]) && str[k + 1] != '0')
	{
		res[i * 2] = '0';
		res[i * 2 + 1] = '1';
	}
	else if (str[k] == LABEL_CHAR || ft_isdigit(str[k]) || ((str[k] == '-'
		&& ft_isdigit(str[k + 1]))))
	{
		res[i * 2] = '1';
		res[i * 2 + 1] = '1';
	}
	else
		return (FALSE);
	return (TRUE);
}

int		error(t_algo *lst, int n_param)
{
	ft_printf(RED"");
	write(2, "ERROR: too many input parameters\n", 33);
	ft_printf("The command accepts %d parameters\n", n_param);
	ft_printf("Number line with error: %d\n"RESET, lst->length);
	return (FALSE);
}

int		type_search(char **mass, t_algo *lst, int n_param)
{
	int		i;
	int		k;
	char	*str;
	char	res[9];

	i = -1;
	while (++i < 8)
		res[i] = '0';
	res[i] = '\0';
	i = -1;
	while (mass[++i])
	{
		if (i > n_param - 1)
			return (error(lst, n_param));
		str = mass[i];
		k = pass_space_opcode_space(str, 0, 0);
		if (type_search_next(str, k, i, res))
			;
		else
			return (error_message(lst, NULL));
	}
	create_hex(1, recode(res), lst);
	lst->len_code += 2;
	return (TRUE);
}
