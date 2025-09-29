/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yocto <yocto@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 21:46:13 by yocto             #+#    #+#             */
/*   Updated: 2025/09/29 22:21:26 by yocto            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	game_win(t_game *game)
{
	write(1, "You win!\n", 10);
	close_window(game);
	exit(0);
}

void	game_lose(t_game *game)
{
	write(1, "You lose!\n", 10);
	close_window(game);
	exit(0);
}

void	on_e(t_game *game, int code)
{
	if (code == 0)
	{
		game->on_exit = 0;
		game->img_player = game->img_player_normal;
	}
	else
	{
		game->on_exit = 1;
		game->img_player = game->img_player_on_exit;
	}
}

void	move_on_exit(t_game *game, int new_y, int new_x)
{
	update_prev_tile(game);
	on_e(game, 1);
	update_player_pos(game, new_y, new_x);
}

void	move_on_floor(t_game *game, int new_y, int new_x, int can_move)
{
	if (can_move == 4)
		game->c_c--;
	update_prev_tile(game);
	on_e(game, 0);
	update_player_pos(game, new_y, new_x);
}
