/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 14:44:55 by cagonzal          #+#    #+#             */
/*   Updated: 2022/06/07 11:13:51 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	move_enemies(t_game *game);
void	move_to_empty(t_game *game, t_tile *tile);
void	move_to_exit(t_game *game, t_tile *tile);
void	pick_collect(t_game *game, t_tile *tile);
void	move_to_enemy(t_game *game, t_tile *tile);

/* Places and starts the "particles" effect */
void	effect_anim(t_effect *effect, t_vector pos)
{
	effect->counter = 0;
	effect->pos = pos;
}

/* Move the player to <tile> doing whats needed based on its type */
t_bool	move_to(t_game *game, t_tile *tile, int dir)
{
	if (game->player.direction != dir)
	{
		game->player.direction = dir;
		game->player.current_img = game->player.idle_img[dir];
	}
	if (tile->type == EMPTY)
		move_to_empty(game, tile);
	else if (tile->type == COLLECTABLE)
		pick_collect(game, tile);
	else if (tile->type == EXIT && game->collects <= 0)
		move_to_exit(game, tile);
	else if (tile->type == ENEMY)
	{
		move_to_enemy(game, tile);
		return (FALSE);
	}
	else
		return (FALSE);
	move_enemies(game);
	return (TRUE);
}

/* Input management. Called each time a key is pressed. */
int	input(int key, t_game *game)
{
	t_bool	moved;

	if (key == ESC)
		end_program(game);
	else if (key == RESET || game->player.tile == NULL)
		return (reset(game));
	if (key == KEY_UP)
		moved = move_to(game, game->player.tile->up, NORTH);
	else if (key == KEY_DOWN)
		moved = move_to(game, game->player.tile->down, SOUTH);
	else if (key == KEY_LEFT)
		moved = move_to(game, game->player.tile->left, WEST);
	else if (key == KEY_RIGHT)
		moved = move_to(game, game->player.tile->right, EAST);
	else
		return (0);
	if (moved)
		printf("Moves -> %02d\n", ++game->moves);
	return (1);
}
