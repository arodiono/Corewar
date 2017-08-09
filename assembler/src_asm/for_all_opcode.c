/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_all_opcode.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 20:39:19 by sprotsen          #+#    #+#             */
/*   Updated: 2017/06/13 20:39:21 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head_asm.h"

int		pass_space_opcode_space(char *str, int i, int len_opcode)
{
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	i += len_opcode;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	return (i);
}

int		find_len_number(long long a)
{
	int		count;

	count = 0;
	if (a < 10)
		return (1);
	while (a > 9)
	{
		a = a / 10;
		count++;
	}
	return (count + 1);
}

void	hex_code(long long a, int i, char *row)
{
	int		num;
	int		n;

	i--;
	num = a / 16;
	n = a % 16;
	if (num > 0)
		hex_code(num, i, row);
	if (n > 9)
		row[i] = (97 + n - 10);
	else
		row[i] = (n + '0');
}

void	create_hex(int n_byte, long long a, t_algo *lst)
{
	char	str[n_byte * 2 + 1];
	char	*ptr;
	int		i;

	i = -1;
	while (++i < n_byte * 2)
		str[i] = '0';
	str[i] = '\0';
	hex_code(a, n_byte * 2, str);
	ptr = lst->hex;
	lst->hex = ft_strjoin(ptr, str);
	ft_strdel(&ptr);
}

int		check_label_name(char *str, t_algo *lst, int len_label, int *index)
{
	while (lst)
	{
		if (lst->content_size == 4000000000)
			if (ft_strncmp(str, lst->content, len_label) == 0)
			{
				ft_strdel(&str);
				*index = lst->len_code_from_start;
				return (TRUE);
			}
		lst = lst->next;
	}
	ft_printf(RED"");
	write(2, "ERROR: label name did't found\n", 30);
	ft_printf("label name: %s\n"RESET, str);
	ft_strdel(&str);
	return (FALSE);
}
