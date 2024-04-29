/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnie <mnie@student.42perpignan.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 08:51:54 by mnie              #+#    #+#             */
/*   Updated: 2024/02/06 13:52:40 by mnie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include <stdio.h>

char	*get_map(int fd)
{
	char	*line;
	char	*all_line;

	all_line = get_next_line(fd);
	line = get_next_line(fd);
	while (line)
	{
		all_line = ft_strjoin(all_line, line);
		free (line);
		line = get_next_line(fd);
	}
	return (all_line);
}

void	ft_free_map(t_data *data)
{
	int		i;

	i = 0;
	while (data->map[i])
	{
		free(data->map[i]);
		i++;
	}
	free(data->map);
	data->map = NULL;
	return ;
}

char	**parse_map(int fd, t_data *data)
{
	int	i;

	i = 0;
	data -> map = ft_split(get_map(fd), '\n');
	if (!data -> map)
	{
		ft_error("Error\nFichier vide");
		return (data -> map);
	}
	ft_check_content(data);
	if (check_wall_line(data) == 0 || check_wall_col(data) == 0 || \
	ft_check_format(data -> map) == 0)
		ft_free_map(data);
	while (data -> map && data -> map[i])
	{
		if (ft_check_other(data -> map[i], &(data -> content)) == 0)
			ft_free_map(data);
		i++;
	}
	if (data -> map && output_valid(data) == 0)
		ft_free_map(data);
	return (data -> map);
}

char	**set_map(char **str, t_data *data)
{
	int	fd;

	fd = 0;
	data -> map = NULL;
	if (ft_strchr(str[1], ".ber") == 0)
	{
		ft_error("ERROR\n NEED EXTENSION .BER FOR MAP (trouduc)\n");
		return (NULL);
	}
	else
	{
		fd = open(str[1], O_RDONLY);
		if (fd <= 0)
		{
			ft_error("ERROR\n FAILED TO OPEN FILE\n");
			return (NULL);
		}
		data -> map = parse_map(fd, data);
	}
	return (data -> map);
}
