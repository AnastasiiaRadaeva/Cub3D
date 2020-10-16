/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatwoma <kbatwoma@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 11:44:27 by kbatwoma          #+#    #+#             */
/*   Updated: 2020/10/14 14:17:22 by kbatwoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int		ft_symb(char symb)
{
	if (symb != '0' && symb != '1' && symb != '2' && symb != 'N' && \
		symb != 'W' && symb != 'E' && symb != 'S' && symb != ' ')
		return (-1);
	return (0);
}

static double	ft_angle(char symb)
{
	double	angle;

	if (symb == 'N')
		angle = M_PI_2;
	else if (symb == 'W')
		angle = M_PI;
	else if (symb == 'E')
		angle = 0;
	else if (symb == 'S')
		angle = 3 * M_PI_2;
	return (angle);
}

static int		check_symb(t_parser *parser, int *player, int i, int j)
{
	while ((parser->map)[i])
	{
		j = 0;
		while ((parser->map)[i][j])
		{
			if (ft_symb((parser->map)[i][j]) != 0)
				return (-1);
			if ((parser->map)[i][j] == 'N' || (parser->map)[i][j] == 'W' || \
				(parser->map)[i][j] == 'E' || (parser->map)[i][j] == 'S')
			{
				parser->p_x = CUBE_2 + j * CUBE;
				parser->p_y = CUBE_2 + i * CUBE;
				parser->a = ft_angle((parser->map)[i][j]);
				(*player)++;
			}
			j++;
		}
		i++;
	}
	return (0);
}

static int		check_close(t_parser *parser, int i, int j)
{
	while ((parser->map)[i])
	{
		j = 0;
		while ((parser->map)[i][j])
		{
			if ((parser->map)[i][j] != ' ' && (parser->map)[i][j] != '1')
			{
				if (i == 0 || i == (ft_arraylen(parser->map) - 1) || \
					(parser->map)[i][j + 1] == ' ' || \
					(parser->map)[i][j - 1] == ' ' || \
					(parser->map)[i - 1][j] == ' ' || \
					(parser->map)[i + 1][j] == ' ' || \
					(parser->map)[i + 1][j + 1] == ' ' || \
					(parser->map)[i + 1][j - 1] == ' ' || \
					(parser->map)[i - 1][j + 1] == ' ' || \
					(parser->map)[i - 1][j - 1] == ' ' || \
					(parser->map)[i][j + 1] == '\0' || j == 0)
					return (-1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int				map_checker(t_parser *parser)
{
	int	player;

	player = 0;
	if (check_symb(parser, &player, 0, 0) != 0)
		return (-1);
	if (check_close(parser, 0, 0) != 0)
		return (-1);
	if (player != 1)
		return (-1);
	return (0);
}
