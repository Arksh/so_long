/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 10:19:21 by cagonzal          #+#    #+#             */
/*   Updated: 2022/06/07 11:19:02 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	open_wallimgs_up(t_game *game);
void	open_wallimgs_down(t_game *game);

static void	open_player_imgs(t_game *game)
{
	game->player.idle_img[NORTH] = mlx_xpm_file_to_image(game->mlx,
			"sprites/player_N00.xpm", &game->img_size.x, &game->img_size.y);
	game->player.anim_img[NORTH] = mlx_xpm_file_to_image(game->mlx,
			"sprites/player_N01.xpm", &game->img_size.x, &game->img_size.y);
	game->player.idle_img[SOUTH] = mlx_xpm_file_to_image(game->mlx,
			"sprites/player_S00.xpm", &game->img_size.x, &game->img_size.y);
	game->player.anim_img[SOUTH] = mlx_xpm_file_to_image(game->mlx,
			"sprites/player_S01.xpm", &game->img_size.x, &game->img_size.y);
	game->player.idle_img[EAST] = mlx_xpm_file_to_image(game->mlx,
			"sprites/player_E00.xpm", &game->img_size.x, &game->img_size.y);
	game->player.anim_img[EAST] = mlx_xpm_file_to_image(game->mlx,
			"sprites/player_E01.xpm", &game->img_size.x, &game->img_size.y);
	game->player.idle_img[WEST] = mlx_xpm_file_to_image(game->mlx,
			"sprites/player_W00.xpm", &game->img_size.x, &game->img_size.y);
	game->player.anim_img[WEST] = mlx_xpm_file_to_image(game->mlx,
			"sprites/player_W01.xpm", &game->img_size.x, &game->img_size.y);
	game->player.current_img = game->player.idle_img[SOUTH];
	game->player.direction = SOUTH;
}

static void	open_collect_imgs(t_game *game)
{
	game->collects_imgs.current_img = mlx_xpm_file_to_image(game->mlx,
			"sprites/coll_close.xpm", &game->img_size.x, &game->img_size.y);
	game->effect.img = mlx_xpm_file_to_image(game->mlx,
			"sprites/effect_w.xpm", &game->img_size.x, &game->img_size.y);
}

static void	open_enemy_imgs(t_game *game)
{
	game->enemy_imgs.ver_imgs[0] = mlx_xpm_file_to_image(game->mlx,
			"sprites/en_v_anim_1.xpm", &game->img_size.x, &game->img_size.y);
	game->enemy_imgs.ver_imgs[1] = mlx_xpm_file_to_image(game->mlx,
			"sprites/en_v_anim_2.xpm", &game->img_size.x, &game->img_size.y);
	game->enemy_imgs.hor_imgs[0] = mlx_xpm_file_to_image(game->mlx,
			"sprites/en_h_anim_1.xpm", &game->img_size.x, &game->img_size.y);
	game->enemy_imgs.hor_imgs[1] = mlx_xpm_file_to_image(game->mlx,
			"sprites/en_h_anim_2.xpm", &game->img_size.x, &game->img_size.y);
	game->enemy_imgs.ver_current = game->enemy_imgs.ver_imgs[0];
	game->enemy_imgs.hor_current = game->enemy_imgs.hor_imgs[0];
	game->enemy_imgs.fol_imgs[0] = mlx_xpm_file_to_image(game->mlx,
			"sprites/en_f_anim_1.xpm", &game->img_size.x, &game->img_size.y);
	game->enemy_imgs.fol_imgs[1] = mlx_xpm_file_to_image(game->mlx,
			"sprites/en_f_anim_2.xpm", &game->img_size.x, &game->img_size.y);
	game->enemy_imgs.fol_current = game->enemy_imgs.fol_imgs[0];
}

static void	open_door_imgs(t_game *game)
{
	game->door_open_img = mlx_xpm_file_to_image(game->mlx,
			"sprites/door_01.xpm", &game->img_size.x, &game->img_size.y);
	game->door_close_img = mlx_xpm_file_to_image(game->mlx,
			"sprites/door_02.xpm", &game->img_size.x, &game->img_size.y);
}

/* Opens with the mlx all images needed in the game */
void	open_images(t_game *game)
{
	open_wallimgs_up (game);
	open_wallimgs_down (game);
	open_player_imgs(game);
	open_collect_imgs(game);
	open_enemy_imgs(game);
	open_door_imgs(game);
}
