/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itsuman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 20:37:29 by itsuman           #+#    #+#             */
/*   Updated: 2017/07/07 20:37:33 by itsuman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vm.h"

int		count_shift(int numb, unsigned char byte, int dir)
{
	unsigned char	cbyte[3];
	int				shift;
	int				i;

	i = 0;
	shift = 2;
	cbyte[0] = (unsigned char)(byte & 192) >> 6;
	cbyte[1] = (unsigned char)(byte & 48) >> 4;
	cbyte[2] = (unsigned char)(byte & 12) >> 2;
	while (i < numb)
	{
		if (cbyte[i] == REG_CODE)
			shift += 1;
		else if (cbyte[i] == IND_CODE)
			shift += 2;
		else if (cbyte[i] == DIR_CODE)
		{
			if (dir == 2)
				shift += 2;
			else
				shift += 4;
		}
		i++;
	}
	return (shift);
}

int		get_ind_address(t_data **data, t_process *process, int *shift)
{
	int				val[2];

	val[0] = ((*data)->map[(process->pc + *shift) % MEM_SIZE]);
	val[1] = ((*data)->map[(process->pc + *shift + 1) % MEM_SIZE]);
	*shift += 2;
	return (short)((val[0] << 8) + val[1]);
}

void	st(t_data **data, t_process **ps)
{
	unsigned char	p[2];
	int				v[3];
	int				shift;

	shift = 2;
	p[0] = (unsigned char)((*data)->map[((*ps)->pc + 1) % MEM_SIZE] & 192) >> 6;
	p[1] = (unsigned char)((*data)->map[((*ps)->pc + 1) % MEM_SIZE] & 48) >> 4;
	if (p[0] == REG_CODE)
		v[0] = get_reg_numb(&(*data), (*ps), &shift);
	if (p[1] == REG_CODE)
		v[1] = get_reg_numb(&(*data), (*ps), &shift);
	else if (p[1] == IND_CODE)
		v[1] = (short)get_ind_address(&(*data), (*ps), &shift);
	v[2] = (*ps)->pc + (v[1] % IDX_MOD);
	if (p[0] == REG_CODE && (v[0] > 0 && v[0] <= 16) && p[1] == IND_CODE)
	{
		load_value(&(*data), &(*ps), v[2], (*ps)->registers[v[0] - 1]);
		(*ps)->pc += 4;
	}
	else if (REG_V1 && REG_V2)
	{
		(*ps)->registers[v[1] - 1] = (*ps)->registers[v[0] - 1];
		(*ps)->pc += 3;
	}
	(*ps)->pc += 1;
}
