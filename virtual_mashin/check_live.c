/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cycle_to_die.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itsuman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 17:52:28 by itsuman           #+#    #+#             */
/*   Updated: 2017/07/06 17:52:31 by itsuman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	print_champ(t_data **data)
{
	ft_printf("Player %d (%s) won.\n", (*data)->win->number, (*data)->win
			->header->prog_name);
	exit(0);
}

int		check_process_live(t_process **process)
{
	t_process	*proc;
	int			f;

	proc = *process;
	f = 0;
	while (proc)
	{
		if (proc->live > 0)
			f++;
		proc = proc->next;
	}
	if (f == 0)
		return (1);
	else
		return (0);
}

void	reset_live(t_data **data)
{
	t_player	*play;
	t_process	*proc;

	proc = (*data)->prcs;
	play = (*data)->player;
	while (play)
	{
		play->live = 0;
		play = play->next;
	}
	while (proc)
	{
		if (proc->live > 0)
			proc->live = 0;
		proc = proc->next;
	}
}

int		check_live(t_data **data)
{
	t_process	*proc;
	t_player	*play;

	proc = (*data)->prcs;
	play = (*data)->player;
	while (proc)
	{
		if (proc->live <= 0)
			proc->live = -1;
		proc = proc->next;
	}
	if (check_process_live(&(*data)->prcs) || (*data)->ccl->ctd < CYCLE_DELTA)
		print_champ(&(*data));
	while (play)
	{
		if (play->live >= NBR_LIVE)
		{
			reset_live(&(*data));
			(*data)->ccl->max_check = 0;
			return (1);
		}
		play = play->next;
	}
	reset_live(&(*data));
	return (0);
}
