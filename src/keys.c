/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouillo <jrouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 12:49:28 by jrouillo          #+#    #+#             */
/*   Updated: 2023/02/20 11:38:18 by jrouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	keypress_escape(int key, t_data *data)
{
	if (key == XK_Escape && data->win_ptr)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
	}
	return (0);
}

// int	keypress_movements(int key, t_data *data)
// {
// 	static int	i;

// 	if (ft_strchr("wasd", key))
// 	{
// 		i += 1;
// 		printf("%d\n", i);
// 	}
// 	return (0);
// }

int	buttonpress(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	data->win_ptr = NULL;
	return (0);
}
