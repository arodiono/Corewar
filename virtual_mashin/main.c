/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itsuman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 17:02:42 by itsuman           #+#    #+#             */
/*   Updated: 2017/06/02 17:02:48 by itsuman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void			set_players_number(t_player **player)
{
	char			c;
	unsigned int	i;
	t_player		*var;

	i = 0;
	c = 1;
	var = *player;
	while (var)
	{
		var->id = c;
		var->number = --i;
		var = var->next;
		c += 1;
	}
}

void			write_to_head(t_player **player, t_player **tmp)
{
	t_player	*last;

	if (*player == NULL)
		*player = *tmp;
	else
	{
		last = *player;
		while (last->next)
			last = last->next;
		last->next = *tmp;
	}
}

void			reed_player(char *file, t_player **player, int player_number)
{
	int			fd;
	char		*line;
	t_player	*tmp;

	fd = open(file, O_RDONLY);
	line = malloc(sizeof(t_header));
	if (fd > 0)
	{
		tmp = (t_player *)malloc(sizeof(t_player));
		tmp->number = (unsigned int)player_number;
		tmp->file = file;
		read(fd, line, sizeof(t_header));
		tmp->header = (t_header *)line;
		tmp->header->prog_size = bit_rev(tmp->header->prog_size);
		tmp->prog_cod = malloc(sizeof(char) * tmp->header->prog_size);
		read(fd, tmp->prog_cod, tmp->header->prog_size);
		tmp->live = 0;
		tmp->last_live = 0;
		close(fd);
		tmp->next = NULL;
		write_to_head(&(*player), &tmp);
	}
	else
		error_manager(file, 1);
}

void			reed_arg(t_data **data, char **av)
{
	int i;

	i = 0;
	while (av[++i])
	{
		if (ft_strcmp(av[i], "-dump") == 0)
		{
			if (is_nbr(av[++i]))
				(*data)->dump = ft_atoi(av[i]);
		}
		else if (ft_strcmp(av[i], "-n") == 0)
		{
			(*data)->nbr = ft_atoi(av[++i]);
			if (av[++i] && ft_strcmp(av[i], "-dump") != 0 &&
				ft_strcmp(av[i], "-n") != 0)
				reed_player(av[i], &(*data)->player, (*data)->nbr);
		}
		else if (ft_strcmp(av[i], "-v") == 0)
			(*data)->v = 1;
		else
			reed_player(av[i], &(*data)->player, 0);
	}
}

int				main(int ac, char **av)
{
	t_data	*data;

	if (ac > 1)
	{
		data = (t_data *)malloc(sizeof(t_data));
		data->player = NULL;
		data->amount_players = check_arg(av, 0, 0, 0);
		reed_arg(&data, av);
		set_players_number(&data->player);
		controller(&data->player);
		model(&data);
	}
	else
		use();
	return (0);
}
