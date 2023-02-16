/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_valid_route_2.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouillo <jrouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 10:36:14 by jrouillo          #+#    #+#             */
/*   Updated: 2023/02/16 15:31:36 by jrouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_map(t_data **data, int y, int x)
{
	if ((*data)->map_copy[y][x + 1]
		&& (*data)->map_copy[y][x + 1] != '1'
		&& (*data)->map_copy[y][x + 1] != 'x')
	{
		(*data)->map_copy[y][x + 1] = 'x';
		flood_map(data, y, (x + 1));
	}
	if ((*data)->map_copy[y][x - 1]
		&& (*data)->map_copy[y][x - 1] != '1'
		&& (*data)->map_copy[y][x - 1] != 'x')
	{
		(*data)->map_copy[y][x - 1] = 'x';
		flood_map(data, y, (x - 1));
	}
	else
		flood_y(data, y, x);
}

void	flood_y(t_data **data, int y, int x)
{
	if ((*data)->map_copy[y + 1][x]
		&& (*data)->map_copy[y + 1][x] != '1'
		&& (*data)->map_copy[y + 1][x] != 'x')
	{
		(*data)->map_copy[y + 1][x] = 'x';
		flood_map(data, (y + 1), x);
	}
	if ((*data)->map_copy[y - 1][x]
		&& (*data)->map_copy[y - 1][x] != '1'
		&& (*data)->map_copy[y - 1][x] != 'x')
	{
		(*data)->map_copy[y - 1][x] = 'x';
		flood_map(data, (y - 1), x);
	}
}

int	is_path_valid(t_data *data)
{
	t_map	map;

	map.y = 0;
	while (map.y < data->height)
	{
		map.x = 0;
		while (data->map_copy[map.y][map.x])
		{
			if (data->map_copy[map.y][map.x] == 'C'
				|| data->map_copy[map.y][map.x] == 'E'
				|| data->map_copy[map.y][map.x] == 'P')
				return (1);
			map.x++;
		}
		map.y++;
	}
	return (0);
}