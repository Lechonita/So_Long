/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_valid_route.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouillo <jrouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 17:31:40 by jrouillo          #+#    #+#             */
/*   Updated: 2023/02/15 18:11:44 by jrouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_map_valid_path(t_data **data, int count_lines)
{
	t_map	map;

	map.y = count_lines - 1;
	// printf("count lines = %d\n", count_lines);
	copy_map(data, map.y);
	// printf("map.y = %d\n", map.y);
	// printf("(*data)->map_copy[y] = %s\n", (*data)->map_copy[0]);
	if (!(*data)->map_copy)
 		exit_error(ERROR_MAP_COPY);
	// printf("(*data)->map_copy[y][x] = %d\n", (*data)->map_copy[map.y][10]);
	flood_map(data, find_py(data), find_px(data));
	if(is_path_valid(*data, count_lines))
		exit_error(ERROR_INVALID_ROUTE);
}

void	copy_map(t_data **data, int y)
{
	char	*line;
	char	*copy_lines;
	int		i;

	i = 0;
	copy_lines = ft_calloc(1, 1);
	if (!copy_lines)
		return ;
	// printf("y = %d\n", y);
	while  (i <= y)
	{
		// line = ft_strdup((*data)->map[i]);
		line = ft_free_strjoin((*data)->map[i], "\n");
		if (!line)
			return ;
		// printf("line = %s\n", line);
		copy_lines = ft_free_strjoin(copy_lines, line);
		if (!copy_lines)
			return (free(line));
		// printf("copy_lines = %s\n", copy_lines);
		i++;
	}
	free(line);
	if (copy_lines[0] == '\0')
	{
		free(copy_lines);
		exit_error(ERROR_MAP_COPY);
	}
	(*data)->map_copy = ft_split(copy_lines, '\n');
	// printf("(*data)->map_copy[y] = %s\n", (*data)->map_copy[4]);
	free(copy_lines);
}

void	flood_map(t_data **data, int y, int x)
{
	printf("in FLOOD MAP = %s\n", (*data)->map_copy[y]);
	printf("x = %d\n", x);
	printf("y = %d\n", y);
	if ((*data)->map_copy[y][x])
	{
		flood_x(data, y, x);
		flood_y(data, y ,x);
	}
}

int	find_py(t_data **data)
{
	t_map	map;

	map.y = 0;
	// printf("in find_py = %s\n", (*data)->map_copy[4]);
	while ((*data)->map_copy[map.y])
	{
		map.x = 0;
		while ((*data)->map_copy[map.y][map.x])
		{
			if ((*data)->map_copy[map.y][map.x] == 'P')
			{
				// printf("map.y = %d\n", map.y);
				return (map.y) ;
			}
			map.x++;
		}
		map.y++;
	}
	// printf("or map.y = %d\n", map.x);
	return (0);
}

int	find_px(t_data **data)
{
	t_map	map;

	map.y = 0;
	// printf("in find_px = %s\n", (*data)->map_copy[4]);
	while ((*data)->map_copy[map.y])
	{
		// printf("map.y = %d\n", map.y);
		map.x = 0;
		// printf("map.x = %d\n", map.x);
		while ((*data)->map_copy[map.y][map.x])
		{
			// printf("map.x = %d\n", map.x);
			if ((*data)->map_copy[map.y][map.x] == 'P')
			{
				// printf("FOUND map.x = %d\n", map.x);
				return (map.x) ;
			}
			map.x++;
		}
		map.y++;
	}
	// printf("or map.x = %d\n", map.y);
	return (0);
}
