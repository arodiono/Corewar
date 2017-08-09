/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   and.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itsuman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 20:43:26 by itsuman           #+#    #+#             */
/*   Updated: 2017/07/07 20:43:28 by itsuman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vm.h"

int		get_dir_value(t_data **data, t_process *process, int *shift, int dsize)
{
	int		i;
	int		val[4];

	i = 0;
	while (i < dsize)
	{
		val[i] = ((*data)->map[(process->pc + (*shift)) % MEM_SIZE]);
		(*shift)++;
		i++;
	}
	if (dsize == 4)
		return (val[0] << 24) + (val[1] << 16) + (val[2] << 8) + val[3];
	else
		return ((val[0] << 8) + val[1]);
}

int		get_ind_value(t_data **data, t_process *process, int *shift, int size)
{
	int	val[7];
	int	i;
	int	adr;

	i = 0;
	val[0] = ((*data)->map[(process->pc + *shift) % MEM_SIZE]);
	val[1] = ((*data)->map[(process->pc + *shift + 1) % MEM_SIZE]);
	adr = (val[0] << 8) + val[1];
	if (adr < 0)
		adr += MEM_SIZE;
	while (i < size)
	{
		val[i + 2] = (*data)->map[(process->pc + adr + i) % MEM_SIZE];
		i++;
	}
	(*shift) += 2;
	return ((val[2] << 24) + (val[3] << 16) + (val[4] << 8) + val[5]);
}

int		get_reg_value(t_data **data, t_process *process, int *shift)
{
	int res;

	res = process->registers[(*data)->map[(process->pc
		+ (*shift)) % MEM_SIZE] - 1];
	(*shift)++;
	return (res);
}

int		get_reg_numb(t_data **data, t_process *process, int *shift)
{
	int res;

	res = (*data)->map[(process->pc + (*shift)) % MEM_SIZE];
	(*shift)++;
	return (res);
}

void	and(t_data **data, t_process **ps)
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
		(*ps)->registers[val[2] - 1] = (val[0] & val[1]);
	(*ps)->carry = (val[0] & val[1]) == 0 ? 1 : 0;
	(*ps)->pc += count_shift(3, (*data)->map[((*ps)->pc + 1) % MEM_SIZE], 4)
				% MEM_SIZE;
}
