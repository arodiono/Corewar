/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_t_ind.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 19:47:55 by sprotsen          #+#    #+#             */
/*   Updated: 2017/06/20 19:47:57 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head_asm.h"

int		valid_str(char *str, int i, t_algo *lst)
{
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\t')
		{
			ft_printf(RED"");
			write(2, "ERROR: Lexical error at:\n", 25);
			ft_printf("%s\n", lst->origin);
			ft_printf("Number line with error: %d\n"RESET, lst->length);
			return (FALSE);
		}
		i++;
	}
	return (TRUE);
}

int		with_label_t_ind(t_algo *lst, char *str, t_algo *list)
{
	int				i;
	char			*label_name;
	int				from_check_label_name;
	unsigned short	a;

	i = 0;
	from_check_label_name = 0;
	label_name = NULL;
	while (find_label_chars(str[i]))
		i++;
	if (valid_str(str, i, lst) == FALSE)
		return (FALSE);
	label_name = ft_strsub(str, 0, i);
	if (check_label_name(label_name, list, i, &from_check_label_name) == FALSE)
		return (FALSE);
	lst->index_label = 1;
	a = from_check_label_name - lst->len_code_from_start;
	create_hex(2, a, lst);
	lst->len_code += 4;
	return (TRUE);
}

int		with_number_t_ind(t_algo *lst, char *str)
{
	int				i;
	unsigned short	a;

	i = 0;
	a = ft_atoi_ulli(str);
	if (str[i] == '-')
		i++;
	while (ft_isdigit(str[i]))
		i++;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\t')
		{
			ft_printf(RED"");
			write(2, "ERROR: Lexical error at:\n", 25);
			ft_printf("%s\n", lst->origin);
			ft_printf("Number line with error: %d\n"RESET, lst->length);
			return (FALSE);
		}
		i++;
	}
	create_hex(2, a, lst);
	lst->len_code += 4;
	return (TRUE);
}

int		parsing_t_ind_v2(t_algo *lst, char *str, t_algo *list)
{
	int			i;

	i = 0;
	i = pass_space_opcode_space(str, 0, 0);
	if (str[i] == LABEL_CHAR)
	{
		if (with_label_t_ind(lst, str + i + 1, list) == 0)
			return (FALSE);
	}
	else if (ft_isdigit(str[i]) || (str[i] == '-' && ft_isdigit(str[i + 1])))
	{
		if (with_number_t_ind(lst, str + i) == FALSE)
			return (FALSE);
	}
	else
		return (error_message(lst, NULL));
	return (TRUE);
}

int		parsing_t_ind(t_algo *lst, t_algo *list)
{
	char	*str;
	int		i;

	str = lst->origin;
	i = 0;
	i = pass_space_opcode_space(str, 0, 0);
	if (str[i] == LABEL_CHAR)
	{
		if (with_label_t_ind(lst, str + i + 1, list) == 0)
			return (FALSE);
	}
	else if (ft_isdigit(str[i]) || (str[i] == '-' && ft_isdigit(str[i + 1])))
	{
		if (with_number_t_ind(lst, str + i) == FALSE)
			return (FALSE);
	}
	else
		return (error_message(lst, NULL));
	return (TRUE);
}
