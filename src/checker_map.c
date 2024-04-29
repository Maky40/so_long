/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnie <mnie@student.42perpignan.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 11:13:39 by mnie              #+#    #+#             */
/*   Updated: 2024/02/05 11:29:37 by mnie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	check_wall_line(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data -> map[0][i])
	{
		if (data -> map[0][i] != '1')
			return (ft_error("ERROR\nMAP NOT CLOSE (trouduc)\n"));
		i++;
	}
	data->height = i;
	i = 0;
	while (data -> map[i])
		i++;
	while (data -> map[i - 1][j])
	{
		if (data -> map[i - 1][j] != '1')
			return (ft_error("ERROR\nMAP NOT CLOSE (trouduc)\n"));
		j++;
	}
	return (1);
}

int	check_wall_col(t_data *data)
{
	int	i;

	i = 0;
	while (data -> map[i])
		i++;
	data->width = i;
	while (i - 1 != 0)
	{
		if (data -> map [i - 1][0] != '1' \
		|| data -> map [i - 1][ft_strlen(data -> map[i - 1]) - 1] != '1')
			return (ft_error("ERROR\nMAP NOT CLOSE (trouduc)\n"));
		i--;
	}
	return (1);
}

int	ft_check_other(char *map_line, t_cnt *content)
{
	int		i;

	i = 0;
	if (content->count_e != 1 || content->count_p != 1 || content->count_c == 0)
	{
		ft_error("Error\nWrong number of player or exit or collectible\n");
		return (0);
	}
	while (map_line[i])
	{
		if (map_line[i] != COMPOSEE_MAP[0] && map_line[i] != COMPOSEE_MAP[1] \
		&& map_line[i] != COMPOSEE_MAP[2] && map_line[i] != COMPOSEE_MAP[3] \
		&& map_line[i] != COMPOSEE_MAP[4])
			return (ft_error("Error\nUnknown symbol(s) in map (trouduc)\n"));
		i++;
	}
	return (1);
}

void	ft_check_content(t_data *data)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	data->content.count_c = 0;
	data->content.count_p = 0;
	data->content.count_e = 0;
	while (data->map[y])
	{
		while (data->map[y][x])
		{
			if (data->map[y][x] == COMPOSEE_MAP[2])
				data->content.count_c += 1;
			if (data->map[y][x] == COMPOSEE_MAP[4])
				data->content.count_p += 1;
			if (data->map[y][x] == COMPOSEE_MAP[3])
				data->content.count_e += 1;
			x++;
		}
		x = 0;
		y++;
	}
}

int	ft_check_format(char **map)
{
	int		y;
	int		x;
	int		count_x;

	x = 0;
	y = 0;
	count_x = 0;
	while (map[0][count_x])
		count_x++;
	while (map[y] != NULL)
	{
		while (map[y][x])
			x++;
		if (x != count_x)
			return (ft_error("Error\nMap must be a rectangle or a square\n"));
		x = 0;
		y++;
	}
	return (1);
}
