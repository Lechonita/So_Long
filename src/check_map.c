/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouillo <jrouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 12:33:06 by jrouillo          #+#    #+#             */
/*   Updated: 2023/04/04 16:33:52 by jrouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	count_collectibles(t_data *data)
{
	t_map	map;

	map.y = -1;
	while (++map.y < data->height)
	{
		map.x = -1;
		while (++map.x < data->width)
		{
			if (data->map[map.y][map.x] == 'C')
				data->collectibles++;
		}
	}
	return ;
}

void	check_map_chars(t_data **data)
{
	t_map	map;

	map.c = 0;
	map.e = 0;
	map.p = 0;
	map.y = -1;
	while (++map.y < (*data)->height)
	{
		map.x = -1;
		while ((*data)->map[map.y][++map.x])
		{
			if ((*data)->map[map.y][map.x] == 'C')
				map.c += 1;
			else if ((*data)->map[map.y][map.x] == 'E')
				map.e += 1;
			else if ((*data)->map[map.y][map.x] == 'P')
				map.p += 1;
			else if ((*data)->map[map.y][map.x] != '1'
				&& (*data)->map[map.y][map.x] != '0'
				&& (*data)->map[map.y][map.x] != 'M')
				exit_error(*data, ERROR_MAP_ELEMENTS);
		}
	}
	if (!map.c || map.e != 1 || map.p != 1)
		exit_error (*data, ERROR_MAP_ECP);
}

void	check_map_shape(t_data **data)
{
	t_map	map;

	map.y = -1;
	while (++map.y < (*data)->height)
	{
		if (ft_strlen((*data)->map[map.y]) != (*data)->width)
			exit_error(*data, ERROR_MAP_SHAPE);
	}
	if ((*data)->height > 21)
		exit_error(*data, ERROR_MAP_SIZE);
	if ((*data)->width > 39)
		exit_error(*data, ERROR_MAP_SIZE);
}

void	check_map(t_data *data)
{
	check_map_shape(&data);
	check_map_chars(&data);
	check_map_walls(&data);
	check_map_valid_path(&data);
	count_collectibles(data);
}
