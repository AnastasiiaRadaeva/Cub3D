/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatwoma <kbatwoma@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 16:00:45 by kbatwoma          #+#    #+#             */
/*   Updated: 2020/10/16 11:37:22 by kbatwoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	correct_sequence(int number, t_info_spr **info)
{
	t_info_spr	*temp;
	int			index;
	int			i;

	index = 0;
	while (index < number)
	{
		i = index + 1;
		while (i < number)
		{
			if (info[index]->distance < info[i]->distance)
			{
				temp = info[i];
				info[i] = info[index];
				info[index] = temp;
			}
			i++;
		}
		index++;
	}
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	error(char *str, t_vars *vars)
{
	if (vars)
		free_vars(vars);
	ft_putstr_fd("Error\n", 1);
	ft_putstr_fd(str, 1);
	exit(EXIT_FAILURE);
}

int		ft_skip(const char *str)
{
	int	index;

	index = 0;
	while (str[index] == 32)
		index++;
	return (index);
}

int		ft_color_add(char *str, int *count)
{
	int	index;
	int	add;
	int	r;
	int	g;
	int	b;

	if ((r = ft_atoi(str)) < 0 || r > 255)
		return (-1);
	if ((index = ft_skip_number(str, count)) == -1)
		return (-1);
	if ((g = ft_atoi(str + index)) < 0 || g > 255)
		return (-1);
	if ((add = ft_skip_number(str + index, count)) == -1)
		return (-1);
	index += add;
	if ((b = ft_atoi(str + index)) < 0 || b > 255)
		return (-1);
	if ((add = ft_skip_number(str + index, count)) == -1)
		return (-1);
	index += add;
	if (str[index] != '\0')
		return (-1);
	index = 0x00 << 24 | r << 16 | g << 8 | b;
	return (index);
}
