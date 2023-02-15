/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouillo <jrouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 17:13:47 by jrouillo          #+#    #+#             */
/*   Updated: 2023/02/15 18:22:41 by jrouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_map_walls(t_data **data, int count_lines)
{
	t_map	map;

	map.y = count_lines - 1;
	while (map.y >= 0)
	{
		// printf("(*data)->map[map.y][0] = %d\n", (*data)->map[map.y][0]);
		if ((*data)->map[map.y][0] != '1'
			|| (*data)->map[map.y][ft_strlen((*data)->map[map.y]) - 1] != '1')
			exit_error(ERROR_MAP_WALLS);
		map.y--;
	}
	if (check_map_top_bottom(data, count_lines))
		exit_error(ERROR_MAP_WALLS);
}

int	check_map_top_bottom(t_data **data, int count_lines)
{
	t_map	map;

	map.y = count_lines - 1;
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

char	**get_map(char *map_filename)
{
	int		fd;
	char	*line;
	char	*map_lines;
	char	**map;
	// char	*map_filepath;

	// map_filepath = ft_strjoin("maps/", map_filename);
	fd = open(map_filename, O_RDONLY);
	if (fd < 0)
		exit_error(ERROR_MAP_FD);
	line = get_next_line(fd);
	map_lines = ft_calloc(1, 1);
	if (!map_lines)
		return (NULL);
	while (line)
	{
		map_lines = ft_free_strjoin(map_lines, line);
		if (!map_lines)
			return (NULL);
		// printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	if (map_lines[0] == '\0')
		exit_error(ERROR_MAP_EMPTY);
	map = ft_split(map_lines, '\n');
	return (free(map_lines), map);
}

void	check_map_shape(t_data **data, int count_lines)
{
	t_map	map;
	int		tmp;

	map.y = 0;
	map.x = 0;
	tmp = 0;
	while (map.y < count_lines)
	{
		map.x = ft_strlen((*data)->map[map.y]) - 1;
		if (tmp != 0)
		{
			if (tmp != map.x)
				exit_error(ERROR_MAP_SHAPE);
		}
		else
			tmp = map.x;
		map.y++;
	}
}
