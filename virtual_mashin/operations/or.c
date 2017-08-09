/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   or.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itsuman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 20:45:39 by itsuman           #+#    #+#             */
/*   Updated: 2017/07/07 20:45:42 by itsuman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vm.h"

void	or(t_data **data, t_process **ps)
{
	unsigned char	p[3];
	int				val[3];
	int				shift;
	int				i;

	shift = 2;
	i = -1;
	p[0] = (unsigned char)((*data)->map[((*ps)->pc + 1) % MEM_SIZE] & 192) >> 6;
	p[1] = (unsigned char)((*data)->map[((*ps)->pc + 1) % MEM_SIZE] & 48) >> 4;
	p[2] = (unsigned char)((*data)->map[((*ps)->pc + 1) % MEM_SIZE] & 12) >> 2;
	while (++i < 2)
	{
		if (p[i] == REG_CODE)
			val[i] = get_reg_value(&(*data), (*ps), &shift);
		else if (p[i] == DIR_CODE)
			val[i] = get_dir_value(&(*data), (*ps), &shift, 4);
		else if (p[i] == IND_CODE)
			val[i] = get_ind_value(&(*data), (*ps), &shift, 4);
	}
	val[2] = get_reg_numb(&(*data), (*ps), &shift);
	if (val[2] <= REG_NUMBER && val[2] > 0 && p[0] > 0 && p[1] > 0 && p[2] == 1)
		(*ps)->registers[val[2] - 1] = val[0] | val[1];
	(*ps)->carry = (val[0] | val[1]) == 0 ? 1 : 0;
	(*ps)->pc += count_shift(3, (*data)->map[((*ps)->pc + 1) % MEM_SIZE], 4)
				% MEM_SIZE;
}
