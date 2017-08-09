/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   model.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itsuman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 21:07:12 by itsuman           #+#    #+#             */
/*   Updated: 2017/06/02 21:07:19 by itsuman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

char	is_process(t_process **process, int i)
{
	t_process	*tmp;

	tmp = *process;
	while (tmp)
	{
		if (tmp->pc == i && tmp->live >= 0)
			return (tmp->p_id);
		tmp = tmp->next;
	}
	return (0);
}

int		process_count(t_process *process)
{
	int			i;
	t_process	*tmp;

	i = 0;
	tmp = process;
	while (tmp)
	{
		if (tmp->live >= 0)
			i++;
		tmp = tmp->next;
	}
	return (i);
}

void	create_process(t_data **data, int index, int p_num, unsigned char p_id)
{
	int			i;
	t_process	*var;
	t_process	*last;

	i = 1;
	var = (t_process *)malloc(sizeof(t_process));
	last = (*data)->prcs;
	var->numb = (*data)->procnumb++;
	var->p_num = p_num;
	var->p_id = p_id;
	var->pc = index;
	var->live = 0;
	var->carry = 0;
	var->delay = 0;
	var->registers[0] = p_num;
	while (i < REG_NUMBER)
		var->registers[i++] = 0;
	var->next = (*data)->prcs;
	(*data)->prcs = var;
}

void	create_map(t_data **data)
{
	int				i;
	int				n;
	unsigned int	j;
	t_player		*var;

	var = (*data)->player;
	i = 0;
	while (i < (*data)->amount_players)
	{
		if (i == 0)
			n = 0;
		else
			n = (MEM_SIZE / (*data)->amount_players) * i;
		j = 0;
		create_process(&(*data), n, var->number, var->id);
		while (j < var->header->prog_size)
		{
			(*data)->map[n] = var->prog_cod[j];
			(*data)->map_v[n] = var->id;
			n++;
			j++;
		}
		var = var->next;
		i++;
	}
}

void	model(t_data **data)
{
	(*data)->speed = 20000;
	(*data)->procnumb = 1;
	create_map(&(*data));
	start_process(&(*data));
	free_player(&(*data)->player);
	free_process(&(*data)->prcs);
}
