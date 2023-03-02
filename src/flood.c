/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouillo <jrouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 15:34:42 by jrouillo          #+#    #+#             */
/*   Updated: 2023/03/02 15:39:41 by jrouillo         ###   ########.fr       */
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
