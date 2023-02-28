/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouillo <jrouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 12:13:59 by jrouillo          #+#    #+#             */
/*   Updated: 2023/02/28 16:23:54 by jrouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// int	display_game(t_data *data)
// {
// 	t_map	map;

// 	map.y = -1;
// 	while (++map.y < data->height)
// 	{
// 		map.x = -1;
// 		while (++map.x < data->width)
// 		{
			
// 			mlx_put_image_to_window(
// 			data->mlx_ptr, data->win_ptr, data->img.p_right,
// 			map.x * SIZE_PXL, map.y * SIZE_PXL);
// 		}
// 	}
// 	return (0);
// }

// void	init_images(t_data *data)
// {
// 	data->img.p_right = "./images_xpm/pig_right.xpm";
// }

// void	xpm_images(t_data *data)
// {
// 	int	width;
// 	int	height;

// 	data->img.p_right = mlx_xpm_file_to_image(
// 		data->mlx_ptr, data->img.p_right, &width, &height);
// 	if (!data->img.p_right)
// 		free_image_exit(data);
// }

// void	free_image_exit(t_data *data)
// {
// 	if (data->img.p_right)
// 		mlx_destroy_image(data->mlx_ptr, data->img.p_right);
// 	if (data->map)
// 		free_map(data);
// 	// if (data->win_ptr)
// 	// 	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
// 	// if (data->mlx_ptr)
// 	// {
// 	// 	mlx_destroy_display(data->mlx_ptr);
// 	// 	free(data->mlx_ptr);
// 	// }
// 	exit_error("Could not display image");
// }
