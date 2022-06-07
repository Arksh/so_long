/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 12:22:29 by cagonzal          #+#    #+#             */
/*   Updated: 2022/06/07 11:12:04 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	reset_enemies(t_enemy *enemy)
{
	if (enemy == NULL)
		return ;
	while (TRUE)
	{
		enemy->tile = enemy->og_tile;
		enemy->dir = 0;
		if (enemy->next == NULL)
			break ;
		enemy = enemy->next;
	}	
}

/* Returns the game to its original state */
int	reset(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->tilemap[y] != NULL)
	{
		x = 0;
		while (game->tilemap[y][x].type != 0)
		{
			game->tilemap[y][x].type = game->tilemap[y][x].og_type;
			if (game->tilemap[y][x].type == PLAYER)
			{
				game->player.tile = &game->tilemap[y][x];
				game->player.direction = SOUTH;
			}
			x++;
		}
		y++;
	}
	reset_enemies(game->enemy_list);
	game->moves = 0;
	game->collects = game->og_collects;
	mlx_put_image_to_window(game->mlx, game->window, game->white_panel, 0, 0);
	return (0);
}
