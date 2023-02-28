/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouillo <jrouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 12:11:45 by jrouillo          #+#    #+#             */
/*   Updated: 2023/02/28 15:11:43 by jrouillo         ###   ########.fr       */
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

void	free_all_exit(char	*error_message, t_data *data)
{
	if (data->img.c)
		mlx_destroy_image(data->mlx_ptr, data->img.c);
	if (data->img.e_open)
		mlx_destroy_image(data->mlx_ptr, data->img.e_open);
	if (data->img.e_closed)
		mlx_destroy_image(data->mlx_ptr, data->img.e_closed);
	if (data->img.p_right)
		mlx_destroy_image(data->mlx_ptr, data->img.p_right);
	if (data->img.p_left)
		mlx_destroy_image(data->mlx_ptr, data->img.p_left);
	if (data->img.f)
		mlx_destroy_image(data->mlx_ptr, data->img.f);
	if (data->img.o)
		mlx_destroy_image(data->mlx_ptr, data->img.o);
	if (data->map)
		free_map(data);
	// if (data->win_ptr)
	// 	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	// if (data->mlx_ptr)
	// {
	// 	mlx_destroy_display(data->mlx_ptr);
	// 	free(data->mlx_ptr);
	// }
	exit_error(error_message);
}

void	free_wall_exit(char	*error_message, t_data *data)
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
	if (data->map)
		free_map(data);
	// if (data->win_ptr)
	// 	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	// if (data->mlx_ptr)
	// {
	// 	mlx_destroy_display(data->mlx_ptr);
	// 	free(data->mlx_ptr);
	// }
	exit_error(error_message);
}