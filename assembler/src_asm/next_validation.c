/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/11 13:02:42 by sprotsen          #+#    #+#             */
/*   Updated: 2017/06/11 13:02:46 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head_asm.h"

void	count_len(t_algo *lst)
{
	int		count;

	count = 0;
	while (lst)
	{
		if (lst->content_size == 4000000000)
		{
			ft_strdel(&(lst)->hex);
			lst->len_code_from_start = count / 2;
		}
		else if (lst->content_size > 4000000000)
		{
			ft_strdel(&(lst)->hex);
			lst->len_code_from_start = count / 2;
			count += lst->len_code;
		}
		lst = lst->next;
	}
}

void	next_validation_part3(t_algo *lst)
{
	fun_live(lst);
	fun_add(lst);
	fun_sub(lst);
	fun_aff(lst);
	fun_zjmp(lst);
	fun_fork(lst);
	fun_lfork(lst);
	fun_ld(lst);
	fun_lld(lst);
	fun_st(lst);
	fun_and(lst);
	fun_or(lst);
	fun_xor(lst);
	fun_lldi(lst);
	fun_ldi(lst);
	fun_sti(lst);
}

int		next_validation_part2(t_algo *lst)
{
	if (fun_and(lst) == FALSE)
		return (FALSE);
	if (fun_or(lst) == FALSE)
		return (FALSE);
	if (fun_xor(lst) == FALSE)
		return (FALSE);
	if (fun_lldi(lst) == FALSE)
		return (FALSE);
	if (fun_ldi(lst) == FALSE)
		return (FALSE);
	if (fun_sti(lst) == FALSE)
		return (FALSE);
	count_len(lst);
	next_validation_part3(lst);
	return (TRUE);
}

int		next_validation(t_algo *lst)
{
	if (name_and_transformation_to_hex(lst, 0, 0) == FALSE)
		return (FALSE);
	if (comment_and_transformation_to_hex(lst, 0, 0) == FALSE)
		return (FALSE);
	if (fun_live(lst) == FALSE)
		return (FALSE);
	if (fun_add(lst) == FALSE)
		return (FALSE);
	if (fun_sub(lst) == FALSE)
		return (FALSE);
	if (fun_aff(lst) == FALSE)
		return (FALSE);
	if (fun_zjmp(lst) == FALSE)
		return (FALSE);
	if (fun_fork(lst) == FALSE)
		return (FALSE);
	if (fun_lfork(lst) == FALSE)
		return (FALSE);
	if (fun_ld(lst) == FALSE)
		return (FALSE);
	if (fun_lld(lst) == FALSE)
		return (FALSE);
	if (fun_st(lst) == FALSE)
		return (FALSE);
	return (next_validation_part2(lst));
}
