/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatwoma <kbatwoma@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 15:17:12 by kbatwoma          #+#    #+#             */
/*   Updated: 2020/05/19 16:44:30 by kbatwoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_calloc(size_t num, size_t size)
{
	void	*str;
	size_t	i;

	i = 0;
	str = malloc(size * num);
	if (str != 0)
	{
		while (i < num * size)
		{
			*((char *)str + i) = 0;
			i++;
		}
		return (str);
	}
	return (0);
}
