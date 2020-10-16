/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_configuration_file.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatwoma <kbatwoma@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 16:36:45 by kbatwoma          #+#    #+#             */
/*   Updated: 2020/10/14 16:38:22 by kbatwoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	flags_checker(t_checker *checker)
{
	if (checker->resolution == 1 && checker->north == 1 && checker->west == 1\
		&& checker->south == 1 && checker->east == 1 && checker->sprite == 1\
		&& checker->ceiling == 1 && checker->floor == 1)
		return (0);
	return (-1);
}

static void	fill_map(t_vars *vars, int y)
{
	int		x;
	char	*new_str;

	while (vars->map->map[++y])
	{
		if (ft_strlen(vars->map->map[y]) < vars->map->size_x)
		{
			if ((new_str = ft_strdup(vars->map->map[y])) == 0)
				error(MALLOC_ERROR, vars);
			free(vars->map->map[y]);
			if (!(vars->map->map[y] = (char *)malloc(sizeof(char) *
												vars->map->size_x + 1)))
				error(MALLOC_ERROR, vars);
			x = ft_strlen(new_str);
			ft_strlcpy(vars->map->map[y], new_str, x + 1);
			while (x < vars->map->size_x)
			{
				vars->map->map[y][x] = ' ';
				x++;
			}
			vars->map->map[y][x] = '\0';
			free(new_str);
		}
	}
}

static int	ft_reader(int fd, t_vars *vars)
{
	char	*line;
	int		i;

	line = NULL;
	while ((i = get_next_line(fd, &line)) > 0)
	{
		if (ft_parser(&line, vars, ft_skip(line)) == -1)
			return (ft_free(&line, -1));
		free(line);
	}
	if (i == -1)
	{
		free(line);
		error(MALLOC_ERROR, NULL);
	}
	if (ft_parser(&line, vars, ft_skip(line)) != 9)
		return (ft_free(&line, -1));
	fill_map(vars, -1);
	if (map_checker(vars->map) != 0)
		return (ft_free(&line, -1));
	if (flags_checker(vars->checker) == -1)
		return (ft_free(&line, -1));
	return (ft_free(&line, 0));
}

void		save_information(char *name, t_vars *vars)
{
	int	fd;

	if ((fd = open(name, O_RDONLY)) < 0)
		error(CANT_OPEN_MAP, vars);
	if (ft_reader(fd, vars) == -1)
	{
		close(fd);
		error(MAP_ERROR, vars);
	}
	close(fd);
}
