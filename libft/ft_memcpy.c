/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatwoma <kbatwoma@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 22:43:34 by kbatwoma          #+#    #+#             */
/*   Updated: 2020/05/19 16:06:19 by kbatwoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *s, size_t n)
{
	size_t i;

	i = 0;
	if (!dst && !s)
		return (0);
	while (i < n)
	{
		*((char *)dst + i) = *((char *)s + i);
		i++;
	}
	return ((void *)dst);
}
