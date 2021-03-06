/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zjmp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itsuman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 20:48:29 by itsuman           #+#    #+#             */
/*   Updated: 2017/07/07 20:48:30 by itsuman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vm.h"

void	zjmp(t_data **data, t_process **process)
{
	unsigned char	val[2];
	short			pos;

	if ((*process)->carry == 1)
	{
		val[0] = ((*data)->map[((*process)->pc + 1) % MEM_SIZE]);
		val[1] = ((*data)->map[((*process)->pc + 2) % MEM_SIZE]);
		pos = (short)((val[0] << 8) + val[1]);
		if (pos < 0)
			pos += MEM_SIZE;
		(*process)->pc = ((*process)->pc + pos) % MEM_SIZE;
	}
	else
		(*process)->pc += 3 % MEM_SIZE;
}
