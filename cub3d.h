/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatwoma <kbatwoma@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 12:33:45 by kbatwoma          #+#    #+#             */
/*   Updated: 2020/10/14 17:02:22 by kbatwoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define CUBE 64
# define CUBE_2 32
# define M_2PI 6.28318530718
# define M_PI_6 0.52359877559
# define M_PI_3 1.0471975512
# define DIST_TO_PR vars->map->width / 1.15470053838

# define BYTES_PER_PIXEL 3
# define FILE_HEADER_SIZE 14
# define INFO_HEADER_SIZE 40

# define W 13
# define S 1
# define D 2
# define A 0

# define MAP_ERROR "Check your configuration file.\n"
# define ARGUMENTS_ERROR "Check your arguments.\n"
# define MALLOC_ERROR "Memory error.\n"
# define CANT_OPEN_TEXTURE "Check your textures.\n"
# define CANT_OPEN_MAP "Can't open configuration file.\n"

# include "libft/libft.h"
# include "minilibx_mms_20200219/mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>

typedef struct	s_parser
{
	int			width;
	int			height;
	int			flag;
	int			floor_color;
	int			ceiling_color;
	char		**map;
	int			size_x;
	double		p_x;
	double		p_y;
	double		a;
}				t_parser;

typedef struct	s_rays
{
	double		x_h;
	double		y_h;
	double		x_v;
	double		y_v;
	double		x_ray;
	double		y_ray;
	double		x_step;
	double		y_step;
	double		fov;
	double		distance;
	double		*array_distance;
}				t_rays;

typedef struct	s_data {
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_data;

typedef struct	s_north
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			width;
	int			height;
}				t_north;

typedef struct	s_south
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			width;
	int			height;
}				t_south;

typedef struct	s_west
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			width;
	int			height;
}				t_west;

typedef struct	s_east
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			width;
	int			height;
}				t_east;

typedef struct	s_info_spr
{
	double		x;
	double		y;
	double		distance;
	double		height;
	double		a;
}				t_info_spr;

typedef struct	s_sprite
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			width;
	int			height;
	int			number;
	double		image_per_sprite;
	double		offset;
	t_info_spr	**info;

}				t_sprite;

typedef struct	s_wall
{
	double		wall_top;
	double		wall_height;
	double		image_per_wall;
	double		offset;
	char		flag;
}				t_wall;

typedef struct	s_checker
{
	int			resolution;
	int			north;
	int			west;
	int			south;
	int			east;
	int			sprite;
	int			floor;
	int			ceiling;
}				t_checker;

typedef struct	s_vars {
	void		*mlx;
	void		*win;
	t_parser	*map;
	t_data		*img;
	t_rays		*rays;
	t_wall		*wall;
	t_north		*north;
	t_south		*south;
	t_west		*west;
	t_east		*east;
	t_sprite	*sprite;
	t_checker	*checker;
}				t_vars;

int				key_press(int key, t_vars *vars);
int				close_press(t_vars *vars);
void			free_vars(t_vars *vars);
void			make_game(t_vars **vars, char *file);
int				map_checker(t_parser *parser);
int				ft_parser(char **line, t_vars *vars, int index);
int				ft_arraylen(char **map);
int				ft_map(char *str, t_vars *vars);
int				field_of_view(t_vars *vars);
void			save_information(char *name, t_vars *vars);
void			make_screen(t_vars **vars, char *file);
void			draw_sprites(t_vars *vars);
t_vars			*create_structs(void);
void			image_texture(t_vars *vars, char *path, char flag);
void			get_color_for_pixel(t_vars *vars, int x, int y, int *color);
void			correct_sequence(int number, t_info_spr **info);
void			my_mlx_pixel_put(t_data *data, int x, int y, int color);
void			error(char *str, t_vars *vars);
int				ft_skip_number(char *str, int *count);
int				ft_skip(const char *str);
void			draw_line(t_vars *vars, int x);
int				ft_extension(char *str, const char *extension);
int				check_number(char *str, int *param);
void			add_array_distance(t_vars *vars);
int				init_sprite(t_vars **vars);
int				init_checker(t_vars **vars);
int				render_next_frame(t_vars *vars);
int				ft_color_add(char *str, int *count);

#endif
