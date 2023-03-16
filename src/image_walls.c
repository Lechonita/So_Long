/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouillo <jrouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 16:27:31 by jrouillo          #+#    #+#             */
/*   Updated: 2023/03/16 12:25:09 by jrouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	image_corner(t_data *data, int y, int x)
{
	// printf("data width = %d\n", data->width);
	if ((y == 0 && x == 0))
		mlx_put_image_to_window(
			data->mlx_ptr, data->win_ptr, data->img.w_topleft, x * PXL, y * PXL);
	else if ((y == 0 && x == data->width - 1))
		mlx_put_image_to_window(
			data->mlx_ptr, data->win_ptr, data->img.w_topright, x * PXL, y * PXL);
	else if ((y == data->height - 1 && x == 0))
		mlx_put_image_to_window(
			data->mlx_ptr, data->win_ptr, data->img.w_bottomleft, x * PXL, y * PXL);
	else if ((y == data->height - 1 && x == data->width - 1))
		mlx_put_image_to_window(
			data->mlx_ptr, data->win_ptr, data->img.w_bottomright, x * PXL, y * PXL);
}

void	image_top_bottom_wall(t_data *data, int y, int x)
{
	if (y == 0 && (x > 0 && x < data->width - 1))
		mlx_put_image_to_window(
			data->mlx_ptr, data->win_ptr, data->img.w_top, x * PXL, y * PXL);
	else if (y == data->height - 1 && (x > 0 && x < data->width - 1))
		mlx_put_image_to_window(
			data->mlx_ptr, data->win_ptr, data->img.w_bottom, x * PXL, y * PXL);
}

void	image_side_wall(t_data *data, int y, int x)
{
	if (x == 0 && (y >= 0 || y <= data->height - 1))
		mlx_put_image_to_window(
			data->mlx_ptr, data->win_ptr, data->img.w_left, x * PXL, y * PXL);
	else if (x == data->width - 1 && (y >= 0 || y <= data->height - 1))
		mlx_put_image_to_window(
			data->mlx_ptr, data->win_ptr, data->img.w_right, x * PXL, y * PXL);
}

void	image_numbers(t_data *data)
{
	int	h;
	int	t;
	int	u;

	h = data->moves / 100;
	t = (data->moves % 100) / 10;
	u = data->moves % 10;
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->bonus.numbers[u], ((data->width * PXL) - NBR_PXL), 0);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->bonus.numbers[t], ((data->width * PXL) - (NBR_PXL * 2)), 0);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->bonus.numbers[h], ((data->width * PXL) - (NBR_PXL * 3)), 0);
}
