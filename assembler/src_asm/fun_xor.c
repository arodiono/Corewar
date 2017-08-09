/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_xor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/25 13:39:58 by sprotsen          #+#    #+#             */
/*   Updated: 2017/06/25 13:40:00 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head_asm.h"

int		fun_xor(t_algo *list)
{
	t_algo	*lst;

	lst = list;
	while (lst)
	{
		if (lst->content_size == 4000000008)
		{
			lst->hex = ft_strdup("08");
			lst->len_code = 2;
			if (parsing_and(lst, list, 3, 3) == FALSE)
				return (FALSE);
		}
		lst = lst->next;
	}
	return (TRUE);
}
