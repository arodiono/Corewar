/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 17:08:55 by sprotsen          #+#    #+#             */
/*   Updated: 2016/12/03 17:08:57 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strclr(char *s)
{
	size_t	len;

	if (s != NULL)
	{
		len = ft_strlen(s);
		while (len--)
			s[len] = '\0';
	}
}