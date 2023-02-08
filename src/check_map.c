/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouillo <jrouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 12:33:06 by jrouillo          #+#    #+#             */
/*   Updated: 2023/02/08 18:23:22 by jrouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_map_file(char *argv)
{
	int	i;

	if (!argv)
		return ;
	i = ft_strlen(argv) - 1;
	if (argv[i] != "r" || argv[i - 1] != "e" || argv[i - 2] != "b"
		|| argv[i - 3] != ".")
		exit_error (ERROR_MAP_FILE);
}

void	check_map_chars(int fd)
{
	char	*line;
	int		e;
	int		c;
	int		p;

	line = get_next_line(fd);
	while (line)
	{
		if (strchr("E", line))
			e += 1;
		if (strchr("C", line))
			c += 1;
		if (strchr("P", line))
			p += 1;
		if (!strchr("01CEP", line))
			exit_error(ERROR_MAP_ELEMENTS);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	if (e != 1 || p != 1 || !c)
		exit_error (ERROR_MAP_ECP);
}

void	check_map_edges(int fd)
{
	char	*line;
	int		len;

	line = get_next_line(fd);
	while (line)
	{
		len = ft_strlen(line);
		if (line[0] != "1" || line[len - 1] != "1")
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
				if (line[i] != "1")
					exit_error(ERROR_MAP_TOP_BOTTOM);
			}
		}
		j++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
}

void	check_map(t_data data, int argc, char *argv)
{
	int		fd;
	char	*line;
	int		count_lines;

	check_map_file(argv);
	fd = open(argv[argc -1], O_RDONLY);
	if (!fd)
		return ;
	line = get_next_line(fd);
	while (line)
	{
		count_lines += 1;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	check_map_chars(fd);
	check_map_edges(fd);
	check_map_top_bottom(fd, count_lines);
}
