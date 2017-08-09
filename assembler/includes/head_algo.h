/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   head_algo.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/01 18:13:37 by sprotsen          #+#    #+#             */
/*   Updated: 2017/07/01 18:13:38 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEAD_ALGO_H
# define HEAD_ALGO_H

typedef struct		s_algo
{
	char			*content;
	char			*origin;
	size_t			content_size;
	int				length;
	char			*hex;
	int				len_code;
	int				len_code_from_start;
	int				index_label;
	struct s_algo	*next;
}					t_algo;

#endif
