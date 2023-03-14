/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouillo <jrouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 14:54:59 by jrouillo          #+#    #+#             */
/*   Updated: 2023/03/14 17:58:46 by jrouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	walk_player_left(t_data *data)
{
	if (data->loop_count < (RATE / 4))
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->player.p_walk[4], data->player.pos_x * SIZE_PXL, data->player.pos_y * SIZE_PXL);
	else if (data->loop_count < (RATE / 3))
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->player.p_walk[5], data->player.pos_x * SIZE_PXL, data->player.pos_y * SIZE_PXL);
	else if (data->loop_count < (RATE / 2))
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->player.p_walk[6], data->player.pos_x * SIZE_PXL, data->player.pos_y * SIZE_PXL);
	else if (data->loop_count < RATE)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->player.p_walk[7], data->player.pos_x * SIZE_PXL, data->player.pos_y * SIZE_PXL);
	if (data->loop_count == RATE)
	{
		data->loop_count = 0;
		data->player.p_animate = 0;
		display_game(data);
	}
	return ;
}

void	walk_player_right(t_data *data)
{
	if (data->loop_count < (RATE / 4))
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->player.p_walk[0], data->player.pos_x * SIZE_PXL, data->player.pos_y * SIZE_PXL);
	else if (data->loop_count < (RATE / 3))
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->player.p_walk[1], data->player.pos_x * SIZE_PXL, data->player.pos_y * SIZE_PXL);
	else if (data->loop_count < (RATE / 2))
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->player.p_walk[2], data->player.pos_x * SIZE_PXL, data->player.pos_y * SIZE_PXL);
	else if (data->loop_count < RATE)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->player.p_walk[3], data->player.pos_x * SIZE_PXL, data->player.pos_y * SIZE_PXL);
	if (data->loop_count == RATE)
	{
		data->loop_count = 0;
		data->player.p_animate = 0;
		display_game(data);
	}
	return ;
}

void	idle_player_left(t_data *data)
{
	if (data->loop_count < (RATE / 5))
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->player.p_idle[5], data->player.pos_x * SIZE_PXL, data->player.pos_y * SIZE_PXL);
	else if (data->loop_count < (RATE / 4))
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->player.p_idle[6], data->player.pos_x * SIZE_PXL, data->player.pos_y * SIZE_PXL);
	else if (data->loop_count < (RATE / 3))
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->player.p_idle[7], data->player.pos_x * SIZE_PXL, data->player.pos_y * SIZE_PXL);
	else if (data->loop_count < (RATE / 2))
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->player.p_idle[8], data->player.pos_x * SIZE_PXL, data->player.pos_y * SIZE_PXL);
	else if (data->loop_count < RATE)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->player.p_idle[9], data->player.pos_x * SIZE_PXL, data->player.pos_y * SIZE_PXL);
	if (data->loop_count == RATE)
	{
		data->loop_count = 0;
		data->player.p_animate = 0;
		display_game(data);
	}
	return ;
}

void	idle_player_right(t_data *data)
{
	if (data->loop_count < (RATE / 5))
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->player.p_idle[0], data->player.pos_x * SIZE_PXL, data->player.pos_y * SIZE_PXL);
	else if (data->loop_count < (RATE / 4))
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->player.p_idle[1], data->player.pos_x * SIZE_PXL, data->player.pos_y * SIZE_PXL);
	else if (data->loop_count < (RATE / 3))
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->player.p_idle[2], data->player.pos_x * SIZE_PXL, data->player.pos_y * SIZE_PXL);
	else if (data->loop_count < (RATE / 2))
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->player.p_idle[3], data->player.pos_x * SIZE_PXL, data->player.pos_y * SIZE_PXL);
	else if (data->loop_count < RATE)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->player.p_idle[4], data->player.pos_x * SIZE_PXL, data->player.pos_y * SIZE_PXL);
	if (data->loop_count == RATE)
	{
		data->loop_count = 0;
		data->player.p_animate = 0;
		display_game(data);
	}
	return ;
}

int	render_sprites(t_data *data)
{
	data->loop_count++;
	data->player.pos_x = find_px(data);
	data->player.pos_y = find_py(data);
	if (data->player.p_animate == 0 && data->player.direction == 0)
		idle_player_right(data);
	else if (data->player.p_animate == 0 && data->player.direction == 1)
		idle_player_left(data);
	else if (data->player.p_animate == 1 && data->player.direction == 0)
		walk_player_right(data);
	else if (data->player.p_animate == 1 && data->player.direction == 1)
		walk_player_left(data);
	// animate_enemy(data);
	return (0);
}