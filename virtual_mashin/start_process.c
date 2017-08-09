/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itsuman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/04 20:23:30 by itsuman           #+#    #+#             */
/*   Updated: 2017/07/04 20:23:34 by itsuman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	print_map(unsigned char *map)
{
	int i;

	i = 0;
	while (i < MEM_SIZE)
	{
		if ((i % 64) == 0)
			ft_printf("0x%.4x : ", i);
		ft_printf("%.2x ", map[i]);
		i++;
		if ((i % 64) == 0)
			ft_printf("\n");
	}
	exit(1);
}

void	cycle(t_data **data)
{
	(*data)->ccl->current = 0;
	while ((*data)->ccl->current < (*data)->ccl->ctd)
	{
		run_process(&(*data));
		if ((*data)->v == 1)
			visualise(&(*data));
		if ((*data)->dump > 0 && (*data)->dump == (*data)->ccl->cycle)
			print_map((*data)->map);
		(*data)->ccl->current++;
		(*data)->ccl->cycle++;
	}
	if (check_live(&(*data)))
	{
		(*data)->ccl->ctd -= CYCLE_DELTA;
		(*data)->ccl->max_check = 0;
	}
	else
		(*data)->ccl->max_check++;
	if ((*data)->ccl->max_check == MAX_CHECKS)
	{
		reset_live(&(*data));
		(*data)->ccl->ctd -= CYCLE_DELTA;
		(*data)->ccl->max_check = 0;
	}
}

void	start_process(t_data **data)
{
	(*data)->ccl = malloc(sizeof(t_cycle));
	(*data)->ccl->max_check = 0;
	(*data)->ccl->ctd = CYCLE_TO_DIE;
	(*data)->ccl->cycle = 1;
	while (1)
	{
		cycle(&(*data));
	}
}
