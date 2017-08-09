/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 12:48:09 by sprotsen          #+#    #+#             */
/*   Updated: 2017/06/05 12:48:10 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head_asm.h"

void	find_operations_part1(t_algo *lst, char *str)
{
	if (ft_strncmp(lst->content, "zjmp", 4) == 0 && NEXT_SYMB(str[4]))
		lst->content_size = 4000000009;
	else if (ft_strncmp(lst->content, "xor", 3) == 0 && NEXT_SYMB(str[3]))
		lst->content_size = 4000000008;
	else if (ft_strncmp(lst->content, "or", 2) == 0 && NEXT_SYMB(str[2]))
		lst->content_size = 4000000007;
	else if (ft_strncmp(lst->content, "and", 3) == 0 && NEXT_SYMB(str[3]))
		lst->content_size = 4000000006;
	else if (ft_strncmp(lst->content, "sub", 3) == 0 && NEXT_SYMB(str[3]))
		lst->content_size = 4000000005;
	else if (ft_strncmp(lst->content, "add", 3) == 0 && NEXT_SYMB(str[3]))
		lst->content_size = 4000000004;
	else if (ft_strncmp(lst->content, "st", 2) == 0 && NEXT_SYMB(str[2]))
		lst->content_size = 4000000003;
	else if (ft_strncmp(lst->content, "ld", 2) == 0 && NEXT_SYMB(str[2]))
		lst->content_size = 4000000002;
	else if (ft_strncmp(lst->content, "live", 4) == 0 && NEXT_SYMB(str[4]))
		lst->content_size = 4000000001;
}

void	find_operations(t_algo *lst)
{
	char	*str;

	while (lst)
	{
		str = (char*)lst->content;
		if (lst->content_size > 300000000)
			;
		else if (ft_strncmp(str, "aff", 3) == 0 && NEXT_SYMB(str[3]))
			lst->content_size = 4000000016;
		else if (ft_strncmp(str, "lfork", 5) == 0 && NEXT_SYMB(str[5]))
			lst->content_size = 4000000015;
		else if (ft_strncmp(str, "lldi", 4) == 0 && NEXT_SYMB(str[4]))
			lst->content_size = 4000000014;
		else if (ft_strncmp(str, "lld", 3) == 0 && NEXT_SYMB(str[3]))
			lst->content_size = 4000000013;
		else if (ft_strncmp(str, "fork", 4) == 0 && NEXT_SYMB(str[4]))
			lst->content_size = 4000000012;
		else if (ft_strncmp(str, "sti", 3) == 0 && NEXT_SYMB(str[3]))
			lst->content_size = 4000000011;
		else if (ft_strncmp(str, "ldi", 3) == 0 && NEXT_SYMB(str[3]))
			lst->content_size = 4000000010;
		else if (1)
			find_operations_part1(lst, str);
		lst = lst->next;
	}
}
