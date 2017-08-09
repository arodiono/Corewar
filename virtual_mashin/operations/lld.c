/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lld.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itsuman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 20:55:18 by itsuman           #+#    #+#             */
/*   Updated: 2017/07/07 20:55:21 by itsuman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vm.h"

void	lld(t_data **data, t_process **ps)
{
	unsigned char	par[2];
	int				val[2];
	int				shift;

	shift = 2;
	par[0] = (unsigned char)((*data)->map[(((*ps)->pc + 1))
		% MEM_SIZE] & 192) >> 6;
	par[1] = (unsigned char)((*data)->map[(((*ps)->pc + 1))
		% MEM_SIZE] & 48) >> 4;
	if (par[0] == DIR_CODE)
		val[0] = get_dir_value(&(*data), (*ps), &shift, 4);
	else if (par[0] == IND_CODE)
		val[0] = get_ind_value(&(*data), (*ps), &shift, 4);
	if (par[1] == REG_CODE)
		val[1] = get_reg_numb(&(*data), (*ps), &shift);
	if ((val[1] <= REG_NUMBER && val[1] > 0) && (par[0] == 2 || par[0] == 3)
		&& par[1] == 1)
	{
		if (par[0] == IND_CODE)
			(*ps)->registers[val[1] - 1] = (val[0] << 16);
		else
			(*ps)->registers[val[1] - 1] = val[0];
	}
	(*ps)->carry = val[0] == 0 ? 1 : 0;
	(*ps)->pc += count_shift(2, (*data)->map[((*ps)->pc + 1) % 4096], 4) % 4096;
}
