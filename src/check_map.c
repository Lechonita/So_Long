/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouillo <jrouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 12:33:06 by jrouillo          #+#    #+#             */
/*   Updated: 2023/02/11 17:36:12 by jrouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_map_file(char *argv)
{
	int	i;

	if (!argv)
		return ;
	i = ft_strlen(argv) - 1;
	if (argv[i] != 'r' || argv[i - 1] != 'e' || argv[i - 2] != 'b'
		|| argv[i - 3] != '.')
		exit_error (ERROR_MAP_FILE);
}

void	map_error_elements(t_data **data)
{
	int	y;

	y = -1;
	while ((*data)->map[++y])
		free((*data)->map[y]);
	free((*data)->map);
	exit_error(ERROR_MAP_ELEMENTS);
}

void	check_map_chars(t_data **data)
{
	t_map	map;

	map.c = 0;
	map.e = 0;
	map.p = 0;
	map.y = count_map_lines((*data)->map) - 1;
	while (map.y)
	{
		map.x = 0;
		while ((*data)->map[map.y][map.x])
		{
			if ((*data)->map[map.y][map.x] == 'C')
				map.c += 1;
			else if ((*data)->map[map.y][map.x] == 'E')
				map.e += 1;
			else if ((*data)->map[map.y][map.x] == 'P')
				map.p += 1;
			else if ((*data)->map[map.y][map.x] != '1'
				&& (*data)->map[map.y][map.x] != '0')
				map_error_elements(data);
			map.x++;
		}
		map.y--;
	}
	printf("map.c = %d\n", map.c);
	printf("map.e = %d\n", map.e);
	printf("map.p = %d\n", map.p);
	if (!map.c || map.e != 1 || map.p != 1)
		exit_error (ERROR_MAP_ECP);
}

int	count_map_lines(char **map)
{
	int		count;

	count = 0;
	while (map[count])
		count++;
	return (count);
}

void	check_map(t_data *data)
{
	int		count_lines;

	count_lines = count_map_lines(data->map);
	printf("count lines = %d\n", count_lines);
	// check_map_chars(&data);
	// check_map_edges(&data);
	// check_map_top_bottom(&data, count_lines);
}
