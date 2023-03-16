/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouillo <jrouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:00:55 by jrouillo          #+#    #+#             */
/*   Updated: 2023/03/16 17:42:44 by jrouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	loop_hook(t_data *data)
{
	mlx_key_hook(data->win_ptr, &keypress, data);
	mlx_hook(data->win_ptr, ClientMessage, LeaveWindowMask,
		&buttonpress, data);
	mlx_loop_hook(data->mlx_ptr, &render_game, data);
	mlx_loop(data->mlx_ptr);
}

void	image_window(t_data *data)
{
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->win.x, data->win.y, TITLE);
	if (!data->win_ptr)
		exit_error(data, ERROR_INIT_WIN);
	xpm_images(data);
}

void	init_struct(t_data *data, char *map_filename)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		exit_error(data, ERROR_INIT_MLX);
	// data->win_ptr = NULL;
	// data->mlx_img = NULL;
	// data->map =  NULL;
	// data->map_copy = NULL;
	data->height = get_height(data, map_filename);
	data->width = get_width(data, map_filename);
	// data->moves = 0;
	// data->loop_count = 0;
	// data->collectibles = 0;
	// data->finish_game = 0;
	data->win.y = data->height * PXL;
	data->win.x = data->width * PXL;
}


int	main(int argc, char **argv)
{
	t_data	*data;

	data = ft_calloc(1, sizeof(t_data));
	if (!data)
		return (0);
	if (argc < 2)
		exit_error (data, ERROR_ARGC);
	map_filename(data, argv[1]);
	init_struct(data, argv[1]);
	data->map = get_map(data, argv[1]);
	if (!data->map)
	{
		free_maps(data);
		exit_error(data, ERROR_MAP_EMPTY);
	}
	check_map(data);
	image_window(data);
	loop_hook(data);
}
