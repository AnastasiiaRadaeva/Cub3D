/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatwoma <kbatwoma@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 12:33:45 by kbatwoma          #+#    #+#             */
/*   Updated: 2020/10/14 16:05:22 by kbatwoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	init_sprite(t_vars **vars)
{
	if (!((*vars)->sprite = (t_sprite *)malloc(sizeof(t_sprite))))
		return (-1);
	(*vars)->sprite->img = NULL;
	(*vars)->sprite->addr = NULL;
	(*vars)->sprite->bits_per_pixel = 0;
	(*vars)->sprite->line_length = 0;
	(*vars)->sprite->width = 0;
	(*vars)->sprite->height = 0;
	(*vars)->sprite->endian = 0;
	(*vars)->sprite->number = 0;
	(*vars)->sprite->image_per_sprite = 0;
	(*vars)->sprite->offset = 0;
	(*vars)->sprite->info = NULL;
	return (0);
}

int	init_checker(t_vars **vars)
{
	if (!((*vars)->checker = (t_checker *)malloc(sizeof(t_checker))))
		return (-1);
	(*vars)->checker->resolution = 0;
	(*vars)->checker->north = 0;
	(*vars)->checker->west = 0;
	(*vars)->checker->south = 0;
	(*vars)->checker->east = 0;
	(*vars)->checker->sprite = 0;
	(*vars)->checker->floor = 0;
	(*vars)->checker->ceiling = 0;
	return (0);
}
