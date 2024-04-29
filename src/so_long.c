/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnie <mnie@student.42perpignan.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 11:12:02 by mnie              #+#    #+#             */
/*   Updated: 2024/02/05 11:42:25 by mnie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
	{
		ft_error("Error\nThis programe take 1 argument .ber\n");
		return (0);
	}
	else
	{
		data.count = 0;
		data.map = set_map(argv, &data);
		if (data.map)
			play(&data);
	}
	return (0);
}
