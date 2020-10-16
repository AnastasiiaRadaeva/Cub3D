/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatwoma <kbatwoma@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 16:06:58 by kbatwoma          #+#    #+#             */
/*   Updated: 2020/05/19 16:45:12 by kbatwoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *str)
{
	int		len;
	char	*duplicate;

	if (!str)
		return (0);
	len = ft_strlen(str);
	duplicate = malloc(sizeof(*str) * (len + 1));
	if (duplicate)
	{
		ft_strlcpy(duplicate, str, len + 1);
		return (duplicate);
	}
	else
		return (0);
}
