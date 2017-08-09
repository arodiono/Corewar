/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_ldi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/25 14:14:44 by sprotsen          #+#    #+#             */
/*   Updated: 2017/06/25 14:14:46 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head_asm.h"

int		fun_ldi(t_algo *list)
{
	t_algo	*lst;

	lst = list;
	while (lst)
	{
		if (lst->content_size == 4000000010)
		{
			lst->hex = ft_strdup("0a");
			lst->len_code = 2;
			if (parsing_lldi(lst, list, 3, 3) == FALSE)
				return (FALSE);
		}
		lst = lst->next;
	}
	return (TRUE);
}
