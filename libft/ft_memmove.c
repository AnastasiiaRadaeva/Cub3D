/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatwoma <kbatwoma@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 09:57:18 by kbatwoma          #+#    #+#             */
/*   Updated: 2020/05/24 23:42:06 by kbatwoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memmove(void *dst, const void *s, size_t n)
{
	size_t	i;

	i = 0;
	if (!dst && !s)
		return (0);
	if (s < dst)
	{
		i = n;
		while (i > 0)
		{
			*((char *)dst + (i - 1)) = *((char *)s + (i - 1));
			i--;
		}
	}
	else
		while (i < n)
		{
			*((char *)dst + i) = *((char *)s + i);
			i++;
		}
	return ((void *)dst);
}
