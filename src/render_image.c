/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouillo <jrouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 11:17:18 by jrouillo          #+#    #+#             */
/*   Updated: 2023/03/13 17:27:56 by jrouillo         ###   ########.fr       */
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

int	loop_hook(t_data *data)
{
	static int	i;
	static int	idle;
	static int	walk;

	if (++i <= 500)
	{
		printf("i = %d\n", i);
		display_game(data);
		if (data->player.p_animate == 0)
			idle_player(data, idle);
		else if (data->player.p_animate == 1)
			animate_player(data, walk);
		if (idle == 5)
			idle = -1;
		if (walk == 3)
			walk = -1;
		idle++;
		walk++;
		if (i == 500)
			i = 0;
	}
	return (0);
}

void	xpm_playeridle_images(t_data *data)
{
	int	width;
	int	height;

	data->player.p_idle[0] = mlx_xpm_file_to_image(
		data->mlx_ptr, data->player.p_idle[0], &width, &height);
	data->player.p_idle[1] = mlx_xpm_file_to_image(
		data->mlx_ptr, data->player.p_idle[1], &width, &height);
	data->player.p_idle[2] = mlx_xpm_file_to_image(
		data->mlx_ptr, data->player.p_idle[2], &width, &height);
	data->player.p_idle[3] = mlx_xpm_file_to_image(
		data->mlx_ptr, data->player.p_idle[3], &width, &height);
	data->player.p_idle[4] = mlx_xpm_file_to_image(
		data->mlx_ptr, data->player.p_idle[4], &width, &height);
	data->player.p_idle[5] = mlx_xpm_file_to_image(
		data->mlx_ptr, data->player.p_idle[5], &width, &height);
	data->player.p_idle[6] = mlx_xpm_file_to_image(
		data->mlx_ptr, data->player.p_idle[6], &width, &height);
	data->player.p_idle[7] = mlx_xpm_file_to_image(
		data->mlx_ptr, data->player.p_idle[7], &width, &height);
	data->player.p_idle[8] = mlx_xpm_file_to_image(
		data->mlx_ptr, data->player.p_idle[8], &width, &height);
	data->player.p_idle[9] = mlx_xpm_file_to_image(
		data->mlx_ptr, data->player.p_idle[9], &width, &height);
	if (!data->player.p_idle[0] || !data->player.p_idle[1]
		|| !data->player.p_idle[2] || !data->player.p_idle[3]
		|| !data->player.p_idle[4] || !data->player.p_idle[5]
		|| !data->player.p_idle[6] || !data->player.p_idle[7]
		|| !data->player.p_idle[8] || !data->player.p_idle[9])
		free_all_exit(ERROR_IMG_IDLE_CONVERT, data);
}

void	xpm_playerwalk_images(t_data *data)
{
	int	width;
	int	height;

	data->player.p_walk[0] = mlx_xpm_file_to_image(
		data->mlx_ptr, data->player.p_walk[0], &width, &height);
	data->player.p_walk[1] = mlx_xpm_file_to_image(
		data->mlx_ptr, data->player.p_walk[1], &width, &height);
	data->player.p_walk[2] = mlx_xpm_file_to_image(
		data->mlx_ptr, data->player.p_walk[2], &width, &height);
	data->player.p_walk[3] = mlx_xpm_file_to_image(
		data->mlx_ptr, data->player.p_walk[3], &width, &height);
	data->player.p_walk[4] = mlx_xpm_file_to_image(
		data->mlx_ptr, data->player.p_walk[4], &width, &height);
	data->player.p_walk[5] = mlx_xpm_file_to_image(
		data->mlx_ptr, data->player.p_walk[5], &width, &height);
	if (!data->player.p_walk[0] || !data->player.p_walk[1]
		|| !data->player.p_walk[2] || !data->player.p_walk[3]
		|| !data->player.p_walk[4] || !data->player.p_walk[5])
		free_all_exit(ERROR_IMG_WALK_CONVERT, data);
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
	data->player.p_image = mlx_xpm_file_to_image(
		data->mlx_ptr, data->player.p_image, &width, &height);
	data->img.f = mlx_xpm_file_to_image(
		data->mlx_ptr, data->img.f, &width, &height);
	data->img.o = mlx_xpm_file_to_image(
		data->mlx_ptr, data->img.o, &width, &height);
	if (!data->img.c || !data->img.e_closed || !data->player.p_image
		|| !data->img.e_open || !data->img.w_top || !data->img.f
		|| !data->img.o)
		free_all_exit(ERROR_IMG_CONVERT, data);
	xpm_wall_images(data);
	xpm_playerwalk_images(data);
	xpm_playeridle_images(data);
}
