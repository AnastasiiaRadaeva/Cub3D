/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatwoma <kbatwoma@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 16:24:45 by kbatwoma          #+#    #+#             */
/*   Updated: 2020/10/14 16:27:22 by kbatwoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	free_map(t_parser *map)
{
	int y;

	y = 0;
	if (map->map)
	{
		while (map->map[y])
			free(map->map[y++]);
		free(map->map);
	}
	free(map);
}

static void	free_sprite(t_sprite *sprite)
{
	int	i;

	i = 0;
	while (i < sprite->number)
		free(sprite->info[i++]);
	if (sprite->info)
		free(sprite->info);
	free(sprite);
}

static void	free_rays(t_rays *rays)
{
	if (rays->array_distance)
		free(rays->array_distance);
	free(rays);
}

void		free_vars(t_vars *vars)
{
	if (vars->map)
		free_map(vars->map);
	if (vars->img)
		free(vars->img);
	if (vars->wall)
		free(vars->wall);
	if (vars->rays)
		free_rays(vars->rays);
	if (vars->north)
		free(vars->north);
	if (vars->south)
		free(vars->south);
	if (vars->west)
		free(vars->west);
	if (vars->east)
		free(vars->east);
	if (vars->sprite)
		free_sprite(vars->sprite);
	if (vars->checker)
		free(vars->checker);
	free(vars);
}
