/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_label.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/01 13:54:57 by sprotsen          #+#    #+#             */
/*   Updated: 2017/07/01 13:54:59 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head_asm.h"

int		find_label_chars(char s)
{
	int		i;

	i = -1;
	while (LABEL_CHARS[++i])
		if (s == LABEL_CHARS[i])
			return (1);
	return (0);
}

void	find_label(t_algo *list)
{
	t_algo	*lst;
	char	*str;
	int		i;
	int		len;

	lst = list;
	while (lst)
	{
		str = (char*)lst->content;
		i = 0;
		while (find_label_chars(str[i]))
			i++;
		if (str[i] == LABEL_CHAR)
		{
			lst->content_size = 4000000000;
			if ((len = ft_strlen(str + i + 1)) > 0)
			{
				add_algo_center(&lst,
					create_list_algo_new(str, i, lst->length, lst->origin));
				ft_strclr(str + i + 1);
			}
		}
		lst = lst->next;
	}
}
