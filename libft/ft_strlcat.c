/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatwoma <kbatwoma@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 15:46:46 by kbatwoma          #+#    #+#             */
/*   Updated: 2020/05/24 22:25:31 by kbatwoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t len_dst;
	size_t i;
	size_t len;

	i = 0;
	len_dst = ft_strlen(dst);
	len = len_dst + ft_strlen(src);
	if (size <= len_dst)
	{
		return (ft_strlen(src) + size);
	}
	while (src[i] != '\0' && len_dst + 1 < size)
	{
		dst[len_dst] = src[i];
		i++;
		len_dst++;
	}
	dst[len_dst] = '\0';
	return (len);
}
