/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatwoma <kbatwoma@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 11:45:08 by kbatwoma          #+#    #+#             */
/*   Updated: 2020/05/25 21:53:26 by kbatwoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *arr, int c, size_t n)
{
	size_t i;

	i = 0;
	if (n == 0)
		return (0);
	while ((char *)arr && *((char *)arr + i) != c \
			&& i < (n - 1))
		i++;
	if (*((char *)arr + i) == c)
		return ((void *)(arr + i));
	return (0);
}
