/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
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
//
//void	ft_ray_cast(t_vars *vars, double angle)
//{
//	double c;
//	double x;
//	double y;
//	double j;
//	double i;
//
//	c = 0;
//	y = vars->map->y;
//	x = vars->map->x;
//	j = y;
//	i = x;
//
//	while (vars->map->map[(int)j][(int)i] != '1')
//	{
//		j = y + (c * sin(angle));
//		i = x + (c * cos(angle));
//		c ++;
//	}
//	vars->map->x_ray = i;
//	vars->map->y_ray = j;
//}

void	ft_line(int x, int y, int len, t_vars *vars, int color)
{
	int	ceilling;
	int	floor;

	printf("Hello\n");
	ceilling = y - (len / 2);
	floor = y + (len / 2);
	printf("Hello_1\n");
	printf("ceiling: %i, floor: %i\n", ceilling, floor);
	while (ceilling <= floor)
	{
		my_mlx_pixel_put(vars->img, x, ceilling, color);
		ceilling++;
	}
	printf("Hello_2\n");
}

void	ft_rays(t_vars	*vars, int color)
{
	double	fov_start;
	double	fov_end;
	double	p;
	int		x;
	double distance;
	int len;

	p = 3.14159265;
	x = 0;
	fov_start = vars->map->a - (p / 6);
	fov_end = vars->map->a + (p / 6);
	while (fov_start <= fov_end)
	{
		ft_ray_cast(vars, fov_start);
		distance = sqrt(pow((vars->map->x_ray - vars->map->x), 2) + pow((vars->map->y_ray - vars->map->y), 2)) * cos(vars->map->a - fov_start);
//		distance = abs((int)((vars->map->x_ray - vars->map->x) / cos(vars->map->a - fov_start))) * abs((int)cos(vars->map->a - fov_start));
		len = vars->map->height - (int)(100 * distance);
		ft_line(x, (vars->map->height / 2), len, vars, 0xffffff);
		fov_start += (p / 3) / vars->map->width;
		x++;
	}
}

void	ft_drawer(t_vars *vars)
{
	vars->img->img = mlx_new_image(vars->mlx, vars->map->width, vars->map->height);
	vars->img->addr = mlx_get_data_addr(vars->img->img, &(vars->img->bits_per_pixel), &(vars->img->line_length), &(vars->img->endian));
	ft_rays(vars, 0xffffff);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img->img, 0, 0);
}

