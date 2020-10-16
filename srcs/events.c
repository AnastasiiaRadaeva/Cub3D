/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatwoma <kbatwoma@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 15:31:45 by kbatwoma          #+#    #+#             */
/*   Updated: 2020/10/16 11:23:22 by kbatwoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	move(int key, t_vars *vars, double x, double y)
{
	if (key == W)
	{
		y -= sin(vars->map->a) * 10;
		x += cos(vars->map->a) * 10;
	}
	if (key == S)
	{
		y += sin(vars->map->a) * 10;
		x -= cos(vars->map->a) * 10;
	}
	if (key == D)
	{
		y -= sin(vars->map->a - (M_PI / 2)) * 10;
		x += cos(vars->map->a - (M_PI / 2)) * 10;
	}
	if (key == A)
	{
		y += sin(vars->map->a - (M_PI / 2)) * 10;
		x -= cos(vars->map->a - (M_PI / 2)) * 10;
	}
	if (vars->map->map[(int)(y / CUBE)][(int)(x / CUBE)] != '1')
	{
		vars->map->p_x = x;
		vars->map->p_y = y;
	}
}

static void	turn(int key, t_vars *vars)
{
	if (key == 123)
	{
		if (vars->map->a == 0)
			vars->map->a = 2 * M_PI;
		vars->map->a += 0.1;
	}
	if (key == 124)
	{
		if (vars->map->a == 2 * M_PI)
			vars->map->a = 0;
		vars->map->a -= 0.1;
	}
}

int			key_press(int key, t_vars *vars)
{
	if (key == W || key == S || key == D || key == A || key == 123\
										|| key == 124 || key == 53)
	{
		move(key, vars, vars->map->p_x, vars->map->p_y);
		turn(key, vars);
		if (key == 53)
		{
			free_vars(vars);
			exit(0);
		}
		if (vars->map->a < 0)
			vars->map->a += 2 * M_PI;
		else if (vars->map->a > 2 * M_PI)
			vars->map->a -= 2 * M_PI;
		render_next_frame(vars);
	}
	return (0);
}

int			close_press(t_vars *vars)
{
	if (!vars)
		return (0);
	free_vars(vars);
	exit(0);
}
