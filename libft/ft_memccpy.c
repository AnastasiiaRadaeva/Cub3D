/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatwoma <kbatwoma@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 09:32:10 by kbatwoma          #+#    #+#             */
/*   Updated: 2020/05/25 21:53:12 by kbatwoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *s, int c, size_t n)
{
	size_t i;

	i = 0;
	if (!dst && !s)
		return (0);
	while (i < n && *((unsigned char *)s + i) != '\0')
	{
		*((unsigned char *)dst + i) = *((unsigned char *)s + i);
		if (*((unsigned char *)dst + i) == (unsigned char)c)
			return ((void *)(dst + (i + 1)));
		i++;
	}
	return (0);
}
