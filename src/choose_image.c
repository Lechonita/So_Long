/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouillo <jrouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 16:27:31 by jrouillo          #+#    #+#             */
/*   Updated: 2023/03/01 16:10:07 by jrouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	image_corner(t_data *data, int y, int x)
{
	if ((y == 0 && x == 0))
		mlx_put_image_to_window(
			data->mlx_ptr, data->win_ptr, data->img.w_topleft, x * SIZE_PXL, y * SIZE_PXL);
	else if ((y == 0 && x == data->width - 1))
		mlx_put_image_to_window(
			data->mlx_ptr, data->win_ptr, data->img.w_topright, x * SIZE_PXL, y * SIZE_PXL);
	else if ((y == data->height - 1 && x == 0))
		mlx_put_image_to_window(
			data->mlx_ptr, data->win_ptr, data->img.w_bottomleft, x * SIZE_PXL, y * SIZE_PXL);
	else if ((y == data->height - 1 && x == data->width - 1))
		mlx_put_image_to_window(
			data->mlx_ptr, data->win_ptr, data->img.w_bottomright, x * SIZE_PXL, y * SIZE_PXL);
}

void	image_top_bottom_wall(t_data *data, int y, int x)
{
	if (y == 0 && (x > 0 && x < data->width - 1))
		mlx_put_image_to_window(
			data->mlx_ptr, data->win_ptr, data->img.w_top, x * SIZE_PXL, y * SIZE_PXL);
	else if (y == data->height - 1 && (x > 0 && x < data->width - 1))
		mlx_put_image_to_window(
			data->mlx_ptr, data->win_ptr, data->img.w_bottom, x * SIZE_PXL, y * SIZE_PXL);
}

void	image_side_wall(t_data *data, int y, int x)
{
	if (x == 0 && (y >= 0 || y <= data->height - 1))
		mlx_put_image_to_window(
			data->mlx_ptr, data->win_ptr, data->img.w_left, x * SIZE_PXL, y * SIZE_PXL);
	else if (x == data->width - 1 && (y >= 0 || y <= data->height - 1))
		mlx_put_image_to_window(
			data->mlx_ptr, data->win_ptr, data->img.w_right, x * SIZE_PXL, y * SIZE_PXL);
}

void	image_center(t_data *data, int y, int x)
{
	printf("letter = %d\n", data->map[y][x]);
	if (data->map[y][x] == 'C')
		mlx_put_image_to_window(
			data->mlx_ptr, data->win_ptr, data->img.c, x * SIZE_PXL, y * SIZE_PXL);
	else if (data->map[y][x] == 'E')
		mlx_put_image_to_window(
			data->mlx_ptr, data->win_ptr, data->img.e_closed, x * SIZE_PXL, y * SIZE_PXL);
	else if (data->map[y][x] == 'P')
		mlx_put_image_to_window(
			data->mlx_ptr, data->win_ptr, data->img.p_right, x * SIZE_PXL, y * SIZE_PXL);
	else if (data->map[y][x] == '1')
		mlx_put_image_to_window(
			data->mlx_ptr, data->win_ptr, data->img.o, x * SIZE_PXL, y * SIZE_PXL);
	else if (data->map[y][x] == '0')
		mlx_put_image_to_window(
			data->mlx_ptr, data->win_ptr, data->img.f, x * SIZE_PXL, y * SIZE_PXL);
}

// void	choose_image(t_data *data, int y, int x)
// {
// 	if ((y == 0 && x == 0) || (y == 0 && x == data->width - 1)
// 		|| (y == data->height - 1 && x == 0)
// 		|| (y == data->height - 1 && x == data->width - 1))
// 		image_corner(data, y, x);
// 	else if ((y == 0) && (x > 0 && x < (data->width - 1))
// 		|| (y == data->height - 1) && (x > 0 && x < (data->width - 1)))
// 		image_top_bottom_wall(data, y, x);
// 	else if ((x == 0) && (y >= 0 || y <= (data->height - 1))
// 		|| (x == data->width - 1) && ((y >= 0 || y <= (data->height - 1))))
// 		image_side_wall(data, y, x);
// 	else
// 		image_center(data, y, x);
// }

void	choose_image(t_data *data, int y, int x)
{
	if (y == 0)
	{
		if ((x == 0) || (x == data->width - 1)
		|| (y == data->height - 1 && x == data->width - 1))
			image_corner(data, y, x);
		else if (x > 0 && x < (data->width - 1))
			image_top_bottom_wall(data, y, x);
	}
	else if (x == 0)
	{
		if (y == data->height - 1)
			image_corner(data, y, x);
		else if (y >= 0 || y <= (data->height - 1))
			image_side_wall(data, y, x);
	}
	else if (x != 0 && y != 0)
	{
		if (y == data->height - 1 && x == data->width - 1)
			image_corner(data, y, x);
		else if ((y == data->height - 1) && (x > 0 && x < (data->width - 1)))
			image_top_bottom_wall(data, y, x);
		else if ((x == data->width - 1) && ((y >= 0 || y <= (data->height - 1))))
			image_side_wall(data, y, x);
		else
			image_center(data, y, x);
	}
}
