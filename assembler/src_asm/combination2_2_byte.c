/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   combination2_2_byte.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/25 14:49:14 by sprotsen          #+#    #+#             */
/*   Updated: 2017/06/25 14:49:16 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head_asm.h"

/*
** Type combinations:
** T_REG - T_REG - T_DIR 0x58 2_byte
** T_REG - T_DIR - T_DIR 0x68 2_byte
** T_REG - T_IND - T_DIR 0x78 2_byte
*/

/*
** 0x58 2_byte
*/

int		comb_t_reg_t_reg_t_dir_2(t_algo *lst, char **mass, t_algo *list)
{
	if (parsing_t_reg_v2(lst, mass[0]) == FALSE)
	{
		ft_strdel_char_mass(mass);
		return (FALSE);
	}
	if (parsing_t_reg_v2(lst, mass[1]) == FALSE)
	{
		ft_strdel_char_mass(mass);
		return (FALSE);
	}
	if (parsing_t_dir_2_byte_v2(lst, mass[2], list) == FALSE)
	{
		ft_strdel_char_mass(mass);
		return (FALSE);
	}
	ft_strdel_char_mass(mass);
	return (TRUE);
}

/*
** 0x68 2_byte
*/

int		comb_t_reg_t_dir_t_dir_2(t_algo *lst, char **mass, t_algo *list)
{
	if (parsing_t_reg_v2(lst, mass[0]) == FALSE)
	{
		ft_strdel_char_mass(mass);
		return (FALSE);
	}
	if (parsing_t_dir_2_byte_v2(lst, mass[1], list) == FALSE)
	{
		ft_strdel_char_mass(mass);
		return (FALSE);
	}
	if (parsing_t_dir_2_byte_v2(lst, mass[2], list) == FALSE)
	{
		ft_strdel_char_mass(mass);
		return (FALSE);
	}
	ft_strdel_char_mass(mass);
	return (TRUE);
}

/*
** 0x78 2_byte
*/

int		comb_t_reg_t_ind_t_dir_2(t_algo *lst, char **mass, t_algo *list)
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
	if (parsing_t_dir_2_byte_v2(lst, mass[2], list) == FALSE)
	{
		ft_strdel_char_mass(mass);
		return (FALSE);
	}
	ft_strdel_char_mass(mass);
	return (TRUE);
}
