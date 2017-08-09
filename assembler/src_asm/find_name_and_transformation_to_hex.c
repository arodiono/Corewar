/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_name_and_transformation_to_hex.c              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/11 13:17:22 by sprotsen          #+#    #+#             */
/*   Updated: 2017/06/11 13:17:24 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head_asm.h"

int		error_name_comment(t_algo *lst)
{
	ft_printf(RED"");
	write(2, "ERROR: problem in line:\n", 24);
	ft_printf("%s\n", lst->origin);
	ft_printf("Number line with error: %d\n"RESET, lst->length);
	return (FALSE);
}

int		error_name_comment_v2(t_algo *lst, int a)
{
	ft_printf(RED"");
	write(2, "ERROR: name is too long\n", 24);
	ft_printf("%s\n", lst->origin);
	ft_printf("Max length %d \n", a);
	ft_printf("Number line with error: %d\n"RESET, lst->length);
	return (FALSE);
}

int		error_place(t_algo *lst)
{
	ft_printf(RED"");
	write(2, "ERROR with sequence\n", 20);
	ft_printf("Number line with error: %d\n"RESET, lst->length);
	return (FALSE);
}

int		name_and_transformation_to_hex(t_algo *lst, int len, int len_all)
{
	char	*str;

	while (NCLINE(lst->content_size))
	{
		if (lst->content_size == 3000000001)
			break ;
		lst = lst->next;
	}
	if (lst->content_size != 3000000001)
		return (error_place(lst));
	len_all = ft_strlen(lst->content);
	str = lst->content;
	while (str[--len_all] <= 32)
		str[len_all] = '\0';
	if (str[len_all] != '"')
		return (error_name_comment(lst));
	len = pass_space_opcode_space(str, 0, ft_strlen(NAME_CMD_STRING));
	if (str[len] != '"')
		return (error_name_comment(lst));
	if (ft_strrchr(str, '"') - ft_strchr(str + len + 1, '"') != 0)
		return (error_name_comment(lst));
	lst->hex = ft_strsub(str, len + 1, len_all - len - 1);
	if (ft_strlen(lst->hex) > (int)PROG_NAME_LENGTH)
		return (error_name_comment_v2(lst, PROG_NAME_LENGTH));
	return (TRUE);
}

int		comment_and_transformation_to_hex(t_algo *lst, int len, int len_all)
{
	char	*str;

	while (NCLINE(lst->content_size))
	{
		if (lst->content_size == 3000000002)
			break ;
		lst = lst->next;
	}
	if (lst->content_size != 3000000002)
		return (error_place(lst));
	len_all = ft_strlen(lst->content);
	str = lst->content;
	while (str[--len_all] <= 32)
		str[len_all] = '\0';
	if (str[len_all] != '"')
		return (error_name_comment(lst));
	len = pass_space_opcode_space(str, 0, ft_strlen(COMMENT_CMD_STRING));
	if (str[len] != '"')
		return (error_name_comment(lst));
	if ((ft_strrchr(str, '"') - ft_strchr(str + len + 1, '"')) != 0)
		return (error_name_comment(lst));
	lst->hex = ft_strsub(str, len + 1, len_all - len - 1);
	if (ft_strlen(lst->hex) > (int)COMMENT_LENGTH)
		return (error_name_comment_v2(lst, COMMENT_LENGTH));
	return (TRUE);
}
