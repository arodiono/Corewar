/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   combination1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/24 21:25:25 by sprotsen          #+#    #+#             */
/*   Updated: 2017/06/24 21:25:26 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head_asm.h"

/*
** Type combinations:
** T_REG - T_IND - T_REG 0x74
** T_DIR - T_IND - T_REG 0xB4 4_byte
** T_IND - T_IND - T_REG 0xF4
** 0x74
*/

int		comb_t_reg_t_ind_t_reg(t_algo *lst, char **mass, t_algo *list)
{
	if (parsing_t_reg_v2(lst, mass[0]) == FALSE)
	{
		ft_strdel_char_mass(mass);
		return (FALSE);
	}
	if (parsing_t_ind_v2(lst, mass[1], list) == FALSE)
	{
		ft_strdel_char_mass(mass);
		return (FALSE);
	}
	if (parsing_t_reg_v2(lst, mass[2]) == FALSE)
	{
		ft_strdel_char_mass(mass);
		return (FALSE);
	}
	ft_strdel_char_mass(mass);
	return (TRUE);
}

/*
** 0xB4 4_byte
*/

int		comb_t_dir_t_ind_t_reg(t_algo *lst, char **mass, t_algo *list)
{
	if (parsing_t_dir_4_byte_v2(lst, mass[0], list) == FALSE)
	{
		ft_strdel_char_mass(mass);
		return (FALSE);
	}
	if (parsing_t_ind_v2(lst, mass[1], list) == FALSE)
	{
		ft_strdel_char_mass(mass);
		return (FALSE);
	}
	if (parsing_t_reg_v2(lst, mass[2]) == FALSE)
	{
		ft_strdel_char_mass(mass);
		return (FALSE);
	}
	ft_strdel_char_mass(mass);
	return (TRUE);
}

/*
** 0xF4
*/

int		comb_t_ind_t_ind_t_reg(t_algo *lst, char **mass, t_algo *list)
{
	if (parsing_t_ind_v2(lst, mass[0], list) == FALSE)
	{
		ft_strdel_char_mass(mass);
		return (FALSE);
	}
	if (parsing_t_ind_v2(lst, mass[1], list) == FALSE)
	{
		ft_strdel_char_mass(mass);
		return (FALSE);
	}
	if (parsing_t_reg_v2(lst, mass[2]) == FALSE)
	{
		ft_strdel_char_mass(mass);
		return (FALSE);
	}
	ft_strdel_char_mass(mass);
	return (TRUE);
}
