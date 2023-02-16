/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_walls.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouillo <jrouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 17:13:47 by jrouillo          #+#    #+#             */
/*   Updated: 2023/02/16 17:18:54 by jrouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_map_walls(t_data **data)
{
	t_map	map;

	map.y = 0;
	while (map.y < (*data)->height)
	{
		if ((*data)->map[map.y][0] != '1'
			|| (*data)->map[map.y][ft_strlen((*data)->map[map.y]) - 1] != '1')
			{
				free_map(*data);
				exit_error(ERROR_MAP_WALLS);
			}
		map.y++;
	}
	if (check_map_top_bottom(data))
	{
		free_map(*data);
		exit_error(ERROR_MAP_WALLS);
	}
		
}

int	check_map_top_bottom(t_data **data)
{
	t_map	map;

	map.y = (*data)->height - 1;
	map.x = 0;
	while ((*data)->map[0][map.x])
	{
		if ((*data)->map[0][map.x] != '1')
			return (1);
		map.x++;
	}
	map.x = 0;
	while ((*data)->map[map.y][map.x])
	{
		if ((*data)->map[map.y][map.x] != '1')
			return (1);
		map.x++;
	}
	return (0);
}


