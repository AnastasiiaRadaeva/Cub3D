/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screenshot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatwoma <kbatwoma@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 18:36:45 by kbatwoma          #+#    #+#             */
/*   Updated: 2020/10/15 12:13:22 by kbatwoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static unsigned char	*cr_file_header(int height, int stride)
{
	int				file_size;
	int				i;
	unsigned char	*f_header;

	file_size = FILE_HEADER_SIZE + INFO_HEADER_SIZE + (stride * height);
	i = 13;
	if (!(f_header = (unsigned char *)malloc(sizeof(unsigned char) * 14)))
		return (NULL);
	while (i >= 0)
	{
		f_header[i] = 0;
		i--;
	}
	f_header[14] = '\0';
	f_header[0] = (unsigned char)('B');
	f_header[1] = (unsigned char)('M');
	f_header[2] = (unsigned char)(file_size);
	f_header[3] = (unsigned char)(file_size >> 8);
	f_header[4] = (unsigned char)(file_size >> 16);
	f_header[5] = (unsigned char)(file_size >> 24);
	f_header[10] = (unsigned char)(FILE_HEADER_SIZE + INFO_HEADER_SIZE);
	return (f_header);
}

static unsigned char	*cr_info_header(int height, int width)
{
	unsigned char	*i_header;
	int				i;

	i = 39;
	if (!(i_header = (unsigned char *)malloc(sizeof(unsigned char) * 40)))
		return (NULL);
	while (i >= 0)
	{
		i_header[i] = 0;
		i--;
	}
	i_header[40] = '\0';
	i_header[0] = (unsigned char)(INFO_HEADER_SIZE);
	i_header[4] = (unsigned char)(width);
	i_header[5] = (unsigned char)(width >> 8);
	i_header[6] = (unsigned char)(width >> 16);
	i_header[7] = (unsigned char)(width >> 24);
	i_header[8] = (unsigned char)(height);
	i_header[9] = (unsigned char)(height >> 8);
	i_header[10] = (unsigned char)(height >> 16);
	i_header[11] = (unsigned char)(height >> 24);
	i_header[12] = (unsigned char)(1);
	i_header[14] = (unsigned char)(24);
	return (i_header);
}

static void				pixel_data(t_vars *vars, int fd, int padding_size)
{
	unsigned char	rgb[3];
	int				i;
	int				j;
	int				max_x;
	int				max_y;

	i = 0;
	max_y = vars->map->height - 1;
	while (i < max_y)
	{
		max_x = vars->map->width;
		j = -1;
		while (++j < max_x)
		{
			rgb[0] = vars->img->addr[(max_y * vars->img->line_length +
							j * (vars->img->bits_per_pixel / 8))];
			rgb[1] = vars->img->addr[(max_y * vars->img->line_length +
							j * (vars->img->bits_per_pixel / 8)) + 1];
			rgb[2] = vars->img->addr[(max_y * vars->img->line_length +
							j * (vars->img->bits_per_pixel / 8)) + 2];
			write(fd, rgb, 3);
		}
		write(fd, "0", padding_size);
		max_y--;
	}
}

static void				screenshot(t_vars *vars)
{
	int				fd;
	unsigned char	*file_header;
	unsigned char	*info_header;
	int				width_in_bytes;
	int				padding_size;

	width_in_bytes = vars->map->width * BYTES_PER_PIXEL;
	padding_size = (4 - (width_in_bytes % 4)) % 4;
	if ((fd = open("cub3D.bmp", O_CREAT | O_RDWR, 416)) < 0)
		error(MALLOC_ERROR, vars);
	if (!(file_header = cr_file_header(vars->map->height - 1,
									width_in_bytes + padding_size)))
		error(MALLOC_ERROR, vars);
	if (!(info_header = cr_info_header(vars->map->height - 1,
								vars->map->width)))
		error(MALLOC_ERROR, vars);
	write(fd, file_header, FILE_HEADER_SIZE);
	write(fd, info_header, INFO_HEADER_SIZE);
	free(file_header);
	free(info_header);
	pixel_data(vars, fd, padding_size);
	close(fd);
}

void					make_screen(t_vars **vars, char *file)
{
	if (((*vars) = create_structs()) == NULL)
		error(MALLOC_ERROR, NULL);
	if (((*vars)->mlx = mlx_init()) == NULL)
		error(MALLOC_ERROR, (*vars));
	(*vars)->map->flag = 1;
	save_information(file, (*vars));
	(*vars)->img->img = mlx_new_image((*vars)->mlx, (*vars)->map->width,
								(*vars)->map->height);
	(*vars)->img->addr = mlx_get_data_addr((*vars)->img->img,
										&((*vars)->img->bits_per_pixel),
						&((*vars)->img->line_length), &((*vars)->img->endian));
	field_of_view(*vars);
	screenshot((*vars));
	free_vars((*vars));
	ft_putstr_fd("Image is created!\n", 1);
	exit(0);
}
