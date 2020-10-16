/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatwoma <kbatwoma@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 11:39:27 by kbatwoma          #+#    #+#             */
/*   Updated: 2020/10/14 16:58:22 by kbatwoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int			ft_arraylen(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

static void	add_new_sprite(int number, t_vars *vars, t_info_spr *new_sprite)
{
	t_info_spr	**temp;

	temp = vars->sprite->info;
	if (!(vars->sprite->info = (t_info_spr **)malloc(sizeof(t_info_spr *)\
															* (number + 1))))
		error(MALLOC_ERROR, vars);
	while (number > 0)
	{
		vars->sprite->info[number - 1] = temp[number - 1];
		number--;
	}
	vars->sprite->info[vars->sprite->number] = new_sprite;
	free(temp);
}

static int	add_sprite(int x, int y, t_vars *vars)
{
	t_info_spr	*new_sprite;
	int			number;

	if (!(new_sprite = (t_info_spr *)malloc(sizeof(t_info_spr))))
		error(MALLOC_ERROR, vars);
	new_sprite->x = 32 + x * CUBE;
	new_sprite->y = 32 + y * CUBE;
	new_sprite->distance = 0;
	new_sprite->height = 0;
	new_sprite->a = 0;
	number = vars->sprite->number;
	if (number == 0)
	{
		if (!(vars->sprite->info = (t_info_spr **)malloc(sizeof(t_info_spr *))))
			error(MALLOC_ERROR, vars);
		vars->sprite->info[0] = new_sprite;
	}
	else
		add_new_sprite(number, vars, new_sprite);
	vars->sprite->number++;
	return (0);
}

static char	**ft_add_map_sprite(char *str, char **map, int i, t_vars *vars)
{
	char		**new_map;
	int			j;

	if (!(new_map = malloc(sizeof(char *) * (ft_arraylen(map) + 2))))
		error(MALLOC_ERROR, vars);
	while (map[++i])
		new_map[i] = map[i];
	j = 0;
	if (!(new_map[i] = malloc(sizeof(char) * (ft_strlen(str) + 1))))
		error(MALLOC_ERROR, vars);
	while (str[j])
	{
		new_map[i][j] = str[j];
		if (new_map[i][j] == '2')
			if (add_sprite(j, i, vars) == -1)
				return (NULL);
		j++;
	}
	new_map[i][j] = '\0';
	new_map[++i] = NULL;
	vars->map->size_x = vars->map->size_x > j ? vars->map->size_x : j;
	return (new_map);
}

int			ft_map(char *str, t_vars *vars)
{
	static char	**strings;
	char		**temp_str;

	if (!strings)
	{
		if (!(strings = malloc(sizeof(char *) * 1)))
			error(MALLOC_ERROR, vars);
		strings[0] = NULL;
	}
	temp_str = strings;
	if (!(strings = ft_add_map_sprite(str, strings, -1, vars)))
		return (-1);
	free(temp_str);
	vars->map->map = strings;
	return (0);
}
