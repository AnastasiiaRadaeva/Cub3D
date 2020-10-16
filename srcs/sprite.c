/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatwoma <kbatwoma@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 12:16:45 by kbatwoma          #+#    #+#             */
/*   Updated: 2020/10/16 11:11:22 by kbatwoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	draw_sprite_pixel(t_vars *vars, int x, int y, int c)
{
	int		color;
	int		j;
	double	pixel;

	j = vars->sprite->offset;
	pixel = vars->sprite->image_per_sprite;
	get_color_for_pixel(vars, j, (int)(c * pixel), &color);
	if (color < 0xe6e6e6)
		my_mlx_pixel_put(vars->img, x, y, color);
}

static void	texture_mapping(t_vars *vars, t_info_spr *info, int x, int y)
{
	int	i;
	int	x_end;
	int	y_text;
	int	x_text;

	x_end = x + (int)(info->height);
	x_text = 0;
	while (x < x_end)
	{
		i = y;
		y_text = 0;
		vars->sprite->offset = x_text * (vars->sprite->width / info->height);
		if ((x >= 0 && x < vars->map->width) && (info->distance * cos(info->a))\
								< vars->rays->array_distance[x])
			while (i < y + (int)(info->height))
			{
				if (i >= 0 && i < vars->map->height)
					draw_sprite_pixel(vars, x, i, y_text);
				i++;
				y_text++;
			}
		x++;
		x_text++;
	}
}

static void	draw_sprite(t_vars *vars, t_info_spr *info)
{
	double	sp_dir;
	int		h_offset;
	int		v_offset;
	double	a;

	sp_dir = atan2((vars->map->p_y - info->y), (info->x - vars->map->p_x));
	sp_dir = sp_dir >= 0 ? sp_dir : M_2PI + sp_dir;
	a = vars->map->a + (M_PI_6) - sp_dir;
	info->a = vars->map->a - sp_dir;
	while (info->a >= M_PI)
		info->a -= M_2PI;
	while (info->a <= -M_PI)
		info->a += M_2PI;
	while (a >= M_PI)
		a -= M_2PI;
	while (a <= -M_PI)
		a += M_2PI;
	info->height = (CUBE / info->distance) * DIST_TO_PR;
	h_offset = (int)(a / (M_PI / 3 / vars->map->width) - info->height / 2);
	v_offset = (int)(vars->map->height / 2 - info->height / 2);
	vars->sprite->image_per_sprite = vars->sprite->height / info->height;
	texture_mapping(vars, info, h_offset, v_offset);
}

static void	ft_distances(t_vars *vars, t_info_spr **info)
{
	int	index;

	index = 0;
	while (index < vars->sprite->number)
	{
		info[index]->distance = sqrt(pow(vars->map->p_y - info[index]->y, 2)\
									+ pow(vars->map->p_x - info[index]->x, 2));
		index++;
	}
}

void		draw_sprites(t_vars *vars)
{
	int			index;
	t_info_spr	**info;

	info = vars->sprite->info;
	ft_distances(vars, info);
	correct_sequence(vars->sprite->number, info);
	index = 0;
	vars->wall->flag = 'T';
	while (index < vars->sprite->number)
	{
		draw_sprite(vars, info[index]);
		index++;
	}
}
