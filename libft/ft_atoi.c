/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatwoma <kbatwoma@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 16:57:05 by kbatwoma          #+#    #+#             */
/*   Updated: 2020/05/18 18:19:30 by kbatwoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(const char *str)
{
	int			index;
	long int	n;
	int			sign;

	index = 0;
	n = 0;
	sign = 1;
	while ((str[index] >= 9 && str[index] <= 13) || str[index] == 32)
		index++;
	if (str[index] == '-' || str[index] == '+')
	{
		sign = (44 - str[index]);
		index++;
	}
	while (str[index] >= '0' && str[index] <= '9')
	{
		if (sign == 1 && (n > (n * 10 + (str[index] - '0'))))
			return (-1);
		if (sign == -1 && (n * sign < ((n * 10 + (str[index] - '0')) * sign)))
			return (0);
		n = (n * 10 + (str[index] - '0'));
		index++;
	}
	n = n * sign;
	return (n);
}
