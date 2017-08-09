/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ldi.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itsuman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 20:50:20 by itsuman           #+#    #+#             */
/*   Updated: 2017/07/07 20:50:22 by itsuman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vm.h"

int		get_direct(t_data **data, t_process *process, int position)
{
	int		i;
	int		val[4];

	i = 0;
	while (i < REG_SIZE)
	{
		val[i] = (*data)->map[(process->pc + position + i) % MEM_SIZE];
		i++;
	}
	return ((val[0] << 24) + (val[1] << 16) + (val[2] << 8) + val[3]);
}

void	ldi(t_data **data, t_process **ps)
{
	unsigned char	p[3];
	int				val[4];
	int				shift;

	shift = 2;
	p[0] = (unsigned char)((*data)->map[((*ps)->pc + 1) % MEM_SIZE] & 192) >> 6;
	p[1] = (unsigned char)((*data)->map[((*ps)->pc + 1) % MEM_SIZE] & 48) >> 4;
	p[2] = (unsigned char)((*data)->map[((*ps)->pc + 1) % MEM_SIZE] & 12) >> 2;
	if (p[0] == REG_CODE)
		val[0] = get_reg_value(&(*data), (*ps), &shift);
	else if (p[0] == DIR_CODE)
		val[0] = (short)get_dir_value(&(*data), (*ps), &shift, 2);
	else if (p[0] == IND_CODE)
		val[0] = (short)get_ind_value(&(*data), (*ps), &shift, 2);
	if (p[1] == REG_CODE)
		val[1] = get_reg_value(&(*data), (*ps), &shift);
	else if (p[1] == DIR_CODE)
		val[1] = get_dir_value(&(*data), (*ps), &shift, 2);
	val[2] = get_reg_numb(&(*data), (*ps), &shift);
	val[3] = get_direct(&(*data), (*ps),
						((val[0] + val[1]) % IDX_MOD) % MEM_SIZE);
	if ((val[2] <= 16 && val[2] > 0) && p[0] > 0 && (p[1] == 1 || p[1] == 2))
		(*ps)->registers[val[2] - 1] = val[3];
	(*ps)->pc += count_shift(3, (*data)->map[((*ps)->pc + 1) % MEM_SIZE], 2)
				% MEM_SIZE;
}
