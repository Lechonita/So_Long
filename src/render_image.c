/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouillo <jrouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 11:17:18 by jrouillo          #+#    #+#             */
/*   Updated: 2023/03/09 14:22:30 by jrouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	display_game(t_data *data)
{
	t_map	map;

	map.y = -1;
	while (++map.y < data->height)
	{
		map.x = -1;
		while (++map.x < data->width)
			choose_image(data, map.y, map.x);
	}
	return (0);
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
	data->player.p_idle = mlx_xpm_file_to_image(
		data->mlx_ptr, data->player.p_idle, &width, &height);
	data->img.f = mlx_xpm_file_to_image(
		data->mlx_ptr, data->img.f, &width, &height);
	data->img.o = mlx_xpm_file_to_image(
		data->mlx_ptr, data->img.o, &width, &height);
	if (!data->img.c || !data->img.e_closed || !data->player.p_idle
		|| !data->img.e_open || !data->img.w_top || !data->img.f
		|| !data->img.o)
		free_all_exit(ERROR_IMG_CONVERT, data);
	xpm_wall_images(data);
}
