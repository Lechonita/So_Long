/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouillo <jrouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:35:25 by jrouillo          #+#    #+#             */
/*   Updated: 2023/02/17 15:30:03 by jrouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_filename(char *argv)
{
	int	i;

	if (!argv)
		return ;
	i = ft_strlen(argv) - 1;
	if (argv[i] != 'r' || argv[i - 1] != 'e' || argv[i - 2] != 'b'
		|| argv[i - 3] != '.')
		exit_error (ERROR_MAP_FILE);
}

int	get_width(t_data **data)
{
	int		width;
	t_map	map;
	
	map.y = 0;
	width = 0;
	while ((*data)->map[map.y][width])
		width++;
	return (width);
}

int	get_height(char *map_filename)
{
	int		fd;
	int		height;
	char	*line;

	fd = open(map_filename, O_RDONLY);
	if (fd < 0)
		exit_error(ERROR_MAP_FD);
	height = 0;
	line = get_next_line(fd);
	while (line)
	{
		height++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (height);
}

char	**get_map(t_data *data, char *map_filename)
{
	int		fd;
	char	**map;
	int		i;

	data->height = get_height(map_filename);
	if (data->height == 0)
		exit_error(ERROR_MAP_EMPTY);
	map = malloc(sizeof(char *) * (data->height + 1));
	if (!map)
		return (NULL);
	fd = open(map_filename, O_RDONLY);
	if (fd < 0)
		exit_error(ERROR_MAP_FD);
	i = 0;
	while (i < data->height)
	{
		map[i] = get_next_line(fd);
		if (!map[i])
			return (free_map(data), NULL);
		if (map[i][ft_strlen(map[i]) - 1] == '\n')
			map[i][ft_strlen(map[i]) - 1] = '\0';
		i++;
	}
	close(fd);
	return (map);
}
