/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_lose.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouillo <jrouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 18:10:29 by jrouillo          #+#    #+#             */
/*   Updated: 2023/04/04 16:34:32 by jrouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	lose_game(t_data *data)
{
	data->finish_game = 1;
	ft_printf(LOSE);
	return ;
}

void	win_game(t_data *data, int x, int y)
{
	data->finish_game = 1;
	data->map[data->player.pos_y][data->player.pos_x] = '0';
	data->map[y][x] = 'E';
	data->moves += 1;
	ft_printf("Move #%d\n", data->moves);
	ft_printf(WIN);
	data->player.p_win = 1;
	return ;
}
