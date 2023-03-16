/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouillo <jrouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 15:44:16 by jrouillo          #+#    #+#             */
/*   Updated: 2023/03/16 16:37:33 by jrouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_numbers_img(t_data *data)
{
	printf("free numbers = %p\n", data->bonus.numbers[0]);
	if (data->bonus.numbers[0])
		mlx_destroy_image(data->mlx_ptr, data->bonus.numbers[0]);
	if (data->bonus.numbers[1])
		mlx_destroy_image(data->mlx_ptr, data->bonus.numbers[1]);
	if (data->bonus.numbers[2])
		mlx_destroy_image(data->mlx_ptr, data->bonus.numbers[2]);
	if (data->bonus.numbers[3])
		mlx_destroy_image(data->mlx_ptr, data->bonus.numbers[3]);
	if (data->bonus.numbers[4])
		mlx_destroy_image(data->mlx_ptr, data->bonus.numbers[4]);
	if (data->bonus.numbers[5])
		mlx_destroy_image(data->mlx_ptr, data->bonus.numbers[5]);
	if (data->bonus.numbers[6])
		mlx_destroy_image(data->mlx_ptr, data->bonus.numbers[6]);
	if (data->bonus.numbers[7])
		mlx_destroy_image(data->mlx_ptr, data->bonus.numbers[7]);
	if (data->bonus.numbers[8])
		mlx_destroy_image(data->mlx_ptr, data->bonus.numbers[8]);
	if (data->bonus.numbers[9])
		mlx_destroy_image(data->mlx_ptr, data->bonus.numbers[9]);
}

void	free_enemy_img(t_data *data)
{
	printf("free enemy = %p\n", data->bonus.enemy[0]);
	if (data->bonus.enemy[0])
		mlx_destroy_image(data->mlx_ptr, data->bonus.enemy[0]);
	if (data->bonus.enemy[1])
		mlx_destroy_image(data->mlx_ptr, data->bonus.enemy[1]);
	if (data->bonus.enemy[2])
		mlx_destroy_image(data->mlx_ptr, data->bonus.enemy[2]);
}

void	free_idle_img(t_data *data)
{
	printf("free idle 0 = %p\n", data->player.p_idle[0]);
	if (data->player.p_idle[0])
		mlx_destroy_image(data->mlx_ptr, data->player.p_idle[0]);
	printf("TEST idle\n");
	printf("free idle 1 = %p\n", data->player.p_idle[1]);
	if (data->player.p_idle[1])
		mlx_destroy_image(data->mlx_ptr, data->player.p_idle[1]);
	if (data->player.p_idle[2])
		mlx_destroy_image(data->mlx_ptr, data->player.p_idle[2]);
	if (data->player.p_idle[3])
		mlx_destroy_image(data->mlx_ptr, data->player.p_idle[3]);
	if (data->player.p_idle[4])
		mlx_destroy_image(data->mlx_ptr, data->player.p_idle[4]);
	if (data->player.p_idle[5])
		mlx_destroy_image(data->mlx_ptr, data->player.p_idle[5]);
	if (data->player.p_idle[6])
		mlx_destroy_image(data->mlx_ptr, data->player.p_idle[6]);
	if (data->player.p_idle[7])
		mlx_destroy_image(data->mlx_ptr, data->player.p_idle[7]);
	if (data->player.p_idle[8])
		mlx_destroy_image(data->mlx_ptr, data->player.p_idle[8]);
	if (data->player.p_idle[9])
		mlx_destroy_image(data->mlx_ptr, data->player.p_idle[9]);
}

void	free_walk_img(t_data *data)
{
	printf("free walk = %p\n", data->player.p_walk[0]);
	if (data->player.p_walk[0])
		mlx_destroy_image(data->mlx_ptr, data->player.p_walk[0]);
	if (data->player.p_walk[1])
		mlx_destroy_image(data->mlx_ptr, data->player.p_walk[1]);
	if (data->player.p_walk[2])
		mlx_destroy_image(data->mlx_ptr, data->player.p_walk[2]);
	if (data->player.p_walk[3])
		mlx_destroy_image(data->mlx_ptr, data->player.p_walk[3]);
	if (data->player.p_walk[4])
		mlx_destroy_image(data->mlx_ptr, data->player.p_walk[4]);
	if (data->player.p_walk[5])
		mlx_destroy_image(data->mlx_ptr, data->player.p_walk[5]);
	if (data->player.p_walk[6])
		mlx_destroy_image(data->mlx_ptr, data->player.p_walk[6]);
	if (data->player.p_walk[7])
		mlx_destroy_image(data->mlx_ptr, data->player.p_walk[7]);
}

void	free_end_img(t_data *data)
{
	printf("free end = %p\n", data->img.e_end[0]);
	if (data->img.e_end[0])
		mlx_destroy_image(data->mlx_ptr, data->img.e_end[0]);
	if (data->img.e_end[1])
		mlx_destroy_image(data->mlx_ptr, data->img.e_end[1]);
	if (data->img.e_end[2])
		mlx_destroy_image(data->mlx_ptr, data->img.e_end[2]);
	if (data->img.e_end[3])
		mlx_destroy_image(data->mlx_ptr, data->img.e_end[3]);
}