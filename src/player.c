/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouillo <jrouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 17:33:34 by jrouillo          #+#    #+#             */
/*   Updated: 2023/03/09 14:36:37 by jrouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	do_movement(t_data *data, int x, int y, int key)
{
	int	width;
	int	height;

	if (key == XK_a)
		data->player.p_idle = mlx_xpm_file_to_image(
		data->mlx_ptr, "./images_xpm/p1_left.xpm", &width, &height);
	else if (key == XK_d)
		data->player.p_idle = mlx_xpm_file_to_image(
		data->mlx_ptr, "./images_xpm/p1_right.xpm", &width, &height);
	data->map[data->player.pos_y][data->player.pos_x] = '0';
	data->map[y][x] = 'P';
	data->player.pos_x = x;
	data->player.pos_y = y;
	data->moves += 1;
	printf("Move #%d\n", data->moves);
	display_map(data);
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
	{
		data->moves += 1;
		data->game_finish = 1;
		printf("Move #%d\n", data->moves);
		free_all_exit(WIN, data);
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
	if (!move_ok(data, x, y, key))
		do_movement(data, x, y, key);
}
