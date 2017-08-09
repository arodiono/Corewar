/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_cor_file_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/01 17:04:44 by sprotsen          #+#    #+#             */
/*   Updated: 2017/07/01 17:04:45 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head_asm.h"

unsigned int	reverse_bits(unsigned int val)
{
	unsigned int result;

	result = (val & 4278190080) >> 24;
	result += (val & 16711680) >> 8;
	result += (val & 65280) << 8;
	result += (val & 255) << 24;
	return (result);
}

void			comment_for_header(t_algo *lst, t_header *head)
{
	int		i;
	char	*str;

	str = head->comment;
	i = -1;
	while (++i <= COMMENT_LENGTH + 1)
		str[i] = 0;
	while (lst)
	{
		if (lst->content_size == 3000000002)
		{
			ft_strcpy(head->comment, lst->hex);
			return ;
		}
		lst = lst->next;
	}
}

void			name_for_header(t_algo *lst, t_header *head)
{
	int		i;
	char	*str;

	str = head->prog_name;
	i = -1;
	while (++i <= PROG_NAME_LENGTH + 1)
		str[i] = 0;
	while (lst)
	{
		if (lst->content_size == 3000000001)
		{
			ft_strcpy(head->prog_name, lst->hex);
			return ;
		}
		lst = lst->next;
	}
}

int				calculate_prog_size(t_algo *lst)
{
	unsigned int	result;

	result = 0;
	while (lst)
	{
		if (lst->content_size > 4000000000)
			result += lst->len_code / 2;
		lst = lst->next;
	}
	return (result);
}

void			write_header(int fd, t_algo *lst)
{
	t_header	head;

	head.magic = reverse_bits(COREWAR_EXEC_MAGIC);
	name_for_header(lst, &head);
	head.prog_size = reverse_bits(calculate_prog_size(lst));
	comment_for_header(lst, &head);
	write(fd, &head.magic, sizeof(unsigned int));
	write(fd, &head.prog_name, (sizeof(char) * (PROG_NAME_LENGTH + 4)));
	write(fd, &head.prog_size, (sizeof(unsigned int)));
	write(fd, &head.comment, (sizeof(char) * (COMMENT_LENGTH + 4)));
}
