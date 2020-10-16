/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatwoma <kbatwoma@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 12:49:45 by kbatwoma          #+#    #+#             */
/*   Updated: 2020/10/16 11:36:22 by kbatwoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	ft_resolution(char *str, t_vars *vars)
{
	int	index;
	int	w;
	int	h;

	index = ft_skip(str);
	if (check_number(str + index, &vars->map->width) == -1)
		return (-1);
	while (str[index] >= '0' && str[index] <= '9')
		index++;
	index += ft_skip(str);
	if (check_number(str + index, &vars->map->height) == -1)
		return (-1);
	while (str[index] >= '0' && str[index] <= '9')
		index++;
	if (str[index] != '\0')
		return (-1);
	if (vars->map->flag == 0)
	{
		mlx_get_screen_size(vars->mlx, &w, &h);
		vars->map->width = vars->map->width > w ? w : vars->map->width;
		vars->map->height = vars->map->height > h ? h : vars->map->height;
	}
	add_array_distance(vars);
	vars->checker->resolution += 1;
	return (0);
}

static int	ft_texture(char symb, char *str, t_vars *vars)
{
	char	*path;
	int		fd;

	str += ft_skip(str);
	if ((path = ft_strdup(str)) == 0)
		error(MALLOC_ERROR, vars);
	if (ft_extension(path, ".png") == -1 && ft_extension(path, ".xpm") == -1)
		return (-1);
	if ((fd = open(path, O_RDONLY)) < 0)
	{
		free(path);
		error(CANT_OPEN_TEXTURE, vars);
	}
	close(fd);
	image_texture(vars, path, symb);
	free(path);
	return (0);
}

static int	ft_color(char symb, char *str, t_vars *vars, int count)
{
	int		index;

	if ((index = ft_color_add(str, &count)) == -1)
		return (-1);
	if (symb == 'F')
	{
		vars->checker->floor += 1;
		vars->map->floor_color = index;
	}
	else if (symb == 'C')
	{
		vars->checker->ceiling += 1;
		vars->map->ceiling_color = index;
	}
	return (0);
}

static int	ft_flags(char **line, t_vars *vars)
{
	if ((*line)[0] == 'R')
	{
		if (ft_resolution(((*line) + 1), vars) != 0)
			return (-1);
	}
	else if ((((*line)[0] == 'N' || (*line)[0] == 'S') && (*line)[1] == 'O')\
				|| ((*line)[0] == 'W' && (*line)[1] == 'E') \
				|| ((*line)[0] == 'E' && (*line)[1] == 'A'))
	{
		if (ft_texture((*line)[0], ((*line) + 2), vars) != 0)
			return (-1);
	}
	else if ((*line)[0] == 'S' && ((*line)[1] == ' ' || (*line)[0] == '.'))
	{
		if (ft_texture('T', ((*line) + 1), vars) != 0)
			return (-1);
	}
	else if ((*line)[0] == 'F' || (*line)[0] == 'C')
	{
		if (ft_color((*line)[0], ((*line) + 1), vars, 0) != 0)
			return (-1);
	}
	else
		return (-1);
	return (0);
}

int			ft_parser(char **line, t_vars *vars, int index)
{
	static int	flag;
	static int	count_vars;

	if (index == 0 && (*line)[0] != '1' && ft_strlen(*line) && flag != 1)
	{
		flag = 0;
		count_vars += 1;
		if (ft_flags(line, vars) == -1)
			return (-1);
	}
	else if (index >= 0 && (*line)[index] == '1')
	{
		if (flag != 1)
			count_vars += 1;
		flag = 1;
		if (ft_map((*line), vars) != 0)
			return (-1);
	}
	else if (*line[0] == '\0' && flag == 1)
		return (-1);
	else if (*line[0] == '\0' && flag == 0)
		return (count_vars);
	else
		return (-1);
	return (count_vars);
}
