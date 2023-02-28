/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouillo <jrouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 14:31:43 by jrouillo          #+#    #+#             */
/*   Updated: 2023/02/28 10:33:15 by jrouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_error(char *error_message)
{
	write (1, error_message, ft_strlen(error_message));
	exit (0);
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
			printf("%c", data->map[y][x]);
	}
}