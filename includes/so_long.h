/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouillo <jrouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:00:57 by jrouillo          #+#    #+#             */
/*   Updated: 2023/02/17 15:33:46 by jrouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "mlx.h"

# include <X11/X.h>
# include <X11/keysym.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdint.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE BUFSIZ
# endif

# define TITLE "So Long Suckers"
# define WIN_WIDTH 1920
# define WIN_HEIGHT 1080

# define GREEN 0x008000
# define RED 0x00FF0000
# define YELLOW 0xFFFF00
# define BLUE 0x00FFFF
# define WHITE 0xFFFFFF

# define ERROR_ARGC "Error\n >> Not enough arguments to launch program\n"
# define ERROR_INIT_MLX "Error\n >> MLX could not be initialized\n"
# define ERROR_INIT_WIN "Error\n >> Window could not be initialized\n"
# define ERROR_NO_MAP "Error\n >> No map has been selected\n"
# define ERROR_MAP_FILE "Error\n >> Map file type is incorrect\n"
# define ERROR_MAP_ELEMENTS "Error\n >> Wrong map element found (!01CEP)\n"
# define ERROR_MAP_ECP "Error\n >> Wrong quantity of Start, Exit and/or Item\n"
# define ERROR_MAP_WALLS "Error\n >> Map walls are incomplete\n"
# define ERROR_MAP_FD "Error\n >> Map file could not be opened\n"
# define ERROR_MAP_EMPTY "Error\n >> Map file is empty\n"
# define ERROR_MAP_SHAPE "Error\n >> Map shape incorrect\n"
# define ERROR_MAP_COPY "Error\n >> Map could not be copied\n"
# define ERROR_INVALID_ROUTE "Error\n >> This map has no possible path\n"

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp; /* bits per pixel */
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_win
{
	int		x;
	int		y;
} t_win;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	char	**map;
	char	**map_copy;
	int		height;
	int		width;
	t_img	img;
	t_win	win;
}	t_data;

typedef struct s_map
{
	void	*mlx_map;
	int		x;
	int		y;
	int		c;
	int		e;
	int		p;
}	t_map;

typedef struct s_rect
{
	int	x;
	int	y;
	int	width;
	int	height;
	int	color;
}	t_rect;

/* SO LONG */
int		put_pixel(t_data *data);

/* KEYS */
int		keypress(int key, t_data *data);
int		buttonpress(t_data *data);

/* RENDER IMAGE */
int		put_rectangle(t_img *img, t_rect rect);
void	render_background(t_img *img, int color);
void	img_pix_put(t_img *img, int x, int y, int color);
int		render(t_data *data);

/* WINDOW */
void	init_window(t_data data);

/* UTILS */
void	exit_error(char *error_message);

/************************************************************/
/**************************** MAP ***************************/
/************************************************************/

/* INIT MAP */
void	map_filename(char *argv);
int		get_width(t_data **data);
int		get_height(char *map_filename);
char	**get_map(t_data *data, char *map_filename);

/* CHECK MAP */
void	map_error_elements(t_data *data);
void	check_map_chars(t_data **data);
void	check_map_shape(t_data **data);
void	check_map(t_data *data);

/* CHECK MAP WALLS */
void	check_map_walls(t_data **data);
int		check_map_top_bottom(t_data **data);

/* VALID MAP ROUTE */
int		find_px(t_data **data);
int		find_py(t_data **data);
void	copy_map(t_data **data);
void	check_map_valid_path(t_data **data);

/* VALID MAP ROUTE 2 */
void	flood_map(t_data **data, int y, int x);
void	flood_y(t_data **data, int x, int y);
int		is_path_valid(t_data *data);

/* GNL */
char	*ft_free_strjoin(char *s1, char *s2);
char	*get_line(char *str, char *tmp);
char	*get_line_store(char *str);
char	*get_str(int fd, char *str);
char	*get_next_line(int fd);

/* FREE MAP*/
void	free_both_maps(t_data *data);
void	free_map(t_data *data);

#endif