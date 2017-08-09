/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_space.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/01 13:46:27 by sprotsen          #+#    #+#             */
/*   Updated: 2017/07/01 13:46:28 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head_asm.h"

void	find_element_less_32(char *str)
{
	int		i;

	i = -1;
	while (str[++i])
	{
		if (str[i] < 32)
			str[i] = ' ';
	}
}

void	delete_space(t_algo *lst)
{
	int		i;
	char	*str;
	char	*copy;

	while (lst)
	{
		find_element_less_32(lst->content);
		str = lst->content;
		i = pass_space_opcode_space(str, 0, 0);
		copy = ft_strdup(str + i);
		ft_strdel(&(lst)->content);
		lst->content = copy;
		if (copy[0] == COMMENT_CHAR)
			lst->content_size = 3000000000;
		lst = lst->next;
	}
}
