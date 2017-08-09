/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/04 17:03:28 by sprotsen          #+#    #+#             */
/*   Updated: 2017/06/04 17:03:31 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head_asm.h"

void	del_list_list(t_list **list)
{
	if (*list)
	{
		del_list_list(&(*list)->next);
		ft_memdel(&(*list)->content);
		free(*list);
		*list = NULL;
	}
}

void	del_list_algo(t_algo **list)
{
	if (*list)
	{
		del_list_algo(&(*list)->next);
		ft_strdel(&(*list)->content);
		ft_strdel(&(*list)->origin);
		ft_strdel(&(*list)->hex);
		free(*list);
	}
}

int		del_list_algo_false(t_algo **list)
{
	if (*list)
	{
		del_list_algo(&(*list)->next);
		ft_strdel(&(*list)->content);
		ft_strdel(&(*list)->origin);
		ft_strdel(&(*list)->hex);
		free(*list);
	}
	return (FALSE);
}

int		ft_strdel_char_mass_false(char **mass)
{
	int		i;

	i = 0;
	if (mass)
	{
		while (mass[i])
		{
			ft_strdel(&mass[i]);
			i++;
		}
		free(mass);
		mass = NULL;
	}
	return (FALSE);
}
