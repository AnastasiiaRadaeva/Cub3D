/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatwoma <kbatwoma@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 14:22:45 by kbatwoma          #+#    #+#             */
/*   Updated: 2020/10/16 11:19:22 by kbatwoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int			check_number(char *str, int *param)
{
	int	number;

	number = 0;
	if (str[0] == '-')
		return (-1);
	while (str[number] >= '0' && str[number] <= '9')
		number++;
	if (number > 9)
		*param = 2147483640;
	else if ((*param = ft_atoi(str)) <= 0)
		return (-1);
	return (0);
}

void		add_array_distance(t_vars *vars)
{
	int	index;

	index = 0;
	if (!(vars->rays->array_distance = (double *)malloc(sizeof(double)\
														* vars->map->width)))
		error(MALLOC_ERROR, vars);
	while (index > vars->map->width)
		vars->rays->array_distance[index++] = 0;
}

static int	skip_number_add(int index, char *str)
{
	int	c;

	c = 0;
	if (str[index] == ',')
	{
		while (str[index] == ',')
		{
			c++;
			index++;
		}
		if (c != 1)
			return (-1);
		index += ft_skip(str + index);
		if (str[index] == '\0')
			return (-1);
	}
	return (index);
}

int			ft_skip_number(char *str, int *count)
{
	int	index;
	int	check;

	check = 0;
	index = ft_skip(str);
	while (str[index] >= '0' && str[index] <= '9')
	{
		check = 1;
		index++;
	}
	*count += check;
	index += ft_skip(str + index);
	if (str[index] != ',' && str[index] != '\0')
		return (-1);
	return (skip_number_add(index, str));
}
