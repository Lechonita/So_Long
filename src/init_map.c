/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouillo <jrouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:35:25 by jrouillo          #+#    #+#             */
/*   Updated: 2023/03/17 12:39:25 by jrouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_map_walls(t_data **data)
{
	t_map	map;

	map.y = -1;
	while (++map.y < (*data)->height)
	{
		if ((*data)->map[map.y][0] != '1'
			|| (*data)->map[map.y][ft_strlen((*data)->map[map.y]) - 1] != '1')
			exit_error(*data, ERROR_MAP_WALLS);
	}
	if (check_map_top_bottom(data))
		exit_error(*data, ERROR_MAP_WALLS);
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

char	**get_map(t_data *data, char *map_filename)
{
	int		fd;
	char	**map;
	int		i;

	if (data->height == 0)
		exit_error(data, ERROR_MAP_EMPTY);
	fd = open(map_filename, O_RDWR);
	if (fd < 0)
		exit_error(data, ERROR_MAP_FD);
	map = malloc(sizeof(char *) * (data->height + 1));
	if (map)
	{	
		i = 0;
		while (i < data->height)
		{
			map[i] = get_next_line(fd);
			if (!map[i])
				return (free_maps(data), NULL);
			if (map[i][ft_strlen(map[i]) - 1] == '\n')
				map[i][ft_strlen(map[i]) - 1] = '\0';
			i++;
		}
		close(fd);
	}
	return (map);
}

void	map_filename(t_data *data, char *argv)
{
	int	i;

	if (!argv)
		return ;
	i = ft_strlen(argv) - 1;
	if (argv[i] != 'r' || argv[i - 1] != 'e' || argv[i - 2] != 'b'
		|| argv[i - 3] != '.')
		exit_error (data, ERROR_MAP_FILE);
}