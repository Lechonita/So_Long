/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouillo <jrouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 14:54:59 by jrouillo          #+#    #+#             */
/*   Updated: 2023/03/10 15:30:29 by jrouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void	animate_player_left(t_data *data, int x, int y)
// {
// 	int	i;
// 	int	x2;

// 	i = 1;
// 	x2 = x;
// 	printf("i = %d\n", i);
// 	printf("x = %d\n", x);
// 	printf("y = %d\n", y);
// 	while (i <= SPEED_P)
// 	{
// 		printf("---------------\n");
// 		printf("i = %d\n", i);
// 		printf("x = %d\n", x);
// 		printf("y = %d\n", y);
// 		printf("x + (i / SPEED_P) * SIZE_PXL = %d\n", x + (i / SPEED_P) * SIZE_PXL);
// 		mlx_put_image_to_window(
// 				data->mlx_ptr, data->win_ptr, data->img.f, x * SIZE_PXL, y * SIZE_PXL);
// 		if (i == 1)
// 			mlx_put_image_to_window(
// 				data->mlx_ptr, data->win_ptr, data->player.p_left_1, x2, y * SIZE_PXL);
// 		else if (i == 2)
// 			mlx_put_image_to_window(
// 				data->mlx_ptr, data->win_ptr, data->player.p_left_2, x2, y * SIZE_PXL);
// 		else if (i == SPEED_P)
// 			mlx_put_image_to_window(
// 				data->mlx_ptr, data->win_ptr, data->player.p_left_3, x2, y * SIZE_PXL);
// 		i++;
// 		x2 = x2 + (i / SPEED_P) * SIZE_PXL;
// 	}
// }

// void	animate_player_left(t_data *data, int x, int y)
// {
// 	static int	i;

// 	i = 1;
// 	if (i > 0 && i < SPEED_P)
// 		mlx_put_image_to_window(
//  			data->mlx_ptr, data->win_ptr, data->player.p_left_1, x * SIZE_PXL, y * SIZE_PXL);
// 	if (i >= SPEED_P && i < (SPEED_P * 4))
// 		mlx_put_image_to_window(
//  			data->mlx_ptr, data->win_ptr, data->player.p_left_2, x * SIZE_PXL, y * SIZE_PXL);
// 	if (i >= (SPEED_P * 4) && i < (SPEED_P * 8))
// 		mlx_put_image_to_window(
//  			data->mlx_ptr, data->win_ptr, data->player.p_left_3, x * SIZE_PXL, y * SIZE_PXL);
// 	if (i == (SPEED_P * 8))
// 		i = 0;
// 	i++;
// }

t_animation		*create_sprites(char *filename, t_data *data)
{
	t_animation		*new;
	char			*name;
	char			*full_filename;
	int				i;

	new = malloc(sizeof(t_animation));
	if (!new)
		return (NULL);
	i = 1;
	while (i <= ENEMY)
	{
		name = ft_strjoin(filename, ft_itoa(i));
		full_filename = ft_strjoin(name, ".xpm");
		printf("fullname = %s\n", full_filename);
		new->sprite = mlx_xpm_file_to_image(
		data->mlx_ptr, full_filename, &data->win.x, &data->win.y);
		free(name);
		free(full_filename);
		new = new->next;
		i++;
	}
	new->next = NULL;
	return (new);
}

void	put_sprites(char *filename, t_data *data, int y, int x)
{
	t_animation		*new;

	new = create_sprites(filename, data);
	while (new)
	{
		mlx_put_image_to_window(
			data->mlx_ptr, data->win_ptr, new->sprite, x * SIZE_PXL, y * SIZE_PXL);
		new = new->next;
	}
}
