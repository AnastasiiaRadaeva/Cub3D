/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatwoma <kbatwoma@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 12:33:45 by kbatwoma          #+#    #+#             */
/*   Updated: 2020/10/14 16:05:22 by kbatwoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	init_parser(t_vars **vars)
{
	if (!((*vars)->map = (t_parser *)malloc(sizeof(t_parser))))
		return (-1);
	(*vars)->map->map = NULL;
	(*vars)->map->height = 0;
	(*vars)->map->width = 0;
	(*vars)->map->flag = 0;
	(*vars)->map->size_x = 0;
	(*vars)->map->p_y = 0;
	(*vars)->map->p_x = 0;
	(*vars)->map->a = 0;
	(*vars)->map->floor_color = 0;
	(*vars)->map->ceiling_color = 0;
	return (0);
}

static int	init_img_rays_wall(t_vars **vars)
{
	if (!((*vars)->img = (t_data *)malloc(sizeof(t_data))))
		return (-1);
	(*vars)->img->addr = NULL;
	(*vars)->img->img = NULL;
	(*vars)->img->line_length = 0;
	(*vars)->img->bits_per_pixel = 0;
	(*vars)->img->endian = 0;
	if (!((*vars)->rays = (t_rays *)malloc(sizeof(t_rays))))
		return (-1);
	(*vars)->rays->fov = 0;
	(*vars)->rays->y_v = 0;
	(*vars)->rays->x_v = 0;
	(*vars)->rays->y_h = 0;
	(*vars)->rays->x_h = 0;
	(*vars)->rays->y_ray = 0;
	(*vars)->rays->x_ray = 0;
	(*vars)->rays->distance = 0;
	(*vars)->rays->array_distance = NULL;
	if (!((*vars)->wall = (t_wall *)malloc(sizeof(t_wall))))
		return (-1);
	(*vars)->wall->wall_height = 0;
	(*vars)->wall->wall_top = 0;
	(*vars)->wall->image_per_wall = 0;
	(*vars)->wall->offset = 0;
	return (0);
}

static int	init_north_south(t_vars **vars)
{
	if (!((*vars)->north = (t_north *)malloc(sizeof(t_north))))
		return (-1);
	(*vars)->north->img = NULL;
	(*vars)->north->addr = NULL;
	(*vars)->north->bits_per_pixel = 0;
	(*vars)->north->line_length = 0;
	(*vars)->north->width = 0;
	(*vars)->north->height = 0;
	(*vars)->north->endian = 0;
	if (!((*vars)->south = (t_south *)malloc(sizeof(t_south))))
		return (-1);
	(*vars)->south->img = NULL;
	(*vars)->south->addr = NULL;
	(*vars)->south->bits_per_pixel = 0;
	(*vars)->south->line_length = 0;
	(*vars)->south->width = 0;
	(*vars)->south->height = 0;
	(*vars)->south->endian = 0;
	return (0);
}

static int	init_west_east(t_vars **vars)
{
	if (!((*vars)->west = (t_west *)malloc(sizeof(t_west))))
		return (-1);
	(*vars)->west->img = NULL;
	(*vars)->west->addr = NULL;
	(*vars)->west->bits_per_pixel = 0;
	(*vars)->west->line_length = 0;
	(*vars)->west->width = 0;
	(*vars)->west->height = 0;
	(*vars)->west->endian = 0;
	if (!((*vars)->east = (t_east *)malloc(sizeof(t_east))))
		return (-1);
	(*vars)->east->img = NULL;
	(*vars)->east->addr = NULL;
	(*vars)->east->bits_per_pixel = 0;
	(*vars)->east->line_length = 0;
	(*vars)->east->width = 0;
	(*vars)->east->height = 0;
	(*vars)->east->endian = 0;
	return (0);
}

t_vars		*create_structs(void)
{
	t_vars	*vars;

	if (!(vars = (t_vars *)malloc(sizeof(t_vars))))
		error(MALLOC_ERROR, NULL);
	vars->mlx = NULL;
	vars->win = NULL;
	if (init_parser(&vars) == -1 || init_img_rays_wall(&vars) == -1 ||\
		init_north_south(&vars) == -1 || init_west_east(&vars) == -1 \
		|| init_sprite(&vars) == -1 || init_checker(&vars) == -1)
		error(MALLOC_ERROR, vars);
	vars->rays->x_step = 0;
	vars->rays->y_step = 0;
	return (vars);
}
