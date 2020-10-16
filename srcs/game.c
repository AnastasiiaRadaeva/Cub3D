/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatwoma <kbatwoma@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 16:29:45 by kbatwoma          #+#    #+#             */
/*   Updated: 2020/10/16 11:10:22 by kbatwoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		render_next_frame(t_vars *vars)
{
	field_of_view(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img->img, 0, 0);
	mlx_do_sync(vars->mlx);
	return (0);
}

void	make_game(t_vars **vars, char *file)
{
	if (((*vars) = create_structs()) == NULL)
		error(MALLOC_ERROR, NULL);
	if (((*vars)->mlx = mlx_init()) == NULL)
		error(MALLOC_ERROR, (*vars));
	save_information(file, (*vars));
	(*vars)->img->img = mlx_new_image((*vars)->mlx, (*vars)->map->width,\
													(*vars)->map->height);
	(*vars)->img->addr = mlx_get_data_addr((*vars)->img->img,\
											&((*vars)->img->bits_per_pixel),\
											&((*vars)->img->line_length),\
											&((*vars)->img->endian));
	if (((*vars)->win = mlx_new_window((*vars)->mlx, (*vars)->map->width,\
		(*vars)->map->height, "Hello world!")) == NULL)
		error(MALLOC_ERROR, (*vars));
	render_next_frame(*vars);
	mlx_hook((*vars)->win, 2, 1L << 0, key_press, (*vars));
	mlx_hook((*vars)->win, 17, 0, close_press, (*vars));
	mlx_loop((*vars)->mlx);
}
