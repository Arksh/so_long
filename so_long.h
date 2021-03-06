/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 14:54:08 by cagonzal          #+#    #+#             */
/*   Updated: 2022/06/07 11:18:42 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "basics.h"
# include <mlx.h>

/* Size of every sprite */
# define IMG_SIZE 64

// ---------- TILES

typedef enum e_tiletype
{
	EMPTY = '0',
	WALL = '1',
	COLLECTABLE = 'C',
	PLAYER = 'P',
	EXIT = 'E',
	ENEMY = 'M',
	FOLLOWER = 'F'
}	t_tiletype;

/* Struct for each tile */
typedef struct s_tile
{
	t_tiletype		type;
	t_tiletype		og_type;
	t_vector		position;
	struct s_tile	*up;
	struct s_tile	*down;
	struct s_tile	*left;
	struct s_tile	*right;
}	t_tile;

// ---------- IMAGES

/* All posible wall images */
typedef struct s_wall_img
{
	void	*block;
	void	*up_left;
	void	*up;
	void	*up_right;
	void	*right;
	void	*down_right;
	void	*down;
	void	*down_left;
	void	*left;
	void	*floor;
}	t_wall_img;

/* Collectables animation info */
typedef struct s_coll_img
{
	void	*current_img;
	int		anim_frames;
}	t_collect_img;

/* Info for the particle-like effect */
typedef struct s_effect
{
	void		*img;
	t_vector	pos;
	int			frames;
	int			counter;
}	t_effect;

/* An image that covers the whole window */
typedef struct s_panel
{
	void		*pointer;
	char		*pixels;
	t_vector	size;
	int			bpp;
	int			line_size;
	int			endian;
}	t_panel;

/* Color */
typedef struct s_color
{
	int	r;
	int	g;
	int	b;
	int	a;
}	t_color;

// ---------- ENEMIES

typedef enum e_enemytype
{
	HORIZONTAL_ENEM = 'H',
	VERTICAL_ENEM = 'V',
	FOLLOW_ENEM = 'F'
}	t_enemyytpe;

/* Enemies animation info */
typedef struct s_enemy_imgs
{
	int		basic_anim;
	void	*ver_current;
	void	*hor_current;
	void	*ver_imgs[2];
	void	*hor_imgs[2];
	int		follow_anim;
	void	*fol_current;
	void	*fol_imgs[2];
}	t_enemy_img;

/* Struct to make a list of enemies */
typedef struct s_enemy
{
	t_enemyytpe			type;
	int					dir;
	t_tile				*og_tile;
	t_tile				*tile;
	struct s_enemy		*next;
}	t_enemy;

// ---------- GAME

/* All valid input keys */
enum e_keycode
{
	KEY_UP = 13,
	KEY_DOWN = 1,
	KEY_LEFT = 0,
	KEY_RIGHT = 2,
	RESET = 15,
	ESC = 53
};

/* All valid input keys */
enum e_directions
{
	NORTH = 0,
	SOUTH = 1,
	EAST = 2,
	WEST = 3,
};

/* Info about the player */
typedef struct s_player
{
	t_tile	*tile;
	void	*current_img;
	int		direction;
	int		framecount;
	int		idle_frames;
	void	*anim_img[4];
	void	*idle_img[4];
}	t_player;

/* All info for the game run */
typedef struct s_game
{
	void			*mlx;
	void			*window;
	t_vector		wndw_size;
	t_tile			**tilemap;
	t_player		player;
	int				og_collects;
	int				collects;
	int				moves;
	t_enemy			*enemy_list;
	t_vector		img_size;
	t_wall_img		wall_imgs;
	t_collect_img	collects_imgs;
	t_enemy_img		enemy_imgs;
	void			*door_open_img;
	void			*door_close_img;
	t_effect		effect;
	void			*red_panel;
	void			*white_panel;
}	t_game;

// ---------------------------
// FUNCTIONS

t_bool	start(t_game *game, int argc, char **argv);

t_color	new_color(int r, int g, int b, int a);
void	*new_panel(t_game *game, t_color color);

int		input(int key, t_game *game);
int		update(t_game *game);
void	render(t_game game);
void	draw_wall(t_tile tile, t_game game, t_vector pos);

void	effect_anim(t_effect *effect, t_vector pos);

void	remove_player(t_game *game);
void	kill_player(t_game *game, t_vector pos);
int		reset(t_game *game);
int		end_program(t_game *game);

#endif