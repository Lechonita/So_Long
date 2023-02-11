/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouillo <jrouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:00:55 by jrouillo          #+#    #+#             */
/*   Updated: 2023/02/11 17:37:57 by jrouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int put_pixel(t_data *data)
{
	if (data->win_ptr)
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, WIN_WIDTH / 2, WIN_HEIGHT / 2, RED);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc < 2)
		exit_error (ERROR_ARGC);
	check_map_file(argv[1]);
	data.map = get_map(argv[1]);
	if (!data.map)
		return (0);
	check_map(&data);
	
	// data.mlx_ptr = mlx_init();
	// if (!data.mlx_ptr)
	// 	exit_error(ERROR_INIT_MLX);
	// data.win_ptr = mlx_new_window(data.mlx_ptr, WIN_WIDTH, WIN_HEIGHT, TITLE);
	// if (!data.win_ptr)
	// exit_error(ERROR_INIT_WIN);

	// /* create image */
	// data.img.mlx_img = mlx_new_image(data.mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	// data.img.addr = mlx_get_data_addr(data.img.mlx_img, &data.img.bpp,
	// 		&data.img.line_len, &data.img.endian);

	// /* hooks */
	// mlx_loop_hook(data.mlx_ptr, &render, &data);
	// mlx_key_hook(data.win_ptr, &keypress, &data);
	// mlx_hook(data.win_ptr, ClientMessage, LeaveWindowMask,
	// 	&buttonpress, &data);

	// mlx_loop(data.mlx_ptr);

	// /* destroy / close window */
	// mlx_destroy_image(data.mlx_ptr, data.img.mlx_img);
	// mlx_destroy_display(data.mlx_ptr);
	// free(data.mlx_ptr);
}
