/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/04 13:27:02 by sprotsen          #+#    #+#             */
/*   Updated: 2017/06/04 18:17:10 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head_asm.h"

int		review_list_valid(t_algo *list, int i, int flag)
{
	char	*str;
	t_algo	*lst;

	str = NULL;
	lst = list;
	while (lst)
	{
		if (lst->content_size < 3000000000)
		{
			str = lst->content;
			i = -1;
			while (str[++i])
				if (str[i] > 32)
				{
					ft_printf(RED"");
					write(2, "ERROR: incorrect data due to:\n", 30);
					ft_printf("%s\n", lst->origin);
					ft_printf("Number line with error: %d\n"RESET, lst->length);
					flag = -1;
					break ;
				}
		}
		lst = lst->next;
	}
	return (flag);
}

t_algo	*giving_len_for_each_list(t_list *lst)
{
	int		i;
	t_algo	*new;

	i = 1;
	new = NULL;
	while (lst)
	{
		add_algo(&new, create_list_algo(lst->content, i));
		i++;
		lst = lst->next;
	}
	return (new);
}

void	*read_from_file(char *argv, int fd, size_t len, int k)
{
	char	*line;
	t_list	*list;

	line = NULL;
	list = NULL;
	if (argv[len - 2] != '.' && argv[len - 1] != 's')
	{
		write(2, "ERROR: file format is not available. ", 37);
		write(2, "Use file with format '.s'\n", 26);
		return (NULL);
	}
	if (fd < 0)
	{
		write(2, "ERROR: filename ", 16);
		ft_printf("'%s' did not found\n", argv);
		return (NULL);
	}
	while ((k = get_next_line(fd, &line)) > 0)
	{
		ft_lstaddend(&list, ft_lstnew((void*)line, ft_strlen(line) + 1));
		ft_strdel(&line);
	}
	k == -1 ? write(2, "ERROR: incorrect input file\n", 28) : 0;
	ft_strdel(&line);
	return (list);
}

int		main(int argc, char **argv)
{
	int		fd[argc - 1];
	int		i;
	t_list	*list;

	list = NULL;
	i = 0;
	if (argc == 1)
		ft_printf(GREEN"usage: ./asm <some file.s>\n"RESET);
	while (++i < argc)
	{
		fd[i - 1] = open(argv[i], O_RDONLY);
		if ((list = read_from_file(argv[i], fd[i - 1], ft_strlen(argv[i]), 0)))
		{
			validation(list, argv[i], fd[i - 1]);
		}
		if (!list)
			write(2, "ERROR: empty file\n", 18);
		del_list_list(&list);
	}
	i--;
	while (--i >= 0)
		close(fd[i]);
	return (0);
}
