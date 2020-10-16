/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatwoma <kbatwoma@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 15:31:45 by kbatwoma          #+#    #+#             */
/*   Updated: 2020/09/18 09:53:22 by kbatwoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	my_mlx_pixel_put(t_data *data, double x, double y, int color)
{
	char    *dst;

	dst = data->addr + ((int)y * data->line_length + (int)x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	ft_ray_cast(t_vars *vars, double angle)
{
	double c;
	double x;
	double y;
	double j;
	double i;

	c = 0;
	y = vars->map->y;
	x = vars->map->x;
	j = y;
	i = x;
	while (vars->map->map[(int)j][(int)i] != '1')
	{
		j = y + (c * sin(angle));
		i = x + (c * cos(angle));
		my_mlx_pixel_put(vars->img, i, j, 0xffffff);
		c++;
	}
}

void	ft_rays(t_vars	*vars, int color)
{
	double	fov_start;
	double	fov_end;
	double	p;

	p = 3.14159265;
	fov_start = vars->map->a - (p / 6);
	fov_end = vars->map->a + (p / 6);
	while (fov_start <= fov_end)
	{
		ft_ray_cast(vars, fov_start);
		fov_start += (p / 3) / vars->map->width;
	}
}

void	ft_drawer(t_vars *vars)
{
	int y;
	int x;

	vars->img->img = mlx_new_image(vars->mlx, vars->map->width, vars->map->height);
	vars->img->addr = mlx_get_data_addr(vars->img->img, &(vars->img->bits_per_pixel), &(vars->img->line_length), &(vars->img->endian));
	y = 0;
	while (vars->map->map[y])
	{
		x = 0;
		while (vars->map->map[y][x])
		{
			if (vars->map->map[y][x] == '1')
				my_mlx_pixel_put(vars->img, x, y, vars->map->ceilling_color);
			if (vars->map->map[y][x] == '2')
				my_mlx_pixel_put(vars->img, x, y, vars->map->floor_color);
			x++;
		}
		y++;
	}
	my_mlx_pixel_put(vars->img, vars->map->x, vars->map->y, 0x34b399);
	ft_rays(vars, 0xffffff);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img->img, 0, 0);
}

