/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_cor_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/25 15:57:01 by sprotsen          #+#    #+#             */
/*   Updated: 2017/06/25 15:57:02 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head_asm.h"

int		get_number(char c)
{
	if (c < 58)
		return (c - 48);
	else
		return (c - 97 + 10);
}

void	hex_to_dec(char *str, int fd)
{
	int		i;
	int		res;

	i = 0;
	while (str[i])
	{
		res = get_number(str[i]) * 16 + get_number(str[i + 1]);
		write(fd, &res, sizeof(char));
		i += 2;
	}
}

void	write_any_data(int fd, t_algo *lst)
{
	while (lst)
	{
		if (lst->content_size > 4000000000)
		{
			hex_to_dec(lst->hex, fd);
		}
		lst = lst->next;
	}
}

void	create_cor_file(t_algo *lst, char *str)
{
	int		fd;
	int		len_name;
	char	*name;

	len_name = ft_strlen(str);
	str[len_name - 1] = '\0';
	str[len_name - 2] = '\0';
	name = ft_strjoin(str, ".cor");
	ft_printf(GREEN"Output file: %s\n"RESET, name);
	fd = open(name, O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR);
	ft_strdel(&name);
	write_header(fd, lst);
	write_any_data(fd, lst);
	close(fd);
}
