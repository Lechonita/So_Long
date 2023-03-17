/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouillo <jrouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 12:49:28 by jrouillo          #+#    #+#             */
/*   Updated: 2023/03/17 12:11:31 by jrouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	keypress(int key, t_data *data)
{
	if (key == XK_w || key == XK_a || key == XK_s || key == XK_d)
		move_player(key, data);
	if (key == XK_Escape && data->win_ptr)
		free_all_exit(QUIT, data);
	return (0);
}

int	buttonpress(t_data *data)
{
	free_all_exit(QUIT, data);
	return (0);
}
