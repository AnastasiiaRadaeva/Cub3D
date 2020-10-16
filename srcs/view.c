/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatwoma <kbatwoma@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 15:31:45 by kbatwoma          #+#    #+#             */
/*   Updated: 2020/10/14 16:23:22 by kbatwoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	ceiling_floor(t_vars *vars, int x)
{
	int	start;

	start = 0;
	while (start < vars->wall->wall_top)
	{
		my_mlx_pixel_put(vars->img, x, start, vars->map->ceiling_color);
		start++;
	}
	start = (int)(vars->wall->wall_top + vars->wall->wall_height);
	while (start < vars->map->height)
	{
		my_mlx_pixel_put(vars->img, x, start, vars->map->floor_color);
		start++;
	}
}

static void	draw_wall_pixel(t_vars *vars, int x, int y, int c)
{
	int		color;
	int		j;
	double	pixel;

	j = (int)vars->wall->offset;
	pixel = vars->wall->image_per_wall;
	get_color_for_pixel(vars, j, (int)(c * pixel), &color);
	my_mlx_pixel_put(vars->img, x, y, color);
}

static void	west_east_text(t_vars *vars)
{
	double	image_per_wall;
	double	offset;

	if (vars->rays->fov >= M_PI_2 && vars->rays->fov < 3 * M_PI_2)
	{
		vars->wall->flag = 'W';
		image_per_wall = vars->west->height / vars->wall->wall_height;
		offset = fmod(vars->rays->y_ray, CUBE) * vars->west->width / CUBE;
	}
	else
	{
		vars->wall->flag = 'E';
		image_per_wall = vars->east->height / vars->wall->wall_height;
		offset = fmod(vars->rays->y_ray, CUBE) * vars->east->width / CUBE;
	}
	vars->wall->offset = offset;
	vars->wall->image_per_wall = image_per_wall;
}

static void	north_south_text(t_vars *vars)
{
	double	image_per_wall;
	double	offset;

	if (vars->rays->fov >= 0 && vars->rays->fov < M_PI)
	{
		vars->wall->flag = 'N';
		image_per_wall = vars->north->height / vars->wall->wall_height;
		offset = fmod(vars->rays->x_ray, CUBE) * vars->north->width / CUBE;
	}
	else
	{
		vars->wall->flag = 'S';
		image_per_wall = vars->south->height / vars->wall->wall_height;
		offset = fmod(vars->rays->x_ray, CUBE) * vars->south->width / CUBE;
	}
	vars->wall->offset = offset;
	vars->wall->image_per_wall = image_per_wall;
}

void		draw_line(t_vars *vars, int x)
{
	int		c;
	int		b;
	int		c_for_text;
	int		j;

	vars->wall->wall_height = (CUBE / vars->rays->distance) * DIST_TO_PR;
	vars->wall->wall_top = vars->map->height / 2 - vars->wall->wall_height / 2;
	b = (int)(vars->wall->wall_top + vars->wall->wall_height);
	c = (int)vars->wall->wall_top;
	if (vars->wall->wall_height < vars->map->height)
		ceiling_floor(vars, x);
	if ((vars->rays->y_ray == vars->rays->y_v) && \
			(vars->rays->y_ray == vars->rays->y_v))
		west_east_text(vars);
	else
		north_south_text(vars);
	c_for_text = 0;
	while (c < b)
	{
		if (c >= 0 && c < vars->map->height)
			draw_wall_pixel(vars, x, c, c_for_text);
		c++;
		c_for_text++;
	}
}
