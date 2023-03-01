/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouillo <jrouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:35:25 by jrouillo          #+#    #+#             */
/*   Updated: 2023/03/01 17:05:33 by jrouillo         ###   ########.fr       */
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

int	get_width(char *map_filename)
{
	int		fd;
	int		width;
	char	*line;

	fd = open(map_filename, O_RDWR);
	if (fd < 0)
		exit_error(ERROR_MAP_FD);
	line = get_next_line(fd);
	width = ft_strlen(line) - 1;
	while (line)
	{
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return(width);
}

int	get_height(char *map_filename)
{
	int		fd;
	int		height;
	char	*line;

	fd = open(map_filename, O_RDWR);
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
	return(height);
}

char	**get_map(t_data *data, char *map_filename)
{
	int		fd;
	char	**map;
	int		i;

	if (data->height == 0)
		exit_error(ERROR_MAP_EMPTY);
	fd = open(map_filename, O_RDWR);
	if (fd < 0)
		exit_error(ERROR_MAP_FD);
	map = malloc(sizeof(char *) * (data->height + 1));
	if (!map)
		return (NULL);
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
