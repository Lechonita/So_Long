/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouillo <jrouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 11:47:09 by jrouillo          #+#    #+#             */
/*   Updated: 2023/03/14 18:07:28 by jrouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_numbers(t_data *data)
{
	data->bonus.numbers[0] = "./images_xpm/numbers/zero.xpm";
	data->bonus.numbers[1] = "./images_xpm/numbers/one.xpm";
	data->bonus.numbers[2] = "./images_xpm/numbers/two.xpm";
	data->bonus.numbers[3] = "./images_xpm/numbers/three.xpm";
	data->bonus.numbers[4] = "./images_xpm/numbers/four.xpm";
	data->bonus.numbers[5] = "./images_xpm/numbers/five.xpm";
	data->bonus.numbers[6] = "./images_xpm/numbers/six.xpm";
	data->bonus.numbers[7] = "./images_xpm/numbers/seven.xpm";
	data->bonus.numbers[8] = "./images_xpm/numbers/eight.xpm";
	data->bonus.numbers[9] = "./images_xpm/numbers/nine.xpm";
}

void	init_player_walk(t_data *data)
{
	data->player.p_walk[0] = "./images_xpm/player/p_walk_right_1.xpm";
	data->player.p_walk[1] = "./images_xpm/player/p_walk_right_2.xpm";
	data->player.p_walk[2] = "./images_xpm/player/p_walk_right_3.xpm";
	data->player.p_walk[3] = "./images_xpm/player/p_walk_right_4.xpm";
	data->player.p_walk[4] = "./images_xpm/player/p_walk_left_1.xpm";
	data->player.p_walk[5] = "./images_xpm/player/p_walk_left_2.xpm";
	data->player.p_walk[6] = "./images_xpm/player/p_walk_left_3.xpm";
	data->player.p_walk[7] = "./images_xpm/player/p_walk_left_4.xpm";

}

void	init_player_idle(t_data *data)
{
	data->player.pos_x = 0;
	data->player.pos_y = 0;
	data->player.direction = 0;
	data->player.p_animate = 0;
	data->player.p_idle[0] = "./images_xpm/player/p_idle_right_1.xpm";
	data->player.p_idle[1] = "./images_xpm/player/p_idle_right_2.xpm";
	data->player.p_idle[2] = "./images_xpm/player/p_idle_right_3.xpm";
	data->player.p_idle[3] = "./images_xpm/player/p_idle_right_4.xpm";
	data->player.p_idle[4] = "./images_xpm/player/p_idle_right_5.xpm";
	data->player.p_idle[5] = "./images_xpm/player/p_idle_left_1.xpm";
	data->player.p_idle[6] = "./images_xpm/player/p_idle_left_2.xpm";
	data->player.p_idle[7] = "./images_xpm/player/p_idle_left_3.xpm";
	data->player.p_idle[8] = "./images_xpm/player/p_idle_left_4.xpm";
	data->player.p_idle[9] = "./images_xpm/player/p_idle_left_5.xpm";
}

void	init_img_struct(t_data *data)
{
	data->img.c = "./images_xpm/map/collectible.xpm";
	data->img.e_open = "./images_xpm/map/door_open.xpm";
	data->img.e_closed = "./images_xpm/map/door_closed.xpm";
	data->img.w_top = "./images_xpm/map/top_wall.xpm";
	data->img.w_bottom = "./images_xpm/map/bottom_wall.xpm";
	data->img.w_right = "./images_xpm/map/right_wall.xpm";
	data->img.w_left = "./images_xpm/map/left_wall.xpm";
	data->img.w_topright = "./images_xpm/map/top_right_corner.xpm";
	data->img.w_topleft = "./images_xpm/map/top_left_corner.xpm";
	data->img.w_bottomright = "./images_xpm/map/bottom_right_corner.xpm";
	data->img.w_bottomleft = "./images_xpm/map/bottom_left_corner.xpm";
	data->img.f = "./images_xpm/map/floor.xpm";
	data->img.o = "./images_xpm/map/obstacle.xpm";
}

void	init_data_struct(t_data *data, char *map_filename)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		exit_error(data, ERROR_INIT_MLX);
	data->win_ptr = NULL;
	data->mlx_img = NULL;
	data->map =  NULL;
	data->map_copy = NULL;
	data->height = get_height(data, map_filename);
	data->width = get_width(data, map_filename);
	data->moves = 0;
	data->loop_count = 0;
	data->collectibles = 0;
	data->game_finish = 0;
	data->win.y = data->height * SIZE_PXL;
	data->win.x = data->width * SIZE_PXL;
}

void	init_struct(t_data *data, char *map_filename)
{
	init_data_struct(data, map_filename);
	init_img_struct(data);
	init_player_idle(data);
	init_player_walk(data);
	init_numbers(data);
}
