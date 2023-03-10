/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouillo <jrouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:00:57 by jrouillo          #+#    #+#             */
/*   Updated: 2023/03/10 15:30:23 by jrouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "ft_printf.h"
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

# define GREEN 0x008000
# define RED 0x00FF0000
# define YELLOW 0xFFFF00
# define BLUE 0x00FFFF
# define WHITE 0xFFFFFF

# define SIZE_PXL 64
# define SPEED_P 4
# define ENEMY 5

# define ERROR_ARGC "Error\n >> Not enough arguments to launch program\n"
# define ERROR_INIT_MLX "Error\n >> MLX could not be initialized\n"
# define ERROR_INIT_WIN "Error\n >> Window could not be initialized\n"
# define ERROR_NO_MAP "Error\n >> No map has been selected\n"
# define ERROR_MAP_FILE "Error\n >> Map file type is incorrect\n"
# define ERROR_MAP_ELEMENTS "Error\n >> Wrong map element found (!01CEP)\n"
# define ERROR_MAP_ECP "Error\n >> Wrong quantity of Start, Exit and/or Item\n"
# define ERROR_MAP_WALLS "Error\n >> Map walls are incomplete\n"
# define ERROR_MAP_FD "Error\n >> Map file could not be opened\n"
// # define ERROR_MAP_FDW "Error\n >> Map file could not be opened (width)\n"
// # define ERROR_MAP_FDH "Error\n >> Map file could not be opened (height)\n"
# define ERROR_MAP_EMPTY "Error\n >> Map file is empty\n"
# define ERROR_MAP_SHAPE "Error\n >> Map shape incorrect\n"
# define ERROR_MAP_COPY "Error\n >> Map could not be copied\n"
# define ERROR_INVALID_ROUTE "Error\n >> This map has no possible path\n"
# define ERROR_IMG_CONVERT "Error\n >> Could not convert xpm non-wall image\n"
# define ERROR_IMG_WALL_CONVERT "Error\n >> Could not convert xpm wall image\n"
# define ERROR_IMG_PLAYER_CONVERT "Error\n >> Could not convert xpm player image\n"
# define WIN "\n\n  ===> YOU WIN ! <===\n\n"

typedef struct s_animation
{
	char					*sprite;
	struct s_animation		*next;
} t_animation;

typedef struct s_player
{
	int 	pos_x;
	int 	pos_y;
	char	*p_idle;
	char	*p_right_1;
	char	*p_right_2;
	char	*p_right_3;
	char	*p_left_1;
	char	*p_left_2;
	char	*p_left_3;
}	t_player;

typedef struct s_img
{
	// char	*addr;
	// int		bpp; /* bits per pixel */
	// int		line_len;
	// int		endian;
	char	*c;
	char	*e_open;
	char	*e_closed;
	char	*w_top;
	char	*w_bottom;
	char	*w_right;
	char	*w_left;
	char	*w_topright;
	char	*w_topleft;
	char	*w_bottomright;
	char	*w_bottomleft;
	char	*f;
	char	*o;
}	t_img;

typedef struct s_win
{
	int		x;
	int		y;
} t_win;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*mlx_img;
	char		**map;
	char		**map_copy;
	int			height;
	int			width;
	int			moves;
	int			collectibles;
	int			game_finish;
	t_img		img;
	t_win		win;
	t_player	player;
	t_animation	animation;
}	t_data;

typedef struct s_map
{
	int		x;
	int		y;
	int		c;
	int		e;
	int		p;
}	t_map;


/* INIT */
void	init_win_struct(t_data *data);
void	init_player_struct(t_data *data);
void	init_img_struct(t_data *data);
void	init_data_struct(t_data *data, char *map_filename);
void	init_struct(t_data *data, char *map_filename);

/* KEYS */
int		keypress(int key, t_data *data);
int		buttonpress(t_data *data);

/* PLAYER */
void	do_movement(t_data *data, int x, int y, int key);
int		move_ok(t_data *data, int x, int y, int key);
void	move_player(int key, t_data *data);

/* UTILS */
char	*ft_strjoin_char(const char *s, int i);
void	exit_error(t_data *data, char *error_message);
int		get_width(t_data *data,char *map_filename);
int		get_height(t_data *data,char *map_filename);

void	display_map(t_data *data);

/* IMAGE */
int		display_game(t_data *data);
void	xpm_player_images(t_data *data);
void	xpm_wall_images(t_data *data);
void	xpm_images(t_data *data);

/* CHOOSE IMAGE */
void	image_corner(t_data *data, int y, int x);
void	image_top_bottom_wall(t_data *data, int y, int x);
void	image_side_wall(t_data *data, int y, int x);
void	image_center(t_data *data, int y, int x);
void	choose_image(t_data *data, int y, int x);

/* FREE */
void	free_both_maps(t_data *data);
void	free_map(t_data *data);
void	free_img(t_data *data);
void	free_wall_img(t_data *data);
void	free_all_exit(char	*error_message, t_data *data);
void	free_close(t_data *data);

/* ANIMATION */
// void			animate_player_left(t_data *data, int x, int y);
t_animation		*create_sprites(char *filename, t_data *data);
void			put_sprites(char *filename, t_data *data, int y, int x);

/************************************************************/
/**************************** MAP ***************************/
/************************************************************/

/* INIT MAP */
void			check_map_walls(t_data **data);
int				check_map_top_bottom(t_data **data);
char			**get_map(t_data *data, char *map_filename);
void			map_filename(t_data *data, char *argv);

/* CHECK MAP */
void	count_collectibles(t_data *data);
void	map_error_elements(t_data *data);
void	check_map_chars(t_data **data);
void	check_map_shape(t_data **data);
void	check_map(t_data *data);

/* VALID MAP ROUTE */
int		is_path_valid(t_data *data);
int		find_px(t_data **data);
int		find_py(t_data **data);
void	copy_map(t_data **data);
void	check_map_valid_path(t_data **data);

/* FLOOD */
void	flood_map(t_data **data, int y, int x);
void	flood_y(t_data **data, int x, int y);

/* GNL */
char	*ft_free_strjoin(char *s1, char *s2);
char	*get_line(char *str, char *tmp);
char	*get_line_store(char *str);
char	*get_str(int fd, char *str);
char	*get_next_line(int fd);

#endif