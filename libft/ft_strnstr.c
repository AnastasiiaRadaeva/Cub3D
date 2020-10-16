/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatwoma <kbatwoma@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 11:53:28 by kbatwoma          #+#    #+#             */
/*   Updated: 2020/05/19 16:42:42 by kbatwoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	n;
	size_t	c;

	i = 0;
	if (little[0] == '\0')
		return ((char *)big);
	if (len == 0)
		return (0);
	while (big[i] != '\0' && i < len)
	{
		while (big[i] != little[0] && big[i] != '\0' && i < len)
			i++;
		n = 0;
		c = i;
		while (big[i] == little[n] && little[n] != '\0' && i < len)
		{
			i++;
			n++;
		}
		if (little[n] == '\0')
			return ((char *)big + c);
	}
	return (0);
}
