/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatwoma <kbatwoma@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 16:48:02 by kbatwoma          #+#    #+#             */
/*   Updated: 2020/05/24 23:16:01 by kbatwoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_size(int n)
{
	int		count;
	int		copy;

	count = 1;
	if (n < 0)
	{
		count++;
		if (n == -2147483648)
		{
			count++;
			n = -147483648;
		}
		n = -n;
	}
	copy = n;
	while ((copy) > 9)
	{
		count++;
		copy = copy / 10;
	}
	return (count);
}

static int	ft_min(int n, char *array)
{
	int		i;

	i = 0;
	if (n < 0)
	{
		array[i] = '-';
		if (n == -2147483648)
		{
			i++;
			array[i] = '2';
			n = -147483648;
		}
		n = -n;
	}
	return (n);
}

char		*ft_itoa(int n)
{
	char	*array;
	int		size;

	size = ft_size(n);
	if (!(array = malloc(sizeof(*array) * (size + 1))))
		return (0);
	array[size] = '\0';
	size--;
	n = ft_min(n, array);
	while (n > 9)
	{
		array[size] = (n % 10) + '0';
		n = n / 10;
		size--;
	}
	array[size] = n + '0';
	return (array);
}
