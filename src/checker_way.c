/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_way.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnie <mnie@student.42perpignan.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 20:43:21 by mnie              #+#    #+#             */
/*   Updated: 2024/02/05 11:41:40 by mnie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	pos_perso(t_data *data, char *composee)
{
	int	i;
	int	j;

	j = 0;
	while (data -> map[j])
	{
		i = 0;
		while (data -> map[j][i])
		{
			if (data -> map[j][i] == composee[4])
			{
				data -> pos.x = i;
				data -> pos.y = j;
				return ;
			}
			i++;
		}
		j++;
	}
}

void	find_way(int x, int y, char **map, t_data *data)
{
	if (map[y][x] == COMPOSEE_MAP[2])
		data->content.count_c--;
	if (map[y][x] == COMPOSEE_MAP[3])
	{
		data->content.count_e--;
		map[y][x] = COMPOSEE_MAP[1];
	}
	if (map[y][x] == COMPOSEE_MAP[1] || map[y][x] == '*')
		return ;
	map[y][x] = '*';
	find_way(x - 1, y, map, data);
	find_way(x + 1, y, map, data);
	find_way(x, y - 1, map, data);
	find_way(x, y + 1, map, data);
	return ;
}

void	ft_free_map_duplicate(char **map)
{
	int		i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
	map = NULL;
	return ;
}

char	**duplicate_map(char **map1)
{
	int		i;
	char	**map2;

	i = 0;
	while (map1[i])
		i++;
	map2 = malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (map1[i])
	{
		map2[i] = ft_strdup(map1[i]);
		i++;
	}
	map2[i] = NULL;
	return (map2);
}

int	output_valid(t_data *data)
{
	char	**map;

	ft_check_content(data);
	pos_perso(data, COMPOSEE_MAP);
	map = duplicate_map(data -> map);
	find_way(data -> pos.x, data -> pos.y, map, data);
	if (data -> content.count_c != 0 || data -> content.count_e != 0)
	{
		if (data -> content.count_c != 0 && data -> content.count_e != 0)
			ft_error("Error\nOutput is not accessible, same for items");
		else if (data -> content.count_c != 0)
			ft_error("Error\nNot all items are accessible");
		else
			ft_error("Error\nOutput is not accessible");
		ft_free_map_duplicate(map);
		return (0);
	}
	ft_free_map_duplicate(map);
	return (1);
}
