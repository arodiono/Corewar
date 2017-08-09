/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   use.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arodiono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/09 20:50:56 by arodiono          #+#    #+#             */
/*   Updated: 2017/08/09 20:51:11 by arodiono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	use(void)
{
	ft_putstr("Usage: ./corewar [-d N -s N -v N | -b --stealth]\n");
	ft_putstr("-n N		: Means that Player after this flag will be\n");
	ft_putstr("#### TEXT OUTPUT MODE #####################################\n");
	ft_putstr("-dump N		: Dumps memory after N cycles then exits\n");
	ft_putstr("#### NCURSES OUTPUT MODE ##################################\n");
	ft_putstr("-v		: Ncurses output mode\n");
	ft_putstr("###########################################################\n");
}
