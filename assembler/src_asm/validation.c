/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/01 13:43:04 by sprotsen          #+#    #+#             */
/*   Updated: 2017/07/01 13:43:06 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head_asm.h"

int		validation(t_list *list, char *str, int fd)
{
	t_algo	*row;

	row = giving_len_for_each_list(list);
	delete_space(row);
	find_label(row);
	delete_space(row);
	if (find_name_and_comment(row, 0, 0) != 1)
		return (del_list_algo_false(&row));
	find_operations(row);
	if (review_list_valid(row, 0, 0))
		return (del_list_algo_false(&row));
	if (!find_backslash_n(row, fd))
		return (del_list_algo_false(&row));
	clear_pieces_of_comment_in_line(row);
	if (next_validation(row))
		create_cor_file(row, str);
	del_list_algo(&row);
	return (TRUE);
}
