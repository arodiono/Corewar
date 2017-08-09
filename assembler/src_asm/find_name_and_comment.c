/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_name_and_comment.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/01 13:04:25 by sprotsen          #+#    #+#             */
/*   Updated: 2017/07/01 13:04:27 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head_asm.h"

void	find_name_part(t_algo *lst, int *count_n, int *flag_error)
{
	lst->content_size = 3000000001;
	*count_n += 1;
	if (*count_n > 1)
	{
		*flag_error = -1;
		ft_printf(RED"");
		write(2, "ERROR: several name_cmd_string\n", 31);
		ft_printf("line number with duplicate: %d\n"RESET, lst->length);
	}
}

void	find_comm_part(t_algo *lst, int *c_com, int *flag_error)
{
	lst->content_size = 3000000002;
	*c_com += 1;
	if (*c_com > 1)
	{
		*flag_error = -1;
		ft_printf(RED"");
		write(2, "ERROR: several comment_cmd_string\n", 34);
		ft_printf("line number with duplicate: %d\n"RESET, lst->length);
	}
}

int		find_name_and_comment(t_algo *list, int count_n, int c_com)
{
	t_algo	*lst;
	size_t	len[2];
	int		flag_error;

	len[0] = ft_strlen(NAME_CMD_STRING);
	len[1] = ft_strlen(COMMENT_CMD_STRING);
	lst = list;
	flag_error = 1;
	while (lst)
	{
		if (ft_strncmp(lst->content, NAME_CMD_STRING, len[0]) == 0)
			find_name_part(lst, &count_n, &flag_error);
		if (ft_strncmp(lst->content, COMMENT_CMD_STRING, len[1]) == 0)
			find_comm_part(lst, &c_com, &flag_error);
		lst = lst->next;
	}
	ft_printf(RED"");
	if (count_n < 1)
		return (write(2, "ERROR: NAME_CMD_STRING didn't found\n", 36));
	if (c_com < 1)
		return (write(2, "ERROR: COMMENT_CMD_STRING didn't found\n", 39));
	ft_printf(""RESET);
	return (flag_error);
}
