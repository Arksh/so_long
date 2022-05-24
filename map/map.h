/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 10:49:25 by cagonzal          #+#    #+#             */
/*   Updated: 2022/05/24 12:20:13 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "../basics.h"
# include "../libft/libft.h"
# include "../so_long.h"

char	**read_map(char *file);
int		valid_file(int argc, char *file);
int		valid_map(char **map);
int		valid_char(char c);
int		valid_uniquechar(char c, char checker, t_bool *bool);
int		valid_border(char c, t_vector point, t_vector size);

typedef struct s_mapcheckerdata
{
	t_vector	size;
	t_vector	point;
	t_bool		b_player;
	t_bool		b_exit;
	t_bool		b_collect;
}	t_mapcheckerdata;

void	add_enemy(t_game *game, t_enemyytpe type, t_tile *tile);

#endif
