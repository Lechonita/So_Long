/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouillo <jrouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:00:55 by jrouillo          #+#    #+#             */
/*   Updated: 2023/02/20 17:22:47 by jrouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// int put_pixel(t_data *data)
// {
// 	if (data->win_ptr)
// 		mlx_pixel_put(data->mlx_ptr, data->win_ptr, WIN_WIDTH / 2, WIN_HEIGHT / 2, RED);
// 	return (0);
// }

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->win_ptr + (y * data->img.line_len + x * (data->img.bpp / 8));
	*(unsigned int*)dst = color;
}

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc < 2)
		exit_error (ERROR_ARGC);
	map_filename(argv[1]);
	data = malloc(sizeof(t_data));
	if (!data)
		return (0);
	data->map = get_map(data, argv[1]);
	if (!data->map)
		exit_error(ERROR_MAP_EMPTY);
	check_map(data);
	
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		exit_error(ERROR_INIT_MLX);
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, TITLE);
	if (!data->win_ptr)
		exit_error(ERROR_INIT_WIN);
	
	xpm_images(data);
	xpm_wall_images(data);

	// /* hooks */
	mlx_loop_hook(data->mlx_ptr, &display_game, &data);
	mlx_key_hook(data->win_ptr, &keypress_escape, &data);
	mlx_hook(data->win_ptr, ClientMessage, LeaveWindowMask,
		&buttonpress, &data);

	mlx_loop(data->mlx_ptr);

	// /* destroy / close window */
	mlx_destroy_image(data->mlx_ptr, data->img.mlx_img);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	free_both_maps(data);
}
