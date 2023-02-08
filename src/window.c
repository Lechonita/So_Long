/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouillo <jrouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 11:48:27 by jrouillo          #+#    #+#             */
/*   Updated: 2023/02/08 12:16:23 by jrouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void	init_window(t_data data)
// {
// 	data.mlx_ptr = mlx_init();
// 	if (!data.mlx_ptr)
// 	{
// 		write(1, ERROR_INIT_MLX, ft_strlen(ERROR_INIT_MLX));
// 		return ;
// 	}
// 	data.win_ptr = mlx_new_window(data.mlx_ptr, WIN_WIDTH, WIN_HEIGHT, TITLE);
// 	if (!data.win_ptr)
// 	{
// 		free(data.win_ptr);
// 		write(1, ERROR_INIT_WIN, ft_strlen(ERROR_INIT_WIN));
// 		return ;
// 	}
// }