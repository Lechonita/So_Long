/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm_images.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouillo <jrouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 11:17:18 by jrouillo          #+#    #+#             */
/*   Updated: 2023/03/15 17:05:40 by jrouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	xpm_numbers_images(t_data *data)
{
	int	width;
	int	height;
	int i;

	i = -1;
	while (++i < 10)
	{
		data->bonus.numbers[i] = mlx_xpm_file_to_image(
		data->mlx_ptr, data->bonus.numbers[i], &width, &height);
		if (!data->bonus.numbers[i])
			free_all_exit(ERROR_IMG_NBR_CONVERT, data);
	}
	return ;
}

void	xpm_enemy_images(t_data *data)
{
	int	width;
	int	height;
	int i;

	i = -1;
	while (++i < 3)
	{
		data->bonus.enemy[i] = mlx_xpm_file_to_image(
		data->mlx_ptr, data->bonus.enemy[i], &width, &height);
		if (!data->bonus.enemy[i])
			free_all_exit(ERROR_IMG_NM_CONVERT, data);
	}
	return ;
}

void	xpm_idle_images(t_data *data)
{
	int	width;
	int	height;
	int	i;

	i = -1;
	while (++i < 10)
	{
		data->player.p_idle[i] = mlx_xpm_file_to_image(
		data->mlx_ptr, data->player.p_idle[i], &width, &height);
		if (!data->player.p_idle[i])
			free_all_exit(ERROR_IMG_IDLE_CONVERT, data);
	}
}

void	xpm_walk_images(t_data *data)
{
	int	width;
	int	height;
	int	i;

	i = -1;
	while (++i < 8)
	{
		data->player.p_walk[i] = mlx_xpm_file_to_image(
			data->mlx_ptr, data->player.p_walk[i], &width, &height);
		if (!data->player.p_walk[i])
			free_all_exit(ERROR_IMG_WALK_CONVERT, data);
	}
}

void	xpm_wall_images(t_data *data)
{
	int	width;
	int	height;

	data->img.w_top = mlx_xpm_file_to_image(
		data->mlx_ptr, data->img.w_top, &width, &height);
	data->img.w_bottom = mlx_xpm_file_to_image(
		data->mlx_ptr, data->img.w_bottom, &width, &height);
	data->img.w_right = mlx_xpm_file_to_image(
		data->mlx_ptr, data->img.w_right, &width, &height);
	data->img.w_left = mlx_xpm_file_to_image(
		data->mlx_ptr, data->img.w_left, &width, &height);
	data->img.w_topright = mlx_xpm_file_to_image(
		data->mlx_ptr, data->img.w_topright, &width, &height);
	data->img.w_topleft = mlx_xpm_file_to_image(
		data->mlx_ptr, data->img.w_topleft, &width, &height);
	data->img.w_bottomright = mlx_xpm_file_to_image(
		data->mlx_ptr, data->img.w_bottomright, &width, &height);
	data->img.w_bottomleft = mlx_xpm_file_to_image(
		data->mlx_ptr, data->img.w_bottomleft, &width, &height);
	if (!data->img.w_top || !data->img.w_bottom || !data->img.w_right
		|| !data->img.w_left || !data->img.w_topright || !data->img.w_topleft
		|| !data->img.w_bottomright	|| !data->img.w_bottomleft)
		free_all_exit(ERROR_IMG_WALL_CONVERT, data);
}

void	xpm_images(t_data *data)
{
	int	width;
	int	height;

	data->img.c = mlx_xpm_file_to_image(
		data->mlx_ptr, data->img.c, &width, &height);
	data->img.e_open = mlx_xpm_file_to_image(
		data->mlx_ptr, data->img.e_open, &width, &height);
	data->img.e_closed = mlx_xpm_file_to_image(
		data->mlx_ptr, data->img.e_closed, &width, &height);
	data->img.e_end[0] = mlx_xpm_file_to_image(
		data->mlx_ptr, data->img.e_end[0], &width, &height);
	data->img.e_end[1] = mlx_xpm_file_to_image(
		data->mlx_ptr, data->img.e_end[1], &width, &height);
	data->img.f = mlx_xpm_file_to_image(
		data->mlx_ptr, data->img.f, &width, &height);
	data->img.o = mlx_xpm_file_to_image(
		data->mlx_ptr, data->img.o, &width, &height);
	if (!data->img.c || !data->img.e_closed	|| !data->img.e_open
		|| !data->img.w_top || !data->img.f	|| !data->img.o)
		free_all_exit(ERROR_IMG_CONVERT, data);
	xpm_wall_images(data);
	xpm_walk_images(data);
	xpm_idle_images(data);
	xpm_enemy_images(data);
	xpm_numbers_images(data);
}
