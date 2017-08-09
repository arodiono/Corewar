/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_or.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/25 13:39:43 by sprotsen          #+#    #+#             */
/*   Updated: 2017/06/25 13:39:44 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head_asm.h"

int		fun_or(t_algo *list)
{
	t_algo	*lst;

	lst = list;
	while (lst)
	{
		if (lst->content_size == 4000000007)
		{
			lst->hex = ft_strdup("07");
			lst->len_code = 2;
			if (parsing_and(lst, list, 3, 2) == FALSE)
				return (FALSE);
		}
		lst = lst->next;
	}
	return (TRUE);
}
