/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouillo <jrouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 12:11:45 by jrouillo          #+#    #+#             */
/*   Updated: 2023/02/17 15:31:48 by jrouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_both_maps(t_data *data)
{
	int i;

	i = -1;
	if (!data->map)
		return ;
	while (++i < data->height && data->map[i])
	{
	 	free(data->map[i]);
	 	free(data->map_copy[i]);
	}
	free(data->map);
	free(data->map_copy);
	free(data);
}

void	free_map(t_data *data)
{
	int i;

	i = -1;
	while (++i < data->height && data->map[i])
		free(data->map[i]);
	free(data->map);
	free(data);
}
