/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatwoma <kbatwoma@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 09:34:57 by kbatwoma          #+#    #+#             */
/*   Updated: 2020/07/21 09:24:20 by kbatwoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_ifn(char **rest, size_t index, char **line, char **last_line)
{
	(*rest)[index++] = '\0';
	if ((*line = ft_strjoin(*line, *rest)) == 0)
		return (ft_free(last_line, -1));
	ft_free(last_line, 0);
	if ((*rest)[index] != '\0')
	{
		*last_line = *rest;
		if ((*rest = ft_strdup(*rest + index)) == 0)
			return (ft_free(last_line, -1));
		ft_free(last_line, 0);
	}
	else
		ft_free(rest, 0);
	return (1);
}

static ssize_t	ft_check_new_line(char *buff, char **rest, char **line)
{
	size_t	index;
	char	*last_line;

	index = 0;
	last_line = *line;
	while (buff[index] != '\0' && buff[index] != '\n')
		index++;
	if (buff[index] == '\n')
	{
		buff[index] = '\0';
		if ((*line = ft_strjoin(*line, buff)) == 0)
			return (ft_free(&last_line, -1));
		ft_free(&last_line, 0);
		if (buff[++index] != '\0')
			if ((*rest = ft_strdup(buff + index)) == 0)
				return (-1);
		return (1);
	}
	if ((*line = ft_strjoin(*line, buff)) == 0)
		return (ft_free(&last_line, -1));
	return (ft_free(&last_line, 0));
}

static ssize_t	ft_read(int fd, char *buff, char **rest, char **line)
{
	ssize_t	num_symb;
	ssize_t	check_new_line;

	while ((num_symb = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[num_symb] = '\0';
		if ((check_new_line = ft_check_new_line(buff, rest, line)) == 1)
			return (ft_free(&buff, 1));
		else if (check_new_line == -1)
			return (ft_free(&buff, -1));
	}
	if (num_symb == 0)
		return (ft_free(&buff, 0));
	return (ft_free(&buff, -1));
}

static ssize_t	ft_rest(char **rest, char **line)
{
	size_t	index;
	char	*last_line;

	index = 0;
	last_line = *line;
	while ((*rest)[index] != '\0' && (*rest)[index] != '\n')
		index++;
	if ((*rest)[index] == '\n')
		return (ft_ifn(rest, index, line, &last_line));
	if ((*line = ft_strjoin(*line, *rest)) == 0)
		return (ft_free(&last_line, -1));
	ft_free(rest, 0);
	return (ft_free(&last_line, 0));
}

int				get_next_line(int fd, char **line)
{
	char		*buff;
	static char	*rest;
	ssize_t		check;
	ssize_t		check_rest;

	if (fd < 0 || read(fd, NULL, 0) < 0 || !line \
		|| !(*line = ft_strdup("")))
		return (-1);
	if (rest)
	{
		if ((check_rest = ft_rest(&rest, line)) == 1)
			return (1);
		else if (check_rest == -1)
			return (ft_free(&rest, -1));
	}
	if (!(buff = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	if ((check = ft_read(fd, buff, &rest, line)) == -1)
		return (-1);
	else if (check == 1)
		return (1);
	return (0);
}
