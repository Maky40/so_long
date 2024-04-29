/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnie <mnie@student.42perpignan.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 15:35:26 by mnie              #+#    #+#             */
/*   Updated: 2024/02/06 11:26:35 by mnie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libraries/libft/include/libft.h"
# include "../libraries/minilibx-linux/mlx.h"
# include "../libraries/gnl/include/get_next_line.h"
# include "../libraries/ft_printf/include/ft_printf.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include <fcntl.h>

# define COMPOSEE_MAP "01CEP"

typedef struct img_s
{
	void	*img_floor;
	void	*img_player;
	void	*img_exit;
	void	*img_wall;
	void	*img_collect;
	int		height;
	int		width;
	char	*player;
	char	*floor;
	char	*wall;
	char	*collect;
	char	*exit;
}				t_img;

typedef struct cnt_s
{
	int		count_p;
	int		count_e;
	int		count_c;
}				t_cnt;

typedef struct pos_s
{
	int		x;
	int		y;
}				t_pos;

typedef struct data_s
{
	void	*mlx_ptr;
	void	*mlx_win;
	int		width;
	int		height;
	char	**map;
	t_cnt	content;
	t_img	img;
	t_pos	pos;
	int		count;
}				t_data;

int		ft_error(char *str);
void	play(t_data *data);
void	ft_check_content(t_data *data);
void	ft_free_map(t_data *data);
int		ft_check_format(char **map);
void	ft_check_content(t_data *data);
int		ft_check_other(char *map_line, t_cnt *content);
int		check_wall_col(t_data *data);
int		check_wall_line(t_data *data);
int		output_valid(t_data *data);
char	**set_map(char **str, t_data *data);
void	set_img(t_data *data);
int		end(t_data *data);
int		key_press(int keysym, t_data *data);
int		chk_collect(t_data *data);
void	print_img(t_data *data, void *img, int x, int y);
void	pos_perso(t_data *data, char *composee);

#endif
