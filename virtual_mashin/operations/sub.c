/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itsuman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 20:41:12 by itsuman           #+#    #+#             */
/*   Updated: 2017/07/07 20:41:20 by itsuman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vm.h"

void	sub(t_data **data, t_process **ps)
{
	unsigned char	p[3];
	int				val[3];
	int				shift;
	int				pos;

	shift = 2;
	pos = 2;
	p[0] = (unsigned char)((*data)->map[((*ps)->pc + 1) % MEM_SIZE] & 192) >> 6;
	p[1] = (unsigned char)((*data)->map[((*ps)->pc + 1) % MEM_SIZE] & 48) >> 4;
	p[2] = (unsigned char)((*data)->map[((*ps)->pc + 1) % MEM_SIZE] & 12) >> 2;
	if (p[0] == REG_CODE && p[1] == REG_CODE && p[2] == REG_CODE)
	{
		val[0] = get_reg_numb(&(*data), (*ps), &shift);
		val[1] = get_reg_numb(&(*data), (*ps), &shift);
		val[2] = get_reg_numb(&(*data), (*ps), &shift);
		if (val[0] <= 16 && val[0] > 0 &&
				val[1] <= 16 && val[1] > 0 && val[2] <= 16 && val[2] > 0)
		{
			val[0] = get_reg_value(&(*data), (*ps), &pos);
			val[1] = get_reg_value(&(*data), (*ps), &pos);
			(*ps)->registers[val[2] - 1] = val[0] - val[1];
		}
	}
	(*ps)->carry = val[0] - val[1] == 0 ? 1 : 0;
	(*ps)->pc += count_shift(3, (*data)->map[((*ps)->pc + 1) % 4096], 4) % 4096;
}
