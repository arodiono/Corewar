/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_lld.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/24 19:26:23 by sprotsen          #+#    #+#             */
/*   Updated: 2017/06/24 19:26:25 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head_asm.h"

int		fun_lld(t_algo *list)
{
	t_algo	*lst;

	lst = list;
	while (lst)
	{
		if (lst->content_size == 4000000013)
		{
			lst->hex = ft_strdup("0d");
			lst->len_code = 2;
			if (parsing_ld(lst, list, 3) == FALSE)
				return (FALSE);
		}
		lst = lst->next;
	}
	return (TRUE);
}
