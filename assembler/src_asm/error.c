/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/01 16:41:29 by sprotsen          #+#    #+#             */
/*   Updated: 2017/07/01 16:42:21 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head_asm.h"

int		error_message(t_algo *lst, char **mass)
{
	ft_printf(RED"");
	write(2, "ERROR: Lexical error at:\n", 25);
	ft_printf("%s\n", lst->origin);
	ft_printf("Number line with error: %d\n"RESET, lst->length);
	ft_strdel_char_mass(mass);
	return (FALSE);
}
