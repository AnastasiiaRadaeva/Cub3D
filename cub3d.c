/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatwoma <kbatwoma@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 13:04:45 by kbatwoma          #+#    #+#             */
/*   Updated: 2020/10/14 16:59:22 by kbatwoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_extension(char *str, const char *extension)
{
	int	len;
	int	i;

	i = 3;
	len = ft_strlen(str) - 1;
	while (len >= 0 && i >= 0)
	{
		if (str[len] != extension[i])
			return (-1);
		len--;
		i--;
	}
	return (0);
}

int	main(int count, char *arg[])
{
	t_vars	*vars;

	if (count == 3 || count == 2)
	{
		if (count == 2 && ft_extension(arg[1], ".cub") == 0)
			make_game(&vars, arg[1]);
		else if (count == 3)
		{
			if (ft_strncmp("--save", arg[2], ft_strlen(arg[2])) == 0\
								&& ft_strncmp("--save", arg[2], 7) == 0\
							&& ft_extension(arg[1], ".cub") == 0)
				make_screen(&vars, arg[1]);
			else if (ft_strncmp("--save", arg[1], ft_strlen(arg[1])) == 0\
									&& ft_strncmp("--save", arg[1], 7) == 0\
							&& ft_extension(arg[2], ".cub") == 0)
				make_screen(&vars, arg[2]);
		}
	}
	error(ARGUMENTS_ERROR, NULL);
}
