/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouillo <jrouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 17:33:34 by jrouillo          #+#    #+#             */
/*   Updated: 2023/03/15 14:45:18 by jrouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	win_game(t_data *data, int x, int y)
{
	data->finish_game = 1;
	data->moves += 1;
	ft_printf("Move #%d\n", data->moves);
	data->map[data->player.pos_y][data->player.pos_x] = '0';
	data->map[y][x] = 'E';
	free_all_exit(WIN, data);
	return ;
}

void	do_movement(t_data *data, int x, int y, int key)
{
	printf("playr pos x = %d\n", data->player.pos_x);
	printf("playr pos y = %d\n", data->player.pos_y);
	(void)key;
	data->map[data->player.pos_y][data->player.pos_x] = '0';
	data->map[y][x] = 'P';
	data->player.pos_x = x;
	data->player.pos_y = y;
	data->moves += 1;
	ft_printf("Move #%d\n", data->moves);
}

int	move_ok(t_data *data, int x, int y, int key)
{
	if (data->map[y][x] == 'C')
		data->collectibles--;
	if (data->map[y][x] == '1')
		return (1);
	if (data->map[y][x] == 'E' && data->collectibles != 0)
		return (1);
	else if (data->map[y][x] == 'E' && data->collectibles == 0)
		win_game(data, x, y);
	if (key != XK_w && key != XK_a && key != XK_s && key != XK_d)
		return (1);
	else
		return (0);
}

void 	move_player(int key, t_data *data)
{
	int	x;
	int	y;

	x = data->player.pos_x;
	y = data->player.pos_y;
	if (key == XK_w)
		y--;
	else if (key == XK_a)
	{
		data->player.direction = 1;
		x--;
	}
	else if (key == XK_s)
		y++;
	else if (key == XK_d)
	{
		data->player.direction = 0;
		x++;
	}
	data->player.p_animate = 1;
	if (!move_ok(data, x, y, key))
		do_movement(data, x, y, key);
}
