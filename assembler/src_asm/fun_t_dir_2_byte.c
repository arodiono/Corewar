/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_t_dir_2_byte.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/18 17:56:52 by sprotsen          #+#    #+#             */
/*   Updated: 2017/06/18 18:54:24 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head_asm.h"

/*
** check_label_name(char *str, t_algo *lst, int len_label, int *index)
** in - fun_live.c
** create_hex(int n_byte, long long a, t_algo *lst)
** in for_all_opcode.c
*/

int		with_label_t_dir_2_byte(t_algo *lst, char *str, t_algo *list)
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
	if (ft_strlen(label_name) == 0)
	{
		ft_strdel(&label_name);
		return (error_message(lst, NULL));
	}
	if (check_label_name(label_name, list, i, &from_check_label_name) == FALSE)
		return (FALSE);
	lst->index_label = 1;
	a = from_check_label_name - lst->len_code_from_start;
	create_hex(2, a, lst);
	lst->len_code += 4;
	return (TRUE);
}

int		with_number_t_dir_2_byte(t_algo *lst, char *str)
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

int		parsing_t_dir_2_byte_v2(t_algo *lst, char *str, t_algo *list)
{
	int		i;

	i = 0;
	i = pass_space_opcode_space(str, 0, 0);
	if (str[i] == DIRECT_CHAR && str[i + 1] == LABEL_CHAR)
	{
		if (with_label_t_dir_2_byte(lst, str + i + 2, list) == 0)
			return (FALSE);
	}
	else if (str[i] == DC && (ft_isdigit(str[i + 1]) || str[i + 1] == '-'))
	{
		if (with_number_t_dir_2_byte(lst, str + i + 1) == FALSE)
			return (FALSE);
	}
	else
		return (error_message(lst, NULL));
	return (TRUE);
}

int		parsing_t_dir_2_byte(t_algo *lst, int len_opcode_name, t_algo *list)
{
	char		*str;
	int			i;

	str = lst->origin;
	i = 0;
	i = pass_space_opcode_space(str, 0, len_opcode_name);
	if (str[i] == DIRECT_CHAR && str[i + 1] == LABEL_CHAR)
	{
		if (with_label_t_dir_2_byte(lst, str + i + 2, list) == 0)
			return (FALSE);
	}
	else if (str[i] == DC && (ft_isdigit(str[i + 1]) || str[i + 1] == '-'))
	{
		if (with_number_t_dir_2_byte(lst, str + i + 1) == FALSE)
			return (FALSE);
	}
	else
		return (error_message(lst, NULL));
	return (TRUE);
}
