/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouillo <jrouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 11:17:18 by jrouillo          #+#    #+#             */
/*   Updated: 2023/02/20 17:25:52 by jrouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	display_game(t_data *data)
{
	t_map	map;

	map.y = -1;
	if (data->win_ptr)
	{
		while (data->map[++map.y])
		{
			map.x = 0;
			while (data->map[map.y][map.x])
			{
				choose_image(data, map.y, map.x);
				map.x++;
			}
		}
	}
	return (0);
}

void	xpm_wall_images(t_data *data)
{
	data->img.w_top = mlx_xpm_file_to_image(
		data->mlx_ptr, data->img.w_top, &data->width, &data->height);
	data->img.w_bottom = mlx_xpm_file_to_image(
		data->mlx_ptr, data->img.w_bottom, &data->width, &data->height);
	data->img.w_right = mlx_xpm_file_to_image(
		data->mlx_ptr, data->img.w_right, &data->width, &data->height);
	data->img.w_left = mlx_xpm_file_to_image(
		data->mlx_ptr, data->img.w_left, &data->width, &data->height);
	data->img.w_topright = mlx_xpm_file_to_image(
		data->mlx_ptr, data->img.w_topright, &data->width, &data->height);
	data->img.w_topleft = mlx_xpm_file_to_image(
		data->mlx_ptr, data->img.w_topleft, &data->width, &data->height);
	data->img.w_bottright = mlx_xpm_file_to_image(
		data->mlx_ptr, data->img.w_bottright, &data->width, &data->height);
	data->img.w_bottleft = mlx_xpm_file_to_image(
		data->mlx_ptr, data->img.w_bottleft, &data->width, &data->height);
	if (!data->img.w_top || !data->img.w_bottom || !data->img.w_right || !data->img.w_left
		|| !data->img.w_topright || !data->img.w_topleft || !data->img.w_bottright
		|| !data->img.w_bottleft)
		free_wall_exit(ERROR_IMG_WALL_CONVERT, data);
}

void	xpm_images(t_data *data)
{
	data->img.c = mlx_xpm_file_to_image(
		data->mlx_ptr, data->img.c, &data->width, &data->height);
	data->img.e_open = mlx_xpm_file_to_image(
		data->mlx_ptr, data->img.e_open, &data->width, &data->height);
	data->img.e_closed = mlx_xpm_file_to_image(
		data->mlx_ptr, data->img.e_closed, &data->width, &data->height);
	data->img.p_right = mlx_xpm_file_to_image(
		data->mlx_ptr, data->img.p_right, &data->width, &data->height);
	data->img.p_left = mlx_xpm_file_to_image(
		data->mlx_ptr, data->img.p_left, &data->width, &data->height);
	data->img.f = mlx_xpm_file_to_image(
		data->mlx_ptr, data->img.f, &data->width, &data->height);
	data->img.o = mlx_xpm_file_to_image(
		data->mlx_ptr, data->img.o, &data->width, &data->height);
	if (!data->img.c || !data->img.e_closed || !data->img.p_right || !data->img.w_top
		|| !data->img.f || !data->img.o)
		free_all_exit(ERROR_IMG_CONVERT, data);
}

void	init_images(t_data *data)
{
	data->img.c = "../images_xpm/collectible.xpm";
	data->img.e_open = "../images_xpm/door_open.xpm";
	data->img.e_closed = "../images_xpm/door_closed.xpm";
	data->img.p_right = "../images_xpm/pig_right.xpm";
	data->img.p_left = "../images_xpm/pig_left.xpm";
	data->img.w_top = "../images_xpm/top_wall.xpm";
	data->img.w_bottom = "../images_xpm/bottom_wall.xpm";
	data->img.w_right = "../images_xpm/right_wall.xpm";
	data->img.w_left = "../images_xpm/left_wall.xpm";
	data->img.w_topright = "../images_xpm/top_right_corner.xpm";
	data->img.w_topleft = "../images_xpm/top_left_corner.xpm";
	data->img.w_bottright = "../images_xpm/bott_right_corner.xpm";
	data->img.w_bottleft = "../images_xpm/bott_left_corner.xpm";
	data->img.f = "../images_xpm/floor.xpm";
	data->img.o = "../images_xpm/obstacle.xpm";
}

