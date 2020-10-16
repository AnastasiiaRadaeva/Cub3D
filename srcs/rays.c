/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatwoma <kbatwoma@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 15:31:45 by kbatwoma          #+#    #+#             */
/*   Updated: 2020/10/14 14:54:22 by kbatwoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int		ray_cast(t_vars *vars, double *x, double *y)
{
	int c;
	int d;
	int	v;

	c = ft_arraylen(vars->map->map);
	v = (int)(*y) / CUBE;
	if (v >= c || v < 0)
		return (-1);
	d = ft_strlen(vars->map->map[v]);
	while ((size_t)(*y) / CUBE < c && (*y) >= 0 && (size_t)(*x) / CUBE < d \
			&& (*x) >= 0 \
			&& vars->map->map[(int)((*y) / CUBE)][(int)((*x) / CUBE)] != '1')
	{
		d = ft_strlen(vars->map->map[(int)((*y) / CUBE)]);
		(*y) = (*y) + vars->rays->y_step;
		(*x) = (*x) + vars->rays->x_step;
	}
	return (0);
}

static double	horizontal_grid(t_vars *vars, double a)
{
	double distance;

	vars->rays->y_step = CUBE;
	if (a > 0 && a < M_PI)
	{
		vars->rays->y_h = (int)(vars->map->p_y / CUBE) * CUBE - 0.001;
		vars->rays->x_h = vars->map->p_x + \
							(vars->map->p_y - vars->rays->y_h) / tan(a);
		vars->rays->y_step = -vars->rays->y_step;
		vars->rays->x_step = CUBE / tan(a);
	}
	else if (a > M_PI && a < M_2PI)
	{
		vars->rays->y_h = (int)(vars->map->p_y / CUBE) * CUBE + CUBE;
		vars->rays->x_h = vars->map->p_x + \
							(vars->map->p_y - vars->rays->y_h) / tan(a);
		vars->rays->x_step = CUBE / (-tan(a));
	}
	else
		return (-1);
	if (ray_cast(vars, &vars->rays->x_h, &vars->rays->y_h) == -1)
		return (-1);
	distance = sqrt(pow(vars->map->p_y - vars->rays->y_h, 2) + \
			pow(vars->map->p_x - vars->rays->x_h, 2)) * cos(a - vars->map->a);
	return (distance);
}

static double	vertical_grid(t_vars *vars, double a)
{
	double distance;

	vars->rays->x_step = CUBE;
	if ((a >= 0 && a < M_PI_2) || (a > 3 * M_PI_2 && a <= M_2PI))
	{
		vars->rays->x_v = (int)(vars->map->p_x / CUBE) * CUBE + CUBE;
		vars->rays->y_v = vars->map->p_y + \
						(vars->map->p_x - vars->rays->x_v) * tan(a);
		vars->rays->y_step = CUBE * (-tan(a));
	}
	else if (a > M_PI_2 && a < 3 * M_PI_2)
	{
		vars->rays->x_v = (int)(vars->map->p_x / CUBE) * CUBE - 0.001;
		vars->rays->y_v = vars->map->p_y + \
						(vars->map->p_x - vars->rays->x_v) * tan(a);
		vars->rays->x_step = -vars->rays->x_step;
		vars->rays->y_step = CUBE * tan(a);
	}
	else
		return (-1);
	if (ray_cast(vars, &vars->rays->x_v, &vars->rays->y_v) == -1)
		return (-1);
	distance = sqrt(pow(vars->map->p_y - vars->rays->y_v, 2) + \
			pow(vars->map->p_x - vars->rays->x_v, 2)) * cos(a - vars->map->a);
	return (distance);
}

static void		coord_of_wall(t_vars *vars, double a, double d_h, double d_v)
{
	if ((d_h = horizontal_grid(vars, a)) == -1)
	{
		vars->rays->x_ray = vars->rays->x_v;
		vars->rays->y_ray = vars->rays->y_v;
		vars->rays->distance = vertical_grid(vars, a);
	}
	else if ((d_v = vertical_grid(vars, a)) == -1)
	{
		vars->rays->x_ray = vars->rays->x_h;
		vars->rays->y_ray = vars->rays->y_h;
		vars->rays->distance = d_h;
	}
	else if (d_h < d_v)
	{
		vars->rays->x_ray = vars->rays->x_h;
		vars->rays->y_ray = vars->rays->y_h;
		vars->rays->distance = d_h;
	}
	else
	{
		vars->rays->x_ray = vars->rays->x_v;
		vars->rays->y_ray = vars->rays->y_v;
		vars->rays->distance = d_v;
	}
}

int				field_of_view(t_vars *vars)
{
	double	fov_end;
	int		x;

	vars->rays->fov = vars->map->a + M_PI_6;
	fov_end = vars->map->a - M_PI_6;
	if (fov_end < 0)
		fov_end += M_2PI;
	x = 0;
	while (x < vars->map->width)
	{
		if (vars->rays->fov > M_2PI)
			vars->rays->fov -= M_2PI;
		else if (vars->rays->fov < 0)
			vars->rays->fov += M_2PI;
		coord_of_wall(vars, vars->rays->fov, 0, 0);
		vars->rays->array_distance[x] = vars->rays->distance;
		draw_line(vars, x);
		vars->rays->fov -= M_PI_3 / vars->map->width;
		x++;
	}
	draw_sprites(vars);
	return (0);
}
