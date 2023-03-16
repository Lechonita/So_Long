/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouillo <jrouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 14:54:59 by jrouillo          #+#    #+#             */
/*   Updated: 2023/03/16 12:24:51 by jrouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void	choose_image(t_data *data, int y, int x)
// {
// 	if ((y == 0 && x == 0) || (y == 0 && x == data->width - 1)
// 		|| (y == data->height - 1 && x == 0)
// 		|| (y == data->height - 1 && x == data->width - 1))
// 		image_corner(data, y, x);
// 	else if ((y == 0) && (x > 0 && x < (data->width - 1))
// 		|| (y == data->height - 1) && (x > 0 && x < (data->width - 1)))
// 		image_top_bottom_wall(data, y, x);
// 	else if ((x == 0) && (y >= 0 || y <= (data->height - 1))
// 		|| (x == data->width - 1) && ((y >= 0 || y <= (data->height - 1))))
// 		image_side_wall(data, y, x);
// 	else
// 		image_center(data, y, x);
// }

void	choose_image(t_data *data, int y, int x, int i)
{
	if (y == 0)
	{
		if ((x == 0) || (x == data->width - 1)
		|| (y == data->height - 1 && x == data->width - 1))
			image_corner(data, y, x);
		else if (x > 0 && x < (data->width - 1))
			image_top_bottom_wall(data, y, x);
	}
	else if (x == 0)
	{
		if (y == data->height - 1)
			image_corner(data, y, x);
		else if (y >= 0 || y <= (data->height - 1))
			image_side_wall(data, y, x);
	}
	else if (x != 0 && y != 0)
	{
		if (y == data->height - 1 && x == data->width - 1)
			image_corner(data, y, x);
		else if ((y == data->height - 1) && (x > 0 && x < (data->width - 1)))
			image_top_bottom_wall(data, y, x);
		else if ((x == data->width - 1) && ((y >= 0 || y <= (data->height - 1))))
			image_side_wall(data, y, x);
		else
			image_center(data, y, x, i);
	}
}

int	display_game(t_data *data, int i)
{
	t_map	map;

	map.y = -1;
	while (++map.y < data->height)
	{
		map.x = -1;
		while (++map.x < data->width)
			choose_image(data, map.y, map.x, i);
	}
	return (0);
}

int	render_game(t_data *data)
{
	static int	i;

	if (i++ <= RATE)
	{
		display_game(data, i);
		if (i == RATE)
		{
			i = 0;
			data->player.p_animate = 0;
		}
	}
	return (0);
}
