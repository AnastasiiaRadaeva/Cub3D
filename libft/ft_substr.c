/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatwoma <kbatwoma@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 17:26:51 by kbatwoma          #+#    #+#             */
/*   Updated: 2020/05/21 23:40:25 by kbatwoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new_str;
	size_t	i;
	size_t	len_s;

	i = start;
	len_s = 0;
	if (!s)
		return (0);
	if (ft_strlen(s) <= start)
	{
		new_str = ft_strdup("");
		return (new_str);
	}
	while (s[i++] != '\0')
		len_s++;
	if (len_s < len)
		len = len_s;
	if (!(new_str = malloc(sizeof(*s) * (len + 1))))
		return (0);
	else
	{
		ft_strlcpy(new_str, ((char const*)s + (start)), len + 1);
		return (new_str);
	}
}
