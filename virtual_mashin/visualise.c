/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualise.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arodiono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 17:10:14 by arodiono          #+#    #+#             */
/*   Updated: 2017/07/18 17:10:16 by arodiono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	wprint_status(t_data **data, WINDOW **status)
{
	t_player	*tmp;
	float		sp;

	sp = 1 / ((float)(*data)->speed / (float)1000000);
	tmp = (*data)->player;
	wattron(*status, A_BOLD);
	wprintw(*status, "CYCLES/SECOND\t%.1f\n", sp);
	wprintw(*status, "CYCLE\t\t%d\n\n", (*data)->ccl->cycle);
	wprintw(*status, "CYCLE_TO_DIE\t%d\n", (*data)->ccl->ctd);
	wprintw(*status, "CYCLE_DELTA\t%d\n", CYCLE_DELTA);
	wprintw(*status, "NBR_LIVE\t%d\n", NBR_LIVE);
	wprintw(*status, "MAX_CHECKS\t%d\n", MAX_CHECKS);
	wprintw(*status, "\nPROCESSES\t%d\n", process_count((*data)->prcs));
	while (tmp)
	{
		wprintw(*status, "\nPLAYER %i\t", tmp->number);
		wattron(*status, COLOR_PAIR(tmp->id));
		wprintw(*status, "%s\n", tmp->header->prog_name);
		wattroff(*status, COLOR_PAIR(tmp->id));
		wprintw(*status, "  LIVE\t\t%d\n", tmp->live);
		wprintw(*status, "  LAST LIVE\t%d\n", tmp->last_live);
		tmp = tmp->next;
	}
	wattroff(*status, A_BOLD);
}

void	wprint_map(t_data **data, WINDOW **map)
{
	int		i;
	int		color;
	char	p_id;

	i = -1;
	while (++i < MEM_SIZE)
	{
		if ((i % 64) == 0)
			wprintw((*map), "0x%.4x : ", i);
		color = (*data)->map_v[i] == 0 ? 10 : (*data)->map_v[i];
		if ((p_id = is_process(&(*data)->prcs, i)))
		{
			wattron((*map), COLOR_PAIR(p_id + 4));
			wprintw((*map), "%.2x", (*data)->map[i]);
			wattroff((*map), COLOR_PAIR(p_id + 4));
			wprintw((*map), " ");
		}
		else
		{
			wattron((*map), COLOR_PAIR(color));
			wprintw((*map), "%.2x ", (*data)->map[i]);
			wattroff((*map), COLOR_PAIR(color));
		}
	}
	wrefresh(*map);
}

void	colors_init(void)
{
	init_color(COLOR_WHITE, 700, 700, 700);
	init_pair(14, COLOR_BLACK, COLOR_WHITE);
	init_pair(10, COLOR_WHITE, COLOR_BLACK);
	init_pair(1, COLOR_GREEN, COLOR_BLACK);
	init_pair(2, COLOR_BLUE, COLOR_BLACK);
	init_pair(3, COLOR_RED, COLOR_BLACK);
	init_pair(4, COLOR_CYAN, COLOR_BLACK);
	init_pair(5, COLOR_BLACK, COLOR_GREEN);
	init_pair(6, COLOR_BLACK, COLOR_BLUE);
	init_pair(7, COLOR_BLACK, COLOR_RED);
	init_pair(8, COLOR_BLACK, COLOR_CYAN);
	init_pair(0, COLOR_WHITE, COLOR_BLACK);
}

void	getkey(t_data **data)
{
	int	key;

	key = getch();
	if (key == 27)
	{
		endwin();
		exit(1);
	}
	else if (key == 32)
		while (1)
		{
			key = getch();
			if (key == 32)
				break ;
		}
	else if (key == 'e')
	{
		if ((*data)->speed > 1001)
			(*data)->speed -= 1000;
	}
	else if (key == 'w')
		if ((*data)->speed < 4294967295)
			(*data)->speed += 1000;
}

void	visualise(t_data **data)
{
	WINDOW	*map;
	WINDOW	*status;

	map = newwin(64, 201, 1, 2);
	status = newwin(64, 48, 1, 205);
	initscr();
	noecho();
	nodelay(stdscr, TRUE);
	start_color();
	colors_init();
	wprint_map(&(*data), &map);
	wprint_status(&(*data), &status);
	refresh();
	wrefresh(status);
	wrefresh(map);
	getkey(&(*data));
	usleep((*data)->speed);
}
