/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnie <mnie@student.42perpignan.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 12:24:38 by mnie              #+#    #+#             */
/*   Updated: 2024/02/06 12:57:54 by mnie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	render_top(t_data *data)
{
	if (data->map[data->pos.y - 1][data->pos.x] != COMPOSEE_MAP[1])
	{
		if (data->map[data->pos.y - 1][data->pos.x] != COMPOSEE_MAP[3])
		{
			data->map[data->pos.y - 1][data->pos.x] = COMPOSEE_MAP[4];
			data->map[data->pos.y][data->pos.x] = COMPOSEE_MAP[0];
			print_img(data, data->img.img_player, data->pos.x, data->pos.y - 1);
			print_img(data, data->img.img_floor, data->pos.x, data->pos.y);
			data->count += 1;
			printf("count: %d\n", data->count);
		}
		else
		{
			if (chk_collect(data) == 0)
			{
				printf("Felicitation vous avez gagne en : %d coup !\n",
					data->count);
				end(data);
			}
		}
	}
}

void	render_right(t_data *data)
{
	if (data->map[data->pos.y][data->pos.x + 1] != COMPOSEE_MAP[1])
	{
		if (data->map[data->pos.y][data->pos.x + 1] != COMPOSEE_MAP[3])
		{
			data->map[data->pos.y][data->pos.x + 1] = COMPOSEE_MAP[4];
			data->map[data->pos.y][data->pos.x] = COMPOSEE_MAP[0];
			print_img(data, data->img.img_player, data->pos.x + 1, data->pos.y);
			print_img(data, data->img.img_floor, data->pos.x, data->pos.y);
			data->count += 1;
			printf("count: %d\n", data->count);
		}
		else
		{
			if (chk_collect(data) == 0)
			{
				printf("Felicitation vous avez gagne en : %d coup !\n",
					data->count);
				end(data);
			}
		}
	}
}

void	render_left(t_data *data)
{
	pos_perso(data, COMPOSEE_MAP);
	if (data->map[data->pos.y][data->pos.x - 1] != COMPOSEE_MAP[1])
	{
		if (data->map[data->pos.y][data->pos.x - 1] != COMPOSEE_MAP[3])
		{
			data->map[data->pos.y][data->pos.x - 1] = COMPOSEE_MAP[4];
			data->map[data->pos.y][data->pos.x] = COMPOSEE_MAP[0];
			print_img(data, data->img.img_player, data->pos.x - 1, data->pos.y);
			print_img(data, data->img.img_floor, data->pos.x, data->pos.y);
			data->count += 1;
			printf("count: %d\n", data->count);
		}
		else
		{
			if (chk_collect(data) == 0)
			{
				printf("Felicitation vous avez gagne en : %d coup !\n",
					data->count);
				end(data);
			}
		}
	}
}

void	render_down(t_data *data)
{
	if (data->map[data->pos.y + 1][data->pos.x] != COMPOSEE_MAP[1])
	{
		if (data->map[data->pos.y + 1][data->pos.x] != COMPOSEE_MAP[3])
		{
			data->map[data->pos.y + 1][data->pos.x] = COMPOSEE_MAP[4];
			data->map[data->pos.y][data->pos.x] = COMPOSEE_MAP[0];
			print_img(data, data->img.img_player, data->pos.x, data->pos.y + 1);
			print_img(data, data->img.img_floor, data->pos.x, data->pos.y);
			data->count += 1;
			printf("count: %d\n", data->count);
		}
		else
		{
			if (chk_collect(data) == 0)
			{
				printf("Felicitation vous avez gagne en : %d coup !\n",
					data->count);
				end(data);
			}
		}
	}
}

int	key_press(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		end(data);
	if (keysym == XK_w)
	{
		render_top(data);
		pos_perso(data, COMPOSEE_MAP);
	}
	if (keysym == XK_d)
	{
		render_right(data);
		pos_perso(data, COMPOSEE_MAP);
	}
	if (keysym == XK_a)
	{
		render_left(data);
		pos_perso(data, COMPOSEE_MAP);
	}
	if (keysym == XK_s)
	{
		render_down(data);
		pos_perso(data, COMPOSEE_MAP);
	}
	return (0);
}
