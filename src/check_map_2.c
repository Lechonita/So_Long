/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouillo <jrouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 17:13:47 by jrouillo          #+#    #+#             */
/*   Updated: 2023/02/11 16:30:27 by jrouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_map_edges(int fd)
{
	char	*line;
	int		len;

	line = get_next_line(fd);
	while (line)
	{
		len = ft_strlen(line);
		if (line[0] != '1' || line[len - 1] != '1')
			exit_error(ERROR_MAP_EDGES);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
}

void	check_map_top_bottom(int fd, int count_lines)
{
	char	*line;
	int		i;
	int		j;

	i = -1;
	j = 1;
	line = get_next_line(fd);
	while (line)
	{
		if (j == 1 || j == count_lines)
		{
			while (line[++i])
			{
				if (line[i] != '1')
					exit_error(ERROR_MAP_TOP_BOTTOM);
			}
		}
		j++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
}

char	**get_map(char *map_doc)
{
	int		fd;
	char	*line;
	char	*map_lines;

	fd = (map_doc, O_RDONLY);
	if (fd < 0)
		exit_error(ERROR_MAP_FD);
	line = get_next_line(fd);
	map_lines = ft_strdup("");
	while (line)
	{
		map_lines = ft_strjoin(map_lines, line);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	if (map_lines[0] == '\0')
		exit_error(ERROR_MAP_EMPTY);
	return (ft_split(map_lines, '\n'));
}
