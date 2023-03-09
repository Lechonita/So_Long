/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouillo <jrouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 14:54:59 by jrouillo          #+#    #+#             */
/*   Updated: 2023/03/09 16:38:44 by jrouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	animate_player_left(t_data *data, int x, int y)
{
	int	i;

	i = 1;
	printf("i = %d\n", i);
	printf("x = %d\n", x);
	printf("y = %d\n", y);
	while (i <= SPEED_P)
	{
		printf("---------------\n");
		printf("i = %d\n", i);
		printf("x = %d\n", x);
		printf("y = %d\n", y);
		printf("x + (i / SPEED_P) * SIZE_PXL = %d\n", x + (i / SPEED_P) * SIZE_PXL);
		mlx_put_image_to_window(
				data->mlx_ptr, data->win_ptr, data->img.f, x * SIZE_PXL, y * SIZE_PXL);
		if (i == 1)
			mlx_put_image_to_window(
				data->mlx_ptr, data->win_ptr, data->player.p1_left, (x + i / SPEED_P) * SIZE_PXL, y * SIZE_PXL);
		else if (i == 2)
			mlx_put_image_to_window(
				data->mlx_ptr, data->win_ptr, data->player.p2_left, (x + i / SPEED_P) * SIZE_PXL, y * SIZE_PXL);
		else if (i == SPEED_P)
			mlx_put_image_to_window(
				data->mlx_ptr, data->win_ptr, data->player.p3_left, (x + i / SPEED_P) * SIZE_PXL, y * SIZE_PXL);
		i++;
	}
}
