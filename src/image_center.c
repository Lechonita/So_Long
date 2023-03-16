/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_center.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouillo <jrouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 17:18:47 by jrouillo          #+#    #+#             */
/*   Updated: 2023/03/16 15:20:37 by jrouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_monster_sprites(t_data *data, int y, int x, int i)
{
	int		j;

	if (i < (RATE / 3))
		j = 0;
	else if (i < 2 * (RATE / 3))
		j = 1;
	else
		j = 2;
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->bonus.enemy[j], x * PXL, y * PXL);
	return ;
}

void	image_exit(t_data *data, int y, int x)
{
	if (data->collectibles > 0)
		mlx_put_image_to_window(
			data->mlx_ptr, data->win_ptr, data->img.e_closed, x * PXL, y * PXL);
	else if (data->collectibles == 0)
	{
		if (data->finish_game == 0)
			mlx_put_image_to_window(
				data->mlx_ptr, data->win_ptr, data->img.e_open, x * PXL, y * PXL);
		else if (data->finish_game == 1 && data->player.direction == 0)
		{
			mlx_put_image_to_window(
				data->mlx_ptr, data->win_ptr, data->img.e_end[0], x * PXL, y * PXL);
			mlx_put_image_to_window(
				data->mlx_ptr, data->win_ptr, data->img.e_end[2], (data->width / 2 - 64) * PXL, (data->height / 2 - 64) * PXL);
		}
		else if (data->finish_game == 1 && data->player.direction == 1)
			mlx_put_image_to_window(
			data->mlx_ptr, data->win_ptr, data->img.e_end[1], x * PXL, y * PXL);
	}
}

void	image_center(t_data *data, int y, int x, int i)
{
	if (data->map[y][x] == 'C')
		mlx_put_image_to_window(
			data->mlx_ptr, data->win_ptr, data->img.c, x * PXL, y * PXL);
	else if (data->map[y][x] == 'E')
		image_exit(data, y, x);
	else if (data->map[y][x] == '1')
		mlx_put_image_to_window(
			data->mlx_ptr, data->win_ptr, data->img.o, x * PXL, y * PXL);
	else if (data->map[y][x] == '0')
		mlx_put_image_to_window(
			data->mlx_ptr, data->win_ptr, data->img.f, x * PXL, y * PXL);
	else if (data->map[y][x] == 'P')
		render_player_sprites(data, i);
	else if (data->map[y][x] == 'M')
		render_monster_sprites(data, y, x, i);
	image_numbers(data);
}
