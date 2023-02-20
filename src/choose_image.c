/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouillo <jrouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 16:27:31 by jrouillo          #+#    #+#             */
/*   Updated: 2023/02/20 17:39:18 by jrouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	image_corner(t_data *data, int y, int x)
{
	if ((y == 0 && x == 0))
		mlx_put_image_to_window(
			data->mlx_ptr, data->win_ptr, data->img.w_topleft, x * 32, y * 32);
	else if ((y == 0 && x == data->width - 1))
		mlx_put_image_to_window(
			data->mlx_ptr, data->win_ptr, data->img.w_topright, x * 32, y * 32);
	else if ((y == data->height - 1 && x == 0))
		mlx_put_image_to_window(
			data->mlx_ptr, data->win_ptr, data->img.w_bottleft, x * 32, y * 32);
	else if ((y == data->height - 1 && x == data->width - 1))
		mlx_put_image_to_window(
			data->mlx_ptr, data->win_ptr, data->img.w_bottright, x * 32, y * 32);
}

void	image_top_bottom_wall(t_data *data, int y, int x)
{
	if (y == 0 && (x > 0 && x < data->width - 1))
		mlx_put_image_to_window(
			data->mlx_ptr, data->win_ptr, data->img.w_top, x * 32, y * 32);
	else if (y == data->height - 1 && (x > 0 && x < data->width - 1))
		mlx_put_image_to_window(
			data->mlx_ptr, data->win_ptr, data->img.w_bottom, x * 32, y * 32);
}

void	image_side_wall(t_data *data, int y, int x)
{
	if (x == 0 && (y >= 0 || y <= data->height - 1))
		mlx_put_image_to_window(
			data->mlx_ptr, data->win_ptr, data->img.w_left, x * 32, y * 32);
	else if (x == data->width - 1 && (y >= 0 || y <= data->height - 1))
		mlx_put_image_to_window(
			data->mlx_ptr, data->win_ptr, data->img.w_right, x * 32, y * 32);
}

void	image_window(t_data *data, int y, int x)
{
	if (data->map[y][x] == 'C')
		mlx_put_image_to_window(
			data->mlx_ptr, data->win_ptr, data->img.c, x * 32, y * 32);
	else if (data->map[y][x] == 'E')
		mlx_put_image_to_window(
			data->mlx_ptr, data->win_ptr, data->img.e_closed, x * 32, y * 32);
	else if (data->map[y][x] == 'P')
		mlx_put_image_to_window(
			data->mlx_ptr, data->win_ptr, data->img.p_right, x * 32, y * 32);
	else if (data->map[y][x] == '1')
		mlx_put_image_to_window(
			data->mlx_ptr, data->win_ptr, data->img.o, x * 32, y * 32);
	else if (data->map[y][x] == '0')
		mlx_put_image_to_window(
			data->mlx_ptr, data->win_ptr, data->img.f, x * 32, y * 32);
}

void	choose_image(t_data *data, int y, int x)
{
	if ((y == 0 && x == 0) || (y == 0 && x == data->width - 1)
		|| (y == data->height - 1 && x == 0)
		|| (y == data->height - 1 && x == data->width - 1))
		image_corner(data, y, x);
	else if ((y == 0) && (x > 0 && x < (data->width - 1))
		|| (y == data->height - 1) && (x > 0 && x < (data->width - 1)))
		image_top_bottom_wall(data, y, x);
	else if ((x == 0) && (y >= 0 || y <= (data->height - 1))
		|| (x == data->width - 1) && ((y >= 0 || y <= (data->height - 1))))
		image_side_wall(data, y, x);
	else
		image_window(data, y, x);
}
