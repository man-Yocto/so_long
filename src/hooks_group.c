/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_group.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yocto <yocto@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 22:05:46 by yocto             #+#    #+#             */
/*   Updated: 2025/09/29 22:29:09 by yocto            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	move_up(t_game *game)
{
	move_player(game, game->p_y - 1, game->p_x);
}

void	move_down(t_game *game)
{
	move_player(game, game->p_y + 1, game->p_x);
}

void	move_left(t_game *game)
{
	move_player(game, game->p_y, game->p_x - 1);
}

void	move_right(t_game *game)
{
	move_player(game, game->p_y, game->p_x + 1);
}

int	handle_key(int keycode, t_game *game)
{
	if (keycode == KEY_W || keycode == KEY_UP)
		move_up(game);
	else if (keycode == KEY_A || keycode == KEY_LEFT)
		move_left(game);
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		move_down(game);
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
		move_right(game);
	else if (keycode == KEY_ESC)
	{
		close_window(game);
		exit(0);
	}
	return (0);
}
