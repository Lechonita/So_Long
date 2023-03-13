/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouillo <jrouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 12:33:06 by jrouillo          #+#    #+#             */
/*   Updated: 2023/03/13 11:47:48 by jrouillo         ###   ########.fr       */
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
		while(++map.x < data->width)
		{
			if (data->map[map.y][map.x] == 'C')
				data->collectibles++;
		}
	}
}

void	map_error_elements(t_data *data)
{
	int	y;

	y = -1;
	while (++y < data->height && data->map[y])
		free(data->map[y]);
	free(data->map);
	free(data);
	exit_error(data, ERROR_MAP_ELEMENTS);
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
				map_error_elements(*data);
		}
	}
	if (!map.c || map.e != 1 || map.p != 1)
		exit_error (*data, ERROR_MAP_ECP);
}

void	check_map_shape(t_data **data)
{
	t_map	map;

	map.y = -1;
	while(++map.y < (*data)->height)
	{
		if (ft_strlen((*data)->map[map.y]) != (*data)->width)
		{
			free_map(*data);
			exit_error(*data, ERROR_MAP_SHAPE);
		}
	}
}

void	check_map(t_data *data)
{
	check_map_shape(&data);
	check_map_chars(&data);
	check_map_walls(&data);
	check_map_valid_path(&data);
	count_collectibles(data);
}
