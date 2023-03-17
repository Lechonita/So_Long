/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouillo <jrouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:00:57 by jrouillo          #+#    #+#             */
/*   Updated: 2023/03/17 18:39:54 by jrouillo         ###   ########.fr       */
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

# define PXL 64
# define NBR_PXL 16
# define RATE 120

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
# define ERROR_MAP_SIZE "Error\n >> Map size too big\n"
# define ERROR_MAP_COPY "Error\n >> Map could not be copied\n"
# define ERROR_INVALID_ROUTE "Error\n >> This map has no possible path\n"
# define ERROR_IMG_CONVERT "Error\n >> Could not convert xpm non-wall image\n"
# define ERROR_IMG_WALL_CONVERT "Error\n >> Could not convert xpm wall image\n"
# define ERROR_IMG_WALK_CONVERT "Error\n >> Could not convert xpm walk image\n"
# define ERROR_IMG_IDLE_CONVERT "Error\n >> Could not convert xpm idle image\n"
# define ERROR_IMG_NBR_CONVERT "Error\n >> Could not convert xpm nbr image\n"
# define ERROR_IMG_NM_CONVERT "Error\n >> Could not convert xpm enemy image\n"
# define ERROR_IMG_END_CONVERT "Error\n >> Could not convert xpm end image\n"
# define ERROR_IMG_LOSE_CONVERT "Error\n >> Could not convert xpm lose image\n"
# define WIN "\n\n  ===> YOU WIN ! <===\n\n"
# define DEAD "\n\n ===> WASTED <===\n\n"
# define LOSE "\n\n ===> YOU LOSE <===\n\n"
# define QUIT "\n  EXIT GAME\n"

typedef struct s_bonus
{
	void	*enemy[3];
	void	*numbers[10];
	void	*lose[3];
}	t_bonus;

typedef struct s_player
{
	int		pos_x;
	int		pos_y;
	int		direction;
	int		p_animate;
	int		p_win;
	int		p_dead;
	void	*p_idle[10];
	void	*p_walk[8];
}	t_player;

typedef struct s_img
{
	void	*c;
	void	*e_open;
	void	*e_closed;
	void	*e_end[3];
	void	*w_top;
	void	*w_bottom;
	void	*w_right;
	void	*w_left;
	void	*w_topright;
	void	*w_topleft;
	void	*w_bottomright;
	void	*w_bottomleft;
	void	*f;
	void	*o;
}	t_img;

typedef struct s_win
{
	int		x;
	int		y;
}	t_win;

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
	int			loop_count;
	int			collectibles;
	int			finish_game;
	t_img		img;
	t_win		win;
	t_player	player;
	t_bonus		bonus;
}	t_data;

typedef struct s_map
{
	int		x;
	int		y;
	int		c;
	int		e;
	int		p;
}	t_map;

/* SO LONG */
void	loop_hook(t_data *data);
void	image_window(t_data *data);
void	init_struct(t_data *data, char *map_filename);

/* KEYS */
int		keypress(int key, t_data *data);
int		buttonpress(t_data *data);

/* UTILS */
void	exit_error(t_data *data, char *error_message);
int		get_width(t_data *data, char *map_filename);
int		get_height(t_data *data, char *map_filename);
int		find_px(t_data *data);
int		find_py(t_data *data);

/* XPM IMAGES */
void	xpm_idle_left_images(t_data *data);
void	xpm_idle_right_images(t_data *data);
void	xpm_wall_images(t_data *data);
void	xpm_center_images(t_data *data);
void	xpm_images(t_data *data);

/* XPM IMAGES 2 */
void	xpm_lose_images(t_data *data);
void	xpm_end_images(t_data *data);
void	xpm_numbers_images(t_data *data);
void	xpm_enemy_images(t_data *data);
void	xpm_walk_images(t_data *data);

/* RENDER MAP */
void	choose_image(t_data *data, int y, int x, int i);
int		display_game(t_data *data, int i);
int		render_game(t_data *data);

/* IMAGE WALLS */
void	image_numbers(t_data *data);
void	image_corner(t_data *data, int y, int x);
void	image_top_bottom_wall(t_data *data, int y, int x);
void	image_side_wall(t_data *data, int y, int x);

/* IMAGE CENTER */
void	render_lose_sprites(t_data *data, int i);
void	render_monster_sprites(t_data *data, int y, int x, int i);
void	image_exit(t_data *data, int y, int x);
void	image_center(t_data *data, int y, int x, int i);

/* PLAYER */
void	player_death(t_data *data, int x, int y);
void	do_movement(t_data *data, int x, int y, int key);
int		move_ok(t_data *data, int x, int y, int key);
void	move_player(int key, t_data *data);

/* WIN LOSE */
void	lose_game(t_data *data);
void	win_game(t_data *data, int x, int y);

/* PLAYER SPRITES */
void	walk_player_left(t_data *data, int i);
void	walk_player_right(t_data *data, int i);
void	idle_player_left(t_data *data, int i);
void	idle_player_right(t_data *data, int i);
void	render_player_sprites(t_data *data, int i);

/* FREE */
void	free_maps(t_data *data);
void	free_close(t_data *data);
void	free_all_exit(char	*error_message, t_data *data);

/* FREE IMG */
void	free_lose(t_data *data);
void	free_sprites_img(t_data *data);
void	free_wall_img(t_data *data);
void	free_img(t_data *data);

/************************************************************/
/**************************** MAP ***************************/
/************************************************************/

/* INIT MAP */
void	check_map_walls(t_data **data);
int		check_map_top_bottom(t_data **data);
char	**get_map(t_data *data, char *map_filename);
void	map_filename(t_data *data, char *argv);

/* CHECK MAP */
void	count_collectibles(t_data *data);
void	check_map_chars(t_data **data);
void	check_map_shape(t_data **data);
void	check_map(t_data *data);

/* VALID MAP ROUTE */
int		is_path_valid(t_data *data);
void	flood_map(t_data **data, int y, int x);
void	flood_y(t_data **data, int x, int y);
void	copy_map(t_data **data);
void	check_map_valid_path(t_data **data);

/* GNL */
char	*ft_free_strjoin(char *s1, char *s2);
char	*get_line(char *str, char *tmp);
char	*get_line_store(char *str);
char	*get_str(int fd, char *str);
char	*get_next_line(int fd);

#endif