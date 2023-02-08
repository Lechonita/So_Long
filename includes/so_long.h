/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouillo <jrouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:00:57 by jrouillo          #+#    #+#             */
/*   Updated: 2023/02/08 16:13:06 by jrouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "mlx.h"

#include <X11/X.h>
#include <X11/keysym.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

#define TITLE "TBD"
#define WIN_WIDTH 1920
#define WIN_HEIGHT 1080

#define GREEN 0x008000
#define RED 0x00FF0000
#define YELLOW 0xFFFF00
#define BLUE 0x00FFFF
#define WHITE 0xFFFFFF

#define ERROR_ARGC "Error\n ==> Not enough arguments to launch program\n"
#define ERROR_INIT_MLX "Error\n ==> MLX could not be initialized\n"
#define ERROR_INIT_WIN "Error\n ==> Window could not be initialized\n"
#define ERROR_NO_MAP "Error\n ==> No map has been selected. Please select a map to launch program\n"
#define ERROR_MAP_FILE "Error\n ==> Map file type is incorrect\n"
#define ERROR_MAP_ELEMENTS "Error\n ==> One of your map elements is not allowed (!= 01CEP)\n"
#define ERROR_MAP_ECP "Error\n ==> Quantity of Start point, Exit point and/or Item is invalid\n"
#define ERROR_MAP_EDGES "Error\n ==> Map edges are invalid\n"
#define ERROR_MAP_TOP_BOTTOM "Error\n ==> Map top or bottom edge is invalid\n"

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp; /* bits per pixel */
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
}	t_data;

typedef struct	s_map
{
	void	*mlx_map;
}	t_map;

typedef struct s_rect
{
	int	x;
	int	y;
	int width;
	int height;
	int color;
}	t_rect;

/* SO LONG */
int 	put_pixel(t_data *data);

/* KEYS */
int		keypress(int key, t_data *data);
int		buttonpress(t_data *data);

/* RENDER IMAGE */
int		put_rectangle(t_img *img, t_rect rect);
void	render_background(t_img *img, int color);
void	img_pix_put(t_img *img, int x, int y, int color);
int		render(t_data *data);

/* WINDOW */
// void	init_window(t_data data);

/* UTILS */
void	exit_error(char *error_message);

#endif