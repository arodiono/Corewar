/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_process.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itsuman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 19:10:55 by itsuman           #+#    #+#             */
/*   Updated: 2017/07/07 19:10:58 by itsuman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	perform_function_continue(t_data **data, t_process **process, int byte)
{
	if ((unsigned char)byte == 0x09)
		zjmp(&(*data), &(*process));
	else if ((unsigned char)byte == 0x0a)
		ldi(&(*data), &(*process));
	else if ((unsigned char)byte == 0x0b)
		sti(&(*data), &(*process));
	else if ((unsigned char)byte == 0x0c)
		ft_fork(&(*data), &(*process));
	else if ((unsigned char)byte == 0x0d)
		lld(&(*data), &(*process));
	else if ((unsigned char)byte == 0x0e)
		lldi(&(*data), &(*process));
	else if ((unsigned char)byte == 0x0f)
		lfork(&(*data), &(*process));
	else if ((unsigned char)byte == 0x10)
		aff(&(*data), &(*process));
	else
		(*process)->pc = ((*process)->pc + 1) % MEM_SIZE;
}

void	perform_function(t_data **data, t_process **process, int byte)
{
	if ((*process)->delay > 0)
		return ;
	if ((unsigned char)byte == 0x01)
		live(&(*data), &(*process));
	else if ((unsigned char)byte == 0x02)
		ld(&(*data), &(*process));
	else if ((unsigned char)byte == 0x03)
		st(&(*data), &(*process));
	else if ((unsigned char)byte == 0x04)
		add(&(*data), &(*process));
	else if ((unsigned char)byte == 0x05)
		sub(&(*data), &(*process));
	else if ((unsigned char)byte == 0x06)
		and(&(*data), &(*process));
	else if ((unsigned char)byte == 0x07)
		or(&(*data), &(*process));
	else if ((unsigned char)byte == 0x08)
		xor(&(*data), &(*process));
	else
		perform_function_continue(&(*data), &(*process), byte);
}

void	set_live_del(t_process **process)
{
	(*process)->live++;
	(*process)->delay = 10;
	(*process)->f = 1;
}

void	set_delay(t_process **process, int byte)
{
	if ((*process)->delay != 0)
		return ;
	if (byte == 0x04 || byte == 0x05 || byte == 0x0d)
		(*process)->delay = 10;
	else if (byte == 0x01)
		set_live_del(&(*process));
	else if (byte == 0x02 || byte == 0x03)
		(*process)->delay = 5;
	else if (byte == 0x06 || byte == 0x07 || byte == 0x08)
		(*process)->delay = 6;
	else if (byte == 0x0a || byte == 0x0b)
		(*process)->delay = 25;
	else if (byte == 0x09)
		(*process)->delay = 20;
	else if (byte == 0x0c)
		(*process)->delay = 800;
	else if (byte == 0x0e)
		(*process)->delay = 50;
	else if (byte == 0x0f)
		(*process)->delay = 1000;
	else if (byte == 0x10)
		(*process)->delay = 2;
}

void	run_process(t_data **data)
{
	t_process	*proc;
	int			byte;

	proc = (*data)->prcs;
	while (proc)
	{
		byte = (int)(*data)->map[proc->pc];
		set_delay(&proc, byte);
		if (proc->delay > 0 && proc->live >= 0)
			proc->delay--;
		if (proc->delay == 0 && proc->live >= 0 && byte > 0 && byte < 17)
			perform_function(&(*data), &proc, byte);
		else if (proc->delay == 0 && proc->live >= 0 && proc->f == 1)
			live(&(*data), &proc);
		else if (proc->delay == 0)
			proc->pc = (proc->pc + 1) % MEM_SIZE;
		proc = proc->next;
	}
}
