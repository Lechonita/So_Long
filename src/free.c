/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouillo <jrouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 12:11:45 by jrouillo          #+#    #+#             */
/*   Updated: 2023/03/16 17:53:33 by jrouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_maps(t_data *data)
{
	int i;

	i = -1;
	if (!data->map)
		return ;
	while (++i < data->height && data->map[i])
	{
	 	free(data->map[i]);
		if (data->map_copy[i])
	 		free(data->map_copy[i]);
	}
	free(data->map);
	free(data->map_copy);
	free(data);
	return ;
}

// void	free_map(t_data *data)
// {
// 	int i;

// 	i = -1;
// 	if (!data->map)
// 		return ;
// 	while (++i < data->height && data->map[i])
// 		free(data->map[i]);
// 	free(data->map);
// 	free(data);
// }

void	free_sprites_img(t_data *data)
{
	int	i;

	i = -1;
	while (++i < 10)
	{
		printf("for i = %d ==> %p\n", i, data->bonus.numbers[i]);
		if (data->bonus.numbers[i])
			mlx_destroy_image(data->mlx_ptr, data->bonus.numbers[i]);
		printf("for i = %d ==> %p\n", i, data->player.p_idle[i]);
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
	}
	// printf("TEST FREE ALL FINISH\n");
}

void	free_wall_img(t_data *data)
{
	printf("TEST wall\n");
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
	printf("TEST\n");
	if (data->img.c)
		mlx_destroy_image(data->mlx_ptr, data->img.c);
	if (data->img.e_open)
		mlx_destroy_image(data->mlx_ptr, data->img.e_open);
	if (data->img.e_closed)
		mlx_destroy_image(data->mlx_ptr, data->img.e_closed);
	if (data->img.e_end[0])
		mlx_destroy_image(data->mlx_ptr, data->img.e_end[0]);
	if (data->img.e_end[1])
		mlx_destroy_image(data->mlx_ptr, data->img.e_end[1]);
	if (data->img.e_end[2])
		mlx_destroy_image(data->mlx_ptr, data->img.e_end[2]);
	if (data->img.e_end[3])
		mlx_destroy_image(data->mlx_ptr, data->img.e_end[3]);
	if (data->img.f)
		mlx_destroy_image(data->mlx_ptr, data->img.f);
	if (data->img.o)
		mlx_destroy_image(data->mlx_ptr, data->img.o);
}

void	free_close(t_data *data)
{
	if (data->map)
		free_maps(data);
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

void	free_all_exit(char	*error_message, t_data *data)
{
	free_img(data);
	free_wall_img(data);
	free_sprites_img(data);
	free_close(data);
	exit_error(data, error_message);
}
