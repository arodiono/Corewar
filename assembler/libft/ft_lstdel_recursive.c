/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel_recursive.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/08 14:34:56 by sprotsen          #+#    #+#             */
/*   Updated: 2017/04/08 14:37:12 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel_recursive(t_list **list)
{
	if (*list)
	{
		ft_lstdel_recursive(&(*list)->next);
		free((*list)->content);
		free(*list);
		(*list)->content = NULL;
		(*list) = NULL;
	}
}
