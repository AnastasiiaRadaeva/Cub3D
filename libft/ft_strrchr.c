/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatwoma <kbatwoma@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 11:28:31 by kbatwoma          #+#    #+#             */
/*   Updated: 2020/05/18 20:44:48 by kbatwoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int symbol)
{
	size_t i;

	i = ft_strlen(str);
	if (!str)
		return (0);
	while (i > 0 && *((unsigned char *)str + i) != symbol)
		i--;
	if (i == 0 && *((unsigned char *)str) != symbol)
		return (0);
	return ((char *)str + i);
}
