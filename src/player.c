/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouillo <jrouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 17:33:34 by jrouillo          #+#    #+#             */
/*   Updated: 2023/03/02 17:26:27 by jrouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	do_movement(t_data *data, int x, int y)
{
	data->map[data->player.pos_y][data->player.pos_x] = '0';
	data->map[y][x] = 'P';
	data->player.pos_x = x;
	data->player.pos_y = y;
	write(1, "Move # : ", 9);
	write(1, ft_itoa(data->moves++), 3);
	write(1, "\n", 1);
	display_map(data);
}

int	move_ok(t_data *data, int x, int y, int key)
{
	printf("data->map[y][x] = %d\n", data->map[y][x]);
	if (data->map[y][x] == 'C')
		data->collectibles--;
	printf("collectiblles = %d\n", data->collectibles);
	if (data->map[y][x] == '1')
		return (1);
	if (data->map[y][x] == 'E' && data->collectibles != 0)
		return (1);
	else if (data->map[y][x] == 'E' && data->collectibles == 0)
	{
		data->game_finish = 1;
		write(1, "Move # : ", 9);
		write(1, ft_itoa(data->moves++), 3);
		write(1, WIN, ft_strlen(WIN));
		free_all_exit("", data);
		return (0);
	}
	if (key != XK_w && key != XK_a && key != XK_s && key != XK_d)
		return (1);
	else 
		return (0);
}

void 	move_player(int key, t_data *data)
{
	int	x;
	int	y;

	printf("data->player.pos_x = %d && data->player.pos_y = %d\n", data->player.pos_x, data->player.pos_y);
	x = data->player.pos_x;
	y = data->player.pos_y;
	if (key == XK_w)
		y--;
	else if (key == XK_a)
		x--;
	else if (key == XK_s)
		y++;
	else if (key == XK_d)
		x++;
	printf("x = %d && y = %d\n", x, y);
	if (!move_ok(data, x, y, key))
		do_movement(data, x, y);
}
