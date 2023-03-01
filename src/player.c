/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouillo <jrouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 17:33:34 by jrouillo          #+#    #+#             */
/*   Updated: 2023/03/01 17:43:38 by jrouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void 	move_player(int key, t_data *data)
// {
// 	if (key == XK_w)
// }

int	player_pos_x(t_data *data)
{
	t_map	map;
	int		pos_x;

	map.y = -1;
	pos_x = 0;
	while (++map.y < data->height)
	{
		map.x = -1;
		while (++map.x < data->width)
		{
			if (data->map[map.y][map.x] == 'P')
				break;
		}
	}
	printf("map.x = %d\n", map.x);
	return (map.x);
}