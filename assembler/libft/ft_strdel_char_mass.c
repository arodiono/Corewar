/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdel_char_mass.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/08 21:00:34 by sprotsen          #+#    #+#             */
/*   Updated: 2017/04/08 21:00:36 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strdel_char_mass(char **mass)
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
}
