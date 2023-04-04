/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm_images2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouillo <jrouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 17:44:57 by jrouillo          #+#    #+#             */
/*   Updated: 2023/04/04 15:23:57 by jrouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	xpm_end_images(t_data *data)
{
	int		w;
	int		h;

	data->img.e_end[0] = mlx_xpm_file_to_image(
			data->mlx_ptr, "./images_xpm/map/door_end_right.xpm", &w, &h);
	data->img.e_end[1] = mlx_xpm_file_to_image(
			data->mlx_ptr, "./images_xpm/map/door_end_left.xpm", &w, &h);
	data->img.e_end[2] = mlx_xpm_file_to_image(
			data->mlx_ptr, "./images_xpm/game/win.xpm", &w, &h);
	if (!data->img.e_end[0] || !data->img.e_end[1]
		|| !data->img.e_end[2])
		free_all_exit(ERROR_IMG_END_CONVERT, data);
	data->bonus.lose[0] = mlx_xpm_file_to_image(
			data->mlx_ptr, "./images_xpm/game/dead_1.xpm", &w, &h);
	data->bonus.lose[1] = mlx_xpm_file_to_image(
			data->mlx_ptr, "./images_xpm/game/dead_2.xpm", &w, &h);
	data->bonus.lose[2] = mlx_xpm_file_to_image(
			data->mlx_ptr, "./images_xpm/game/dead_3.xpm", &w, &h);
	if (!data->bonus.lose[0] || !data->bonus.lose[1]
		|| !data->bonus.lose[2])
		free_all_exit(ERROR_IMG_LOSE_CONVERT, data);
}

void	xpm_numbers2_images(t_data *data)
{
	int		w;
	int		h;

	data->bonus.numbers[5] = mlx_xpm_file_to_image(
			data->mlx_ptr, "./images_xpm/numbers/five.xpm", &w, &h);
	data->bonus.numbers[6] = mlx_xpm_file_to_image(
			data->mlx_ptr, "./images_xpm/numbers/six.xpm", &w, &h);
	data->bonus.numbers[7] = mlx_xpm_file_to_image(
			data->mlx_ptr, "./images_xpm/numbers/seven.xpm", &w, &h);
	data->bonus.numbers[8] = mlx_xpm_file_to_image(
			data->mlx_ptr, "./images_xpm/numbers/eight.xpm", &w, &h);
	data->bonus.numbers[9] = mlx_xpm_file_to_image(
			data->mlx_ptr, "./images_xpm/numbers/nine.xpm", &w, &h);
	if (!data->bonus.numbers[5]
		|| !data->bonus.numbers[6] || !data->bonus.numbers[7]
		|| !data->bonus.numbers[8] || !data->bonus.numbers[9])
		free_all_exit(ERROR_IMG_NBR_CONVERT, data);
}

void	xpm_numbers1_images(t_data *data)
{
	int		w;
	int		h;

	data->bonus.numbers[0] = mlx_xpm_file_to_image(
			data->mlx_ptr, "./images_xpm/numbers/zero.xpm", &w, &h);
	data->bonus.numbers[1] = mlx_xpm_file_to_image(
			data->mlx_ptr, "./images_xpm/numbers/one.xpm", &w, &h);
	data->bonus.numbers[2] = mlx_xpm_file_to_image(
			data->mlx_ptr, "./images_xpm/numbers/two.xpm", &w, &h);
	data->bonus.numbers[3] = mlx_xpm_file_to_image(
			data->mlx_ptr, "./images_xpm/numbers/three.xpm", &w, &h);
	data->bonus.numbers[4] = mlx_xpm_file_to_image(
			data->mlx_ptr, "./images_xpm/numbers/four.xpm", &w, &h);
	if (!data->bonus.numbers[0] || !data->bonus.numbers[1]
		|| !data->bonus.numbers[2] || !data->bonus.numbers[3]
		|| !data->bonus.numbers[4])
		free_all_exit(ERROR_IMG_NBR_CONVERT, data);
}

void	xpm_enemy_images(t_data *data)
{
	int		w;
	int		h;

	data->bonus.enemy[0] = mlx_xpm_file_to_image(
			data->mlx_ptr, "./images_xpm/enemy/enemy_1.xpm", &w, &h);
	data->bonus.enemy[1] = mlx_xpm_file_to_image(
			data->mlx_ptr, "./images_xpm/enemy/enemy_2.xpm", &w, &h);
	data->bonus.enemy[2] = mlx_xpm_file_to_image(
			data->mlx_ptr, "./images_xpm/enemy/enemy_3.xpm", &w, &h);
	if (!data->bonus.enemy[0] || !data->bonus.enemy[1]
		|| !data->bonus.enemy[2])
		free_all_exit(ERROR_IMG_NM_CONVERT, data);
}

void	xpm_walk_images(t_data *data)
{
	int		w;
	int		h;

	data->player.p_walk[0] = mlx_xpm_file_to_image(
			data->mlx_ptr, "./images_xpm/player/p_walk_right_1.xpm", &w, &h);
	data->player.p_walk[1] = mlx_xpm_file_to_image(
			data->mlx_ptr, "./images_xpm/player/p_walk_right_2.xpm", &w, &h);
	data->player.p_walk[2] = mlx_xpm_file_to_image(
			data->mlx_ptr, "./images_xpm/player/p_walk_right_3.xpm", &w, &h);
	data->player.p_walk[3] = mlx_xpm_file_to_image(
			data->mlx_ptr, "./images_xpm/player/p_walk_right_4.xpm", &w, &h);
	data->player.p_walk[4] = mlx_xpm_file_to_image(
			data->mlx_ptr, "./images_xpm/player/p_walk_left_1.xpm", &w, &h);
	data->player.p_walk[5] = mlx_xpm_file_to_image(
			data->mlx_ptr, "./images_xpm/player/p_walk_left_2.xpm", &w, &h);
	data->player.p_walk[6] = mlx_xpm_file_to_image(
			data->mlx_ptr, "./images_xpm/player/p_walk_left_3.xpm", &w, &h);
	data->player.p_walk[7] = mlx_xpm_file_to_image(
			data->mlx_ptr, "./images_xpm/player/p_walk_left_4.xpm", &w, &h);
	if (!data->player.p_walk[0] || !data->player.p_walk[1]
		|| !data->player.p_walk[2] || !data->player.p_walk[3]
		|| !data->player.p_walk[4] || !data->player.p_walk[5]
		|| !data->player.p_walk[6] || !data->player.p_walk[7])
		free_all_exit(ERROR_IMG_WALK_CONVERT, data);
}
