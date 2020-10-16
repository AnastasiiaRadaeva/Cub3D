/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatwoma <kbatwoma@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 12:44:47 by kbatwoma          #+#    #+#             */
/*   Updated: 2020/05/19 16:39:40 by kbatwoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t num)
{
	size_t index;

	index = 0;
	if (num == 0)
		return (0);
	while (*((unsigned char*)s1 + index) != '\0' && \
			*((unsigned char*)s1 + index) == *((unsigned char*)s2 + index) && \
			index < num - 1)
		index++;
	return (*((unsigned char*)s1 + index) - *((unsigned char*)s2 + index));
}
