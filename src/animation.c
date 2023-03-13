/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouillo <jrouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 14:54:59 by jrouillo          #+#    #+#             */
/*   Updated: 2023/03/13 17:20:20 by jrouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	animate_player(t_data *data, int walk)
{
	printf("direction = %d\n", data->player.direction);
	if (data->player.direction == 0)
		data->player.p_image = data->player.p_walk[walk];
	else if (data->player.direction == 1)
		data->player.p_image = data->player.p_walk[walk + 3];
}

void	idle_player(t_data *data, int idle)
{
	printf("direction = %d\n", data->player.direction);
	if (data->player.direction == 0)
		data->player.p_image = data->player.p_idle[idle];
	else if (data->player.direction == 1)
		data->player.p_image = data->player.p_idle[idle + 5];
}