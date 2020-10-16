/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatwoma <kbatwoma@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 12:16:31 by kbatwoma          #+#    #+#             */
/*   Updated: 2020/05/24 23:14:47 by kbatwoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		ft_skip(char const *s, size_t index, char c)
{
	while (s[index] == c && s[index])
		index++;
	return (index);
}

static int			word_count(char const *s, char c)
{
	int				index;
	int				word;

	word = 0;
	index = ft_skip(s, 0, c);
	if (s[index] != '\0')
		word = 1;
	while (s[index] != '\0')
	{
		if (s[index] == c)
		{
			word++;
			index = ft_skip(s, index, c);
			if (s[index] == '\0')
			{
				word--;
				index--;
			}
		}
		index++;
	}
	return (word);
}

static char			*ft_array(char const *s, size_t i, size_t len)
{
	char			*t;
	size_t			index;

	index = 0;
	if (len == 0)
		return (0);
	t = malloc(sizeof(*s) * len + 1);
	if (t != 0)
	{
		while (index < len)
			t[index++] = s[i++];
		t[index] = '\0';
	}
	return (t);
}

static char			**ft_while_t(char c, char const *s, size_t num, \
									size_t index)
{
	char			**array;
	int				i;

	i = 0;
	if (!(array = malloc(sizeof(char *) * (word_count(s, c) + 1))))
		return (0);
	index = ft_skip(s, index, c);
	num = index;
	while (1)
	{
		if (s[index] == c || s[index] == '\0')
		{
			if (!(array[i] = ft_array(s, num, (index - num))))
				break ;
			i++;
			index = ft_skip(s, index, c);
			num = index;
		}
		if (s[index] == '\0')
			break ;
		index++;
	}
	array[i] = 0;
	return (array);
}

char				**ft_split(char const *s, char c)
{
	char			**array;
	int				i;

	i = 0;
	if (!s)
		return (0);
	array = ft_while_t(c, s, 0, 0);
	if (array == 0)
		return (0);
	while (array[i] != 0)
		i++;
	if (i != word_count(s, c))
	{
		while (i >= 0)
		{
			free(array[i]);
			i--;
		}
		free(array);
		return (0);
	}
	return (array);
}
