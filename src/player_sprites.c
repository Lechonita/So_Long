/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_sprites.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouillo <jrouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 17:10:33 by jrouillo          #+#    #+#             */
/*   Updated: 2023/03/15 17:15:38 by jrouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	walk_player_left(t_data *data, int i)
{
	int j;

	if (i < (RATE / 4))
		j = 0;
	else if (i < 2 * (RATE / 4))
		j = 1;
	else if (i < 3 * (RATE / 4))
		j = 2;
	else
		j = 3;
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->player.p_walk[j + 4], data->player.pos_x * PXL, data->player.pos_y * PXL);
	return ;
}

void	walk_player_right(t_data *data, int i)
{
	int	j;

	if (i < (RATE / 4))
		j = 0;
	else if (i < 2 * (RATE / 4))
		j = 1;
	else if (i < 3 * (RATE / 4))
		j = 2;
	else
		j = 3;
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->player.p_walk[j], data->player.pos_x * PXL, data->player.pos_y * PXL);
	return ;
}

void	idle_player_left(t_data *data, int i)
{
	int	j;

	if (i < (RATE / 5))
		j = 0;
	else if (i < 2 * (RATE / 5))
		j = 1;
	else if (i < 3 * (RATE / 5))
		j = 2;
	else if (i < 4 * (RATE / 5))
		j = 3;
	else
		j = 4;
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->player.p_idle[j + 5], data->player.pos_x * PXL, data->player.pos_y * PXL);
	return ;
}

void	idle_player_right(t_data *data, int i)
{
	int j;

	if (i < (RATE / 5))
		j = 0;
	else if (i < 2 * (RATE / 5))
		j = 1;
	else if (i < 3 * (RATE / 5))
		j = 2;
	else if (i < 4 * (RATE / 5))
		j = 3;
	else
		j = 4;
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->player.p_idle[j], data->player.pos_x * PXL, data->player.pos_y * PXL);
	return ;
}

void	render_player_sprites(t_data *data, int i)
{
	data->player.pos_x = find_px(data);
	data->player.pos_y = find_py(data);
	if (data->player.p_animate == 0 && data->player.direction == 0)
		idle_player_right(data, i);
	else if (data->player.p_animate == 0 && data->player.direction == 1)
		idle_player_left(data, i);
	else if (data->player.p_animate == 1 && data->player.direction == 0)
		walk_player_right(data, i);
	else if (data->player.p_animate == 1 && data->player.direction == 1)
		walk_player_left(data, i);
}