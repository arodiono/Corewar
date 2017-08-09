/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_pieces_of_comment_in_line.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/01 13:57:58 by sprotsen          #+#    #+#             */
/*   Updated: 2017/07/01 13:58:00 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head_asm.h"

void	clear_pieces_of_comment_in_line(t_algo *lst)
{
	while (lst)
	{
		if (ft_strchr(lst->origin, COMMENT_CHAR))
		{
			ft_strclr(ft_strchr(lst->origin, COMMENT_CHAR));
			ft_strclr(ft_strchr(lst->content, COMMENT_CHAR));
		}
		lst = lst->next;
	}
}
