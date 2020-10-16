/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatwoma <kbatwoma@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 12:33:45 by kbatwoma          #+#    #+#             */
/*   Updated: 2020/10/14 16:20:22 by kbatwoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	texture_north_south(t_vars *vars, char *path, char flag)
{
	if (flag == 'N')
	{
		vars->checker->north += 1;
		if (!(vars->north->img = mlx_xpm_file_to_image(vars->mlx, path, \
									&vars->north->width, &vars->north->height)))
			error(CANT_OPEN_TEXTURE, vars);
		vars->north->addr = mlx_get_data_addr(vars->north->img, \
											&vars->north->bits_per_pixel, \
							&vars->north->line_length, &vars->north->endian);
	}
	if (flag == 'S')
	{
		vars->checker->south += 1;
		if (!(vars->south->img = mlx_xpm_file_to_image(vars->mlx, path, \
									&vars->south->width, &vars->south->height)))
			error(CANT_OPEN_TEXTURE, vars);
		vars->south->addr = mlx_get_data_addr(vars->south->img, \
												&vars->south->bits_per_pixel, \
							&vars->south->line_length, &vars->south->endian);
	}
}

static void	texture_west_east(t_vars *vars, char *path, char flag)
{
	if (flag == 'W')
	{
		vars->checker->west += 1;
		if (!(vars->west->img = mlx_xpm_file_to_image(vars->mlx, path, \
									&vars->west->width, &vars->west->height)))
			error(CANT_OPEN_TEXTURE, vars);
		vars->west->addr = mlx_get_data_addr(vars->west->img, \
												&vars->west->bits_per_pixel, \
								&vars->west->line_length, &vars->west->endian);
	}
	if (flag == 'E')
	{
		vars->checker->east += 1;
		if (!(vars->east->img = mlx_xpm_file_to_image(vars->mlx, path, \
									&vars->east->width, &vars->east->height)))
			error(CANT_OPEN_TEXTURE, vars);
		vars->east->addr = mlx_get_data_addr(vars->east->img, \
												&vars->east->bits_per_pixel, \
								&vars->east->line_length, &vars->east->endian);
	}
}

void		image_texture(t_vars *vars, char *path, char flag)
{
	texture_north_south(vars, path, flag);
	texture_west_east(vars, path, flag);
	if (flag == 'T')
	{
		vars->checker->sprite += 1;
		if (!(vars->sprite->img = mlx_xpm_file_to_image(vars->mlx, path, \
								&vars->sprite->width, &vars->sprite->height)))
			error(CANT_OPEN_TEXTURE, vars);
		vars->sprite->addr = mlx_get_data_addr(vars->sprite->img, \
												&vars->sprite->bits_per_pixel, \
							&vars->sprite->line_length, &vars->sprite->endian);
	}
}

void		get_color_for_pixel(t_vars *vars, int x, int y, int *color)
{
	char	*dst;

	if (vars->wall->flag == 'N')
		dst = vars->north->addr + (y * vars->north->line_length + x * \
											(vars->north->bits_per_pixel / 8));
	if (vars->wall->flag == 'S')
		dst = vars->south->addr + (y * vars->south->line_length + x * \
											(vars->south->bits_per_pixel / 8));
	if (vars->wall->flag == 'W')
		dst = vars->west->addr + (y * vars->west->line_length + x * \
											(vars->west->bits_per_pixel / 8));
	if (vars->wall->flag == 'E')
		dst = vars->east->addr + (y * vars->east->line_length + x * \
											(vars->east->bits_per_pixel / 8));
	if (vars->wall->flag == 'T')
		dst = vars->sprite->addr + (y * vars->sprite->line_length + x * \
											(vars->sprite->bits_per_pixel / 8));
	*color = *(unsigned int *)dst;
}
