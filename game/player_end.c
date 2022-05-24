/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_end.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 14:47:56 by cagonzal          #+#    #+#             */
/*   Updated: 2022/05/19 12:40:06 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	kill_player(t_game *game, t_vector pos)
{
	game->player.tile = NULL;
	effect_anim(&game->effect, pos);
	mlx_put_image_to_window(game->mlx, game->window, game->red_panel, 0, 0);
}

void	remove_player(t_game *game)
{
	game->player.tile->type = EMPTY;
	game->player.tile = NULL;
}
