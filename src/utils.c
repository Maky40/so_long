/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnie <mnie@student.42perpignan.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 15:46:20 by mnie              #+#    #+#             */
/*   Updated: 2024/02/05 11:14:12 by mnie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	chk_collect(t_data *data)
{
	int		i;
	int		y;
	int		count;

	i = 0;
	y = 0;
	count = 0;
	while (data->map[y])
	{
		while (data->map[y][i])
		{
			if (data->map[y][i] == COMPOSEE_MAP[2])
				count++;
			i++;
		}
		i = 0;
		y++;
	}
	return (count);
}

int	ft_error(char *str)
{
	write(2, str, ft_strlen(str));
	return (0);
}

void	set_img(t_data *data)
{
	data->img.height = 80;
	data->img.width = 80;
	data->img.floor = "./rsrc/floor_texture.xpm";
	data->img.wall = "./rsrc/wall_texture.xpm";
	data->img.collect = "./rsrc/collect.xpm";
	data->img.player = "./rsrc/mario_player.xpm";
	data->img.exit = "./rsrc/exit_texture.xpm";
	data->img.img_wall = mlx_xpm_file_to_image(data->mlx_ptr, data->img.wall,
			&(data->img.width), &(data->img.height));
	data->img.img_floor = mlx_xpm_file_to_image(data->mlx_ptr, data->img.floor,
			&(data->img.width), &(data->img.height));
	data->img.img_exit = mlx_xpm_file_to_image(data->mlx_ptr, data->img.exit,
			&(data->img.width), &(data->img.height));
	data->img.img_collect = mlx_xpm_file_to_image(data->mlx_ptr,
			data->img.collect, &(data->img.width), &(data->img.height));
	data->img.img_player = mlx_xpm_file_to_image(data->mlx_ptr,
			data->img.player, &(data->img.width), &(data->img.height));
}

int	end(t_data *data)
{
	if (data->map)
		ft_free_map(data);
	mlx_destroy_image(data->mlx_ptr, data->img.img_wall);
	mlx_destroy_image(data->mlx_ptr, data->img.img_floor);
	mlx_destroy_image(data->mlx_ptr, data->img.img_collect);
	mlx_destroy_image(data->mlx_ptr, data->img.img_player);
	mlx_destroy_image(data->mlx_ptr, data->img.img_exit);
	mlx_destroy_window(data->mlx_ptr, data->mlx_win);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(0);
	return (0);
}
