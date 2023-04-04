/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouillo <jrouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 18:06:54 by jrouillo          #+#    #+#             */
/*   Updated: 2023/04/04 15:01:11 by jrouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_lose(t_data *data)
{
	int	i;

	i = -1;
	while (++i < 3)
	{
		if (data->bonus.lose[i])
			mlx_destroy_image(data->mlx_ptr, data->bonus.lose[i]);
	}
}

void	free_sprites_img(t_data *data)
{
	int	i;

	i = -1;
	while (++i < 10)
	{
		if (data->bonus.numbers[i])
			mlx_destroy_image(data->mlx_ptr, data->bonus.numbers[i]);
		if (data->player.p_idle[i])
			mlx_destroy_image(data->mlx_ptr, data->player.p_idle[i]);
	}
	i = -1;
	while (++i < 8)
	{
		if (data->player.p_walk[i])
			mlx_destroy_image(data->mlx_ptr, data->player.p_walk[i]);
	}
	i = -1;
	while (++i < 3)
	{
		if (data->bonus.enemy[i])
			mlx_destroy_image(data->mlx_ptr, data->bonus.enemy[i]);
		if (data->img.e_end[i])
			mlx_destroy_image(data->mlx_ptr, data->img.e_end[i]);
	}
}

void	free_wall_img(t_data *data)
{
	if (data->img.w_top)
		mlx_destroy_image(data->mlx_ptr, data->img.w_top);
	if (data->img.w_bottom)
		mlx_destroy_image(data->mlx_ptr, data->img.w_bottom);
	if (data->img.w_right)
		mlx_destroy_image(data->mlx_ptr, data->img.w_right);
	if (data->img.w_left)
		mlx_destroy_image(data->mlx_ptr, data->img.w_left);
	if (data->img.w_topright)
		mlx_destroy_image(data->mlx_ptr, data->img.w_topright);
	if (data->img.w_topleft)
		mlx_destroy_image(data->mlx_ptr, data->img.w_topleft);
	if (data->img.w_bottomright)
		mlx_destroy_image(data->mlx_ptr, data->img.w_bottomright);
	if (data->img.w_bottomleft)
		mlx_destroy_image(data->mlx_ptr, data->img.w_bottomleft);
}

void	free_img(t_data *data)
{
	if (data->img.c)
		mlx_destroy_image(data->mlx_ptr, data->img.c);
	if (data->img.e_open)
		mlx_destroy_image(data->mlx_ptr, data->img.e_open);
	if (data->img.e_closed)
		mlx_destroy_image(data->mlx_ptr, data->img.e_closed);
	if (data->img.f)
		mlx_destroy_image(data->mlx_ptr, data->img.f);
	if (data->img.o)
		mlx_destroy_image(data->mlx_ptr, data->img.o);
}
