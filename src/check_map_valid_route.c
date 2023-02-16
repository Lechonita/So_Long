/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_valid_route.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouillo <jrouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 17:31:40 by jrouillo          #+#    #+#             */
/*   Updated: 2023/02/16 17:41:51 by jrouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	find_px(t_data **data)
{
	t_map	map;

	map.y = 0;
	while ((*data)->map_copy[map.y])
	{
		map.x = 0;
		while ((*data)->map_copy[map.y][map.x])
		{
			if ((*data)->map_copy[map.y][map.x] == 'P')
				return (map.x) ;
			map.x++;
		}
		map.y++;
	}
	return (0);
}

int	find_py(t_data **data)
{
	t_map	map;

	map.y = 0;
	while ((*data)->map_copy[map.y])
	{
		map.x = 0;
		while ((*data)->map_copy[map.y][map.x])
		{
			if ((*data)->map_copy[map.y][map.x] == 'P')
				return (map.y) ;
			map.x++;
		}
		map.y++;
	}
	return (0);
}

void	copy_map(t_data **data)
{
	char	*line;
	char	*copy_lines;
	int		i;

	i = 0;
	copy_lines = ft_calloc(1, 1);
	if (!copy_lines)
		return ;
	while  (i < (*data)->height)
	{
		line = ft_strjoin((*data)->map[i], "\n");
		if (!line)
			return ;
		copy_lines = ft_free_strjoin(copy_lines, line);
		free(line);
		if (!copy_lines)
			return ;
		i++;
	}
	if (copy_lines[0] == '\0')
	{
		free(copy_lines);
		exit_error(ERROR_MAP_COPY);
	}
	(*data)->map_copy = ft_split(copy_lines, '\n');
	free(copy_lines);
}

void	check_map_valid_path(t_data **data)
{
	copy_map(data);
	if (!(*data)->map_copy)
 		exit_error(ERROR_MAP_COPY);
	flood_map(data, find_py(data), find_px(data));
	if(is_path_valid(*data))
	{
		free_both_maps(*data);
		exit_error(ERROR_INVALID_ROUTE);
	}
}