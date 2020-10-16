/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatwoma <kbatwoma@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 22:24:31 by kbatwoma          #+#    #+#             */
/*   Updated: 2020/05/19 16:38:04 by kbatwoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int symbol)
{
	int i;

	i = 0;
	while (*((unsigned char *)str + i) != '\0' && \
			*((unsigned char *)str + i) != symbol)
		i++;
	if (symbol == '\0' && *((unsigned char *)str + i) == '\0')
		return ((char *)str + i);
	if (str[i] != '\0')
		return ((char *)str + i);
	return (0);
}
