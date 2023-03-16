/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm_images.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouillo <jrouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 11:17:18 by jrouillo          #+#    #+#             */
/*   Updated: 2023/03/16 18:06:57 by jrouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	xpm_idle_left_images(t_data *data)
{
	int		width;
	int		height;

	data->player.p_idle[5] = mlx_xpm_file_to_image(
		data->mlx_ptr, "./images_xpm/player/p_idle_left_1.xpm", &width, &height);
	data->player.p_idle[6] = mlx_xpm_file_to_image(
		data->mlx_ptr, "./images_xpm/player/p_idle_left_2.xpm", &width, &height);
	data->player.p_idle[7] = mlx_xpm_file_to_image(
		data->mlx_ptr, "./images_xpm/player/p_idle_left_3.xpm", &width, &height);
	data->player.p_idle[8] = mlx_xpm_file_to_image(
		data->mlx_ptr, "./images_xpm/player/p_idle_left_4.xpm", &width, &height);
	data->player.p_idle[9] = mlx_xpm_file_to_image(
		data->mlx_ptr, "./images_xpm/player/p_idle_left_5.xpm", &width, &height);
	if (!data->player.p_idle[5]	|| !data->player.p_idle[6]
		|| !data->player.p_idle[7] || !data->player.p_idle[8]
		|| !data->player.p_idle[9])
	// {
	// 	printf("ERROR in xpm idle left images");
	// 	free_all_exit(ERROR_IMG_IDLE_CONVERT, data);
	// }
		free_all_exit(ERROR_IMG_IDLE_CONVERT, data);
}

void	xpm_idle_right_images(t_data *data)
{
	int		width;
	int		height;

	data->player.p_idle[0] = mlx_xpm_file_to_image(
		data->mlx_ptr, "./images_xpm/player/p_idle_right_1.xpm", &width, &height);
	data->player.p_idle[1] = mlx_xpm_file_to_image(
		data->mlx_ptr, "./images_xpm/player/p_idle_right_2.xpm", &width, &height);
	data->player.p_idle[2] = mlx_xpm_file_to_image(
		data->mlx_ptr, "./images_xpm/player/p_idle_right_3.xpm", &width, &height);
	data->player.p_idle[3] = mlx_xpm_file_to_image(
		data->mlx_ptr, "./images_xpm/player/p_idle_right_4.xpm", &width, &height);
	data->player.p_idle[4] = mlx_xpm_file_to_image(
		data->mlx_ptr, "./images_xpm/player/p_idle_right_5.xpm", &width, &height);
	if (!data->player.p_idle[0] || !data->player.p_idle[1]
		|| !data->player.p_idle[2] || !data->player.p_idle[3]
		|| !data->player.p_idle[4])
	// {
	// 	printf("ERROR in xpm idle right images");
	// 	free_all_exit(ERROR_IMG_IDLE_CONVERT, data);
	// }
		free_all_exit(ERROR_IMG_IDLE_CONVERT, data);
}

void	xpm_wall_images(t_data *data)
{
	int	width;
	int	height;

	data->img.w_top = mlx_xpm_file_to_image(
		data->mlx_ptr, "./images_xpm/map/top_wall.xpm", &width, &height);
	data->img.w_bottom = mlx_xpm_file_to_image(
		data->mlx_ptr, "./images_xpm/map/bottom_wall.xpm", &width, &height);
	data->img.w_right = mlx_xpm_file_to_image(
		data->mlx_ptr, "./images_xpm/map/right_wall.xpm", &width, &height);
	data->img.w_left = mlx_xpm_file_to_image(
		data->mlx_ptr, "./images_xpm/map/left_wall.xpm", &width, &height);
	data->img.w_topright = mlx_xpm_file_to_image(
		data->mlx_ptr, "./images_xpm/map/top_right_corner.xpm", &width, &height);
	data->img.w_topleft = mlx_xpm_file_to_image(
		data->mlx_ptr, "./images_xpm/map/top_left_corner.xpm", &width, &height);
	data->img.w_bottomright = mlx_xpm_file_to_image(
		data->mlx_ptr, "./images_xpm/map/bottom_right_corner.xpm", &width, &height);
	data->img.w_bottomleft = mlx_xpm_file_to_image(
		data->mlx_ptr, "./images_xpm/map/bottom_left_corner.xpm", &width, &height);
	if (!data->img.w_top || !data->img.w_bottom || !data->img.w_right
		|| !data->img.w_left || !data->img.w_topright || !data->img.w_topleft
		|| !data->img.w_bottomright	|| !data->img.w_bottomleft)
	// {
	// 	printf("ERROR in xpm wall images");
	// 	free_all_exit(ERROR_IMG_WALL_CONVERT, data);
	// }
		free_all_exit(ERROR_IMG_WALL_CONVERT, data);
}

void	xpm_center_images(t_data *data)
{
	int	width;
	int	height;

	data->img.c = mlx_xpm_file_to_image(
		data->mlx_ptr, "./images_xpm/map/collectible.xpm", &width, &height);
	// printf("data->img.c = %p\n", data->img.c);
	data->img.e_open = mlx_xpm_file_to_image(
		data->mlx_ptr, "./images_xpm/map/door_open.xpm", &width, &height);
	// printf("data->img.e_open = %p\n", data->img.e_open);
	data->img.e_closed = mlx_xpm_file_to_image(
		data->mlx_ptr, "./images_xpm/map/door_closed.xpm", &width, &height);
	// printf("data->img.e_closed = %p\n", data->img.e_closed);
	data->img.f = mlx_xpm_file_to_image(
		data->mlx_ptr, "./images_xpm/map/floor.xpm", &width, &height);
	// printf("data->img.f = %p\n", data->img.f);
	data->img.o = mlx_xpm_file_to_image(
		data->mlx_ptr, "./images_xpm/map/obstacle.xpm", &width, &height);
	// printf("data->img.o = %p\n", data->img.o);
	if (!data->img.c || !data->img.e_closed	|| !data->img.e_open
		 || !data->img.f || !data->img.o)
	// {
	// 	printf("ERROR in xpm center images");
	// 	free_all_exit(ERROR_IMG_CONVERT, data);
	// }
		free_all_exit(ERROR_IMG_CONVERT, data);
}

void	xpm_images(t_data *data)
{
	xpm_center_images(data);
	xpm_wall_images(data);
	xpm_idle_right_images(data);
	xpm_idle_left_images(data);
	xpm_walk_images(data);
	xpm_enemy_images(data);
	xpm_numbers_images(data);
	xpm_end_images(data);
}