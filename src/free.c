/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouillo <jrouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 12:11:45 by jrouillo          #+#    #+#             */
/*   Updated: 2023/03/14 18:11:23 by jrouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_both_maps(t_data *data)
{
	int i;

	i = -1;
	if (!data->map)
		return ;
	while (++i < data->height && data->map[i])
	{
	 	free(data->map[i]);
	 	free(data->map_copy[i]);
	}
	free(data->map);
	free(data->map_copy);
	free(data);
}

void	free_map(t_data *data)
{
	int i;

	i = -1;
	if (!data->map)
		return ;
	while (++i < data->height && data->map[i])
		free(data->map[i]);
	free(data->map);
	free(data);
}

void	free_numbers_img(t_data *data)
{
	if (data->bonus.numbers[0])
		mlx_destroy_image(data->mlx_ptr, data->bonus.numbers[0]);
	if (data->bonus.numbers[1])
		mlx_destroy_image(data->mlx_ptr, data->bonus.numbers[1]);
	if (data->bonus.numbers[2])
		mlx_destroy_image(data->mlx_ptr, data->bonus.numbers[2]);
	if (data->bonus.numbers[3])
		mlx_destroy_image(data->mlx_ptr, data->bonus.numbers[3]);
	if (data->bonus.numbers[4])
		mlx_destroy_image(data->mlx_ptr, data->bonus.numbers[4]);
	if (data->bonus.numbers[5])
		mlx_destroy_image(data->mlx_ptr, data->bonus.numbers[5]);
	if (data->bonus.numbers[6])
		mlx_destroy_image(data->mlx_ptr, data->bonus.numbers[6]);
	if (data->bonus.numbers[7])
		mlx_destroy_image(data->mlx_ptr, data->bonus.numbers[7]);
	if (data->bonus.numbers[8])
		mlx_destroy_image(data->mlx_ptr, data->bonus.numbers[8]);
	if (data->bonus.numbers[9])
		mlx_destroy_image(data->mlx_ptr, data->bonus.numbers[9]);
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

void	free_walk_img(t_data *data)
{
	if (data->player.p_walk[0])
		mlx_destroy_image(data->mlx_ptr, data->player.p_walk[0]);
	if (data->player.p_walk[1])
		mlx_destroy_image(data->mlx_ptr, data->player.p_walk[1]);
	if (data->player.p_walk[2])
		mlx_destroy_image(data->mlx_ptr, data->player.p_walk[2]);
	if (data->player.p_walk[3])
		mlx_destroy_image(data->mlx_ptr, data->player.p_walk[3]);
	if (data->player.p_walk[4])
		mlx_destroy_image(data->mlx_ptr, data->player.p_walk[4]);
	if (data->player.p_walk[5])
		mlx_destroy_image(data->mlx_ptr, data->player.p_walk[5]);
	if (data->player.p_walk[6])
		mlx_destroy_image(data->mlx_ptr, data->player.p_walk[6]);
	if (data->player.p_walk[7])
		mlx_destroy_image(data->mlx_ptr, data->player.p_walk[7]);
}

void	free_idle_img(t_data *data)
{
	if (data->player.p_idle[0])
		mlx_destroy_image(data->mlx_ptr, data->player.p_idle[0]);
	if (data->player.p_idle[1])
		mlx_destroy_image(data->mlx_ptr, data->player.p_idle[1]);
	if (data->player.p_idle[2])
		mlx_destroy_image(data->mlx_ptr, data->player.p_idle[2]);
	if (data->player.p_idle[3])
		mlx_destroy_image(data->mlx_ptr, data->player.p_idle[3]);
	if (data->player.p_idle[4])
		mlx_destroy_image(data->mlx_ptr, data->player.p_idle[4]);
	if (data->player.p_idle[5])
		mlx_destroy_image(data->mlx_ptr, data->player.p_idle[5]);
	if (data->player.p_idle[6])
		mlx_destroy_image(data->mlx_ptr, data->player.p_idle[6]);
	if (data->player.p_idle[7])
		mlx_destroy_image(data->mlx_ptr, data->player.p_idle[7]);
	if (data->player.p_idle[8])
		mlx_destroy_image(data->mlx_ptr, data->player.p_idle[8]);
	if (data->player.p_idle[9])
		mlx_destroy_image(data->mlx_ptr, data->player.p_idle[9]);
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
	printf("%p\n", data->player.p_walk[0]);
}

void	free_all_exit(char	*error_message, t_data *data)
{
	free_img(data);
	free_idle_img(data);
	free_walk_img(data);
	free_wall_img(data);
	free_numbers_img(data);
	free_close(data);
	exit_error(data, error_message);
}

void	free_close(t_data *data)
{
	if (data->map && data->map_copy)
		free_both_maps(data);
	else if (data->map)
		free_map(data);
	if (data->win_ptr)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		free(data->win_ptr);
	}
	if (data->mlx_ptr)
	{
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
	}
	free(data);
}
