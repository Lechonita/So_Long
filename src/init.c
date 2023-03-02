/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouillo <jrouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 11:47:09 by jrouillo          #+#    #+#             */
/*   Updated: 2023/03/02 17:50:36 by jrouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_win_struct(t_data *data)
{
	data->win.y = data->height * SIZE_PXL;
	data->win.x = data->width * SIZE_PXL;
}

void	init_player_struct(t_data *data)
{
	data->player.pos_x = 0;
	data->player.pos_y = 0;
	data->player.p1_right = "./images_xpm/p1_right.xpm";
	data->player.p2_right = "./images_xpm/p2_right.xpm";
	data->player.p3_right = "./images_xpm/p3_right.xpm";
	data->player.p1_left = "./images_xpm/p1_left.xpm";
	data->player.p2_left = "./images_xpm/p2_left.xpm";
	data->player.p3_left = "./images_xpm/p3_left.xpm";
}

void	init_img_struct(t_data *data)
{
	data->img.c = "./images_xpm/collectible.xpm";
	data->img.e_open = "./images_xpm/door_open.xpm";
	data->img.e_closed = "./images_xpm/door_closed.xpm";
	data->img.p_right = "./images_xpm/p1_right.xpm";
	data->img.p_left = "./images_xpm/p1_left.xpm";
	data->img.w_top = "./images_xpm/top_wall.xpm";
	data->img.w_bottom = "./images_xpm/bottom_wall.xpm";
	data->img.w_right = "./images_xpm/right_wall.xpm";
	data->img.w_left = "./images_xpm/left_wall.xpm";
	data->img.w_topright = "./images_xpm/top_right_corner.xpm";
	data->img.w_topleft = "./images_xpm/top_left_corner.xpm";
	data->img.w_bottomright = "./images_xpm/bottom_right_corner.xpm";
	data->img.w_bottomleft = "./images_xpm/bottom_left_corner.xpm";
	data->img.f = "./images_xpm/floor.xpm";
	data->img.o = "./images_xpm/obstacle.xpm";
}

void	init_data_struct(t_data *data, char *map_filename)
{
	data->mlx_ptr = NULL;
	data->win_ptr = NULL;
	data->mlx_img = NULL;
	data->map =  NULL;
	data->map_copy = NULL;
	data->height = get_height(data, map_filename);
	data->width = get_width(data, map_filename);
	data->moves = 0;
	data->collectibles = 0;
	data->game_finish = 0;
}

void	init_struct(t_data *data, char *map_filename)
{
	init_data_struct(data, map_filename);
	init_img_struct(data);
	init_player_struct(data);
	init_win_struct(data);
}