/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 21:46:18 by sprotsen          #+#    #+#             */
/*   Updated: 2017/06/07 21:57:12 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head_asm.h"

t_algo	*create_list_algo(char *str, int i)
{
	t_algo	*list;

	list = (t_algo*)malloc(sizeof(t_algo));
	if (!list)
		return (NULL);
	list->content = ft_strdup(str);
	list->origin = ft_strdup(str);
	list->content_size = 0;
	list->length = i;
	list->hex = NULL;
	list->len_code = 0;
	list->len_code_from_start = 0;
	list->index_label = 0;
	list->next = NULL;
	return (list);
}

t_algo	*create_list_algo_new(char *str, int i, int length, char *origin)
{
	t_algo	*list;

	list = (t_algo*)malloc(sizeof(t_algo));
	if (!list)
		return (NULL);
	list->content = ft_strdup(str + i + 1);
	list->origin = ft_strdup(origin + i + 1);
	list->content_size = 0;
	list->length = length;
	list->hex = NULL;
	list->next = NULL;
	return (list);
}

void	add_algo(t_algo **alst, t_algo *new)
{
	t_algo	*list;

	if (*alst == NULL)
		*alst = new;
	else
	{
		list = *alst;
		while (list->next)
			list = list->next;
		list->next = new;
	}
}

int		size_algo(t_algo *begin_list)
{
	int		count;
	t_algo	*list;

	count = 0;
	list = begin_list;
	if (list)
	{
		while (list)
		{
			count++;
			list = list->next;
		}
		return (count);
	}
	else
		return (0);
}

void	add_algo_center(t_algo **list, t_algo *new)
{
	new->next = (*list)->next;
	(*list)->next = new;
}
