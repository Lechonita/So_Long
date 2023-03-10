/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouillo <jrouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 14:31:43 by jrouillo          #+#    #+#             */
/*   Updated: 2023/03/10 15:06:57 by jrouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_error(t_data *data, char *error_message)
{
	write (1, error_message, ft_strlen(error_message));
	free_close(data);
	exit (0);
}

int	get_width(t_data *data,char *map_filename)
{
	int		fd;
	int		width;
	char	*line;

	fd = open(map_filename, O_RDWR);
	if (fd < 0)
		exit_error(data, ERROR_MAP_FD);
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

int	get_height(t_data *data,char *map_filename)
{
	int		fd;
	int		height;
	char	*line;

	fd = open(map_filename, O_RDWR);
	if (fd < 0)
		exit_error(data, ERROR_MAP_FD);
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

/* TO BE REMOVED */

void	display_map(t_data *data)
{
	int		y;
	int		x;

	y = -1;
	while (++y < data->height)
	{
		x = -1;
		while (++x < data->width)
		{
			// printf("  y = %d     ", y);
			printf("%c", data->map[y][x]);
		}
		printf("\n");
	}
}
