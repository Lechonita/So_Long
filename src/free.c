/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouillo <jrouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 12:11:45 by jrouillo          #+#    #+#             */
/*   Updated: 2023/04/04 16:34:00 by jrouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_maps(t_data *data)
{
	int	i;

	i = 0;
	if (!data->map)
		return ;
	while (i < data->height && data->map[i])
	{
		free(data->map[i]);
		if (data->map_copy)
			free(data->map_copy[i]);
		i++;
	}
	free(data->map);
	free(data->map_copy);
	free(data);
	return ;
}

void	free_close(t_data *data)
{
	if (data->win_ptr)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	if (data->mlx_ptr)
	{
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
	}
	if (data->map)
		free_maps(data);
	else
		free(data);
}

void	free_all_exit(char	*error_message, t_data *data)
{
	free_img(data);
	free_wall_img(data);
	free_sprites_img(data);
	free_lose(data);
	free_close(data);
	write(1, error_message, ft_strlen(error_message));
	exit (0);
}
