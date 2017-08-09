/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itsuman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 21:05:50 by itsuman           #+#    #+#             */
/*   Updated: 2017/06/06 21:05:56 by itsuman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void			free_player(t_player **player)
{
	t_player *tmp;

	tmp = (*player);
	while (tmp->next)
	{
		tmp = (*player);
		if ((*player)->prog_cod)
			free((*player)->prog_cod);
		free((*player)->header);
		(*player) = (*player)->next;
		free(tmp);
	}
}

void			free_process(t_process **process)
{
	t_process	*var;

	if (process)
	{
		while (*process)
		{
			var = *process;
			*process = (*process)->next;
			free(var);
		}
		free(process);
	}
}

unsigned int	bit_rev(unsigned int octet)
{
	unsigned int	x[4];

	x[0] = (unsigned int)((octet & 4278190080) >> 24);
	x[1] = ((octet & 16711680) >> 8);
	x[2] = ((octet & 65280) << 8);
	x[3] = ((octet & 255) << 24);
	return (x[0] + x[1] + x[2] + x[3]);
}
