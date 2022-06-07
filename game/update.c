/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 16:59:04 by cagonzal          #+#    #+#             */
/*   Updated: 2022/06/07 11:03:53 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	player_animation(t_player *player)
{
	if (player->framecount == player->idle_frames)
		player->current_img = player->anim_img[player->direction];
	else if (player->framecount >= player->idle_frames * 2)
	{
		player->current_img = player->idle_img[player->direction];
		player->framecount = 0;
	}
	player->framecount += 1;
}

static void	effect_animation(t_effect *effect)
{
	if (effect->counter < effect->frames)
		effect->counter++;
}

static void	enemy_animation(t_enemy_img *img)
{
	static int	basic_count;
	static int	follower_count;

	if (basic_count == img->basic_anim)
	{
		img->ver_current = img->ver_imgs[1];
		img->hor_current = img->hor_imgs[1];
	}
	else if (basic_count > img->basic_anim * 2)
	{
		img->ver_current = img->ver_imgs[0];
		img->hor_current = img->hor_imgs[0];
		basic_count = 0;
	}
	basic_count++;
	if (follower_count == img->follow_anim)
		img->fol_current = img->fol_imgs[1];
	else if (follower_count > img->follow_anim * 2)
	{
		img->fol_current = img->fol_imgs[0];
		follower_count = 0;
	}
	follower_count++;
}

/* Calculates all animations and render.
* Called once each frame */
int	update(t_game *game)
{
	player_animation(&game->player);
	effect_animation(&game->effect);
	enemy_animation(&game->enemy_imgs);
	render(*game);
	return (1);
}
