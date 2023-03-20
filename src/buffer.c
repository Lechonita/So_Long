/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouillo <jrouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 16:12:27 by jrouillo          #+#    #+#             */
/*   Updated: 2023/03/20 17:56:27 by jrouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_buffer_size(t_data *data, char *map_filename)
{
	int		nbyte;
	int		fd;
	char	buffer[4096];
	int		i;

	printf("ENTER get buffer size\n");
	fd = open(map_filename, O_RDWR);
	if (fd < 0)
		exit_error(data, ERROR_MAP_FD);
	printf("TEST\n");
	nbyte = 1;
	while (nbyte > 0)
	{
		i = read(fd, buffer, 4096);
		printf("nbyte == %d\n", nbyte);
		if (i == 0)
			break ;
		if (i < 0)
			exit_error(data, ERROR_MAP_EMPTY);
		nbyte += i;
	}
	printf("nbyte == %d\n", nbyte);
	if (nbyte == 0)
		exit_error(data, ERROR_MAP_EMPTY);
	close (fd);
	return (nbyte);
}

char	*read_mapfile(t_data *data, char *map_filename)
{
	int		nbyte;
	int		fd;
	char	*buffer;

	printf("ENTER read mapfile\n");
	fd = open(map_filename, O_RDWR);
	if (fd < 0)
		exit_error(data, ERROR_MAP_FD);
	nbyte = get_buffer_size(data, map_filename);
	printf("%d\n", nbyte);
	buffer = malloc(sizeof(char) * (nbyte + 1));
	if (!buffer)
		exit_error(data, ERROR_MAP_EMPTY);
	if (read(fd, buffer, nbyte + 1) < 0)
	{
		free(buffer);
		exit_error(data, ERROR_MAP_EMPTY);
	}
	close(fd);
	buffer[nbyte] = '\0';
	printf("%s\n", buffer);
	return (buffer);
}

char	**get_map(t_data *data, char *buffer)
{
	char	**final_map;
	t_map	map;

	final_map = ft_split(buffer, '\n');
	map.y = 0;
	while (final_map[map.y] && map.y < data->height)
	{
		map.x = 0;
		printf("%s\n", final_map[map.y]);
		while (final_map[map.y][map.x] && map.x < data->width)
		{
			if (final_map[map.y][map.x] == '\n'
				&& final_map[map.y][map.x + 1] == '\n')
				exit_error(data, ERROR_MAP_SHAPE);
			if (final_map[map.y][map.x] == '\n')
				final_map[map.y][map.x] = '\0';
			map.x++;
		}
		map.y++;
	}
	return (final_map);
}
