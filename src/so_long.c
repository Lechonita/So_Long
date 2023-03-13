/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouillo <jrouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:00:55 by jrouillo          #+#    #+#             */
/*   Updated: 2023/03/13 17:17:29 by jrouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (0);
	if (argc < 2)
		exit_error (data, ERROR_ARGC);
	map_filename(data, argv[1]);
	init_struct(data, argv[1]);
	data->map = get_map(data, argv[1]);
	if (!data->map)
		exit_error(data, ERROR_MAP_EMPTY);
	check_map(data);

	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		exit_error(data, ERROR_INIT_MLX);
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->win.x, data->win.y, TITLE);
	if (!data->win_ptr)
		exit_error(data, ERROR_INIT_WIN);

	xpm_images(data);

	/* hooks */
	mlx_loop_hook(data->mlx_ptr, &loop_hook, data);
	printf("TEST\n");
	mlx_key_hook(data->win_ptr, &keypress, data);
	printf("TEST\n");
	mlx_hook(data->win_ptr, ClientMessage, LeaveWindowMask,
		&buttonpress, data);
	printf("TEST\n");

	mlx_loop(data->mlx_ptr);

	/* destroy / close window */
	mlx_destroy_image(data->mlx_ptr, data->mlx_img);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	free_both_maps(data);
}
