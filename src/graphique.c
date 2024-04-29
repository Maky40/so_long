/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphique.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnie <mnie@student.42perpignan.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 18:43:24 by mnie              #+#    #+#             */
/*   Updated: 2024/02/06 11:16:47 by mnie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	print_img(t_data *data, void *img, int x, int y)
{
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, img,
		data->img.width * x, data->img.height * y);
}

void	graphique_wall_floor(t_data *data)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (data->map[y])
	{
		while (data->map[y][x])
		{
			if (data->map[y][x] == COMPOSEE_MAP[1])
				print_img(data, data->img.img_wall, x, y);
			if (data->map[y][x] == COMPOSEE_MAP[0])
				print_img(data, data->img.img_floor, x, y);
			x++;
		}
		x = 0;
		y++;
	}
}

void	graphique_collect_player_exit(t_data *data)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (data->map[y])
	{
		while (data->map[y][x])
		{
			if (data->map[y][x] == COMPOSEE_MAP[2])
				print_img(data, data->img.img_collect, x, y);
			if (data->map[y][x] == COMPOSEE_MAP[4])
			{
				data->pos.x = x;
				data->pos.y = y;
				print_img(data, data->img.img_player, x, y);
			}
			if (data->map[y][x] == COMPOSEE_MAP[3])
				print_img(data, data->img.img_exit, x, y);
			x++;
		}
		x = 0;
		y++;
	}
}

int	render(t_data *data)
{
	graphique_wall_floor(data);
	graphique_collect_player_exit(data);
	return (0);
}

void	play(t_data *data)
{
	int	height;
	int	width;

	data->mlx_ptr = mlx_init();
	set_img(data);
	height = data->height * data->img.height;
	width = data->width * data->img.width;
	data->mlx_win = mlx_new_window(data->mlx_ptr, height, width, "so_long");
	mlx_hook(data->mlx_win, KeyRelease, KeyReleaseMask, &key_press, data);
	mlx_hook(data->mlx_win, 17, 0, &end, data);
	render(data);
	mlx_loop(data->mlx_ptr);
}
