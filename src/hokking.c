/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hokking.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yocto <yocto@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 21:46:17 by yocto             #+#    #+#             */
/*   Updated: 2025/09/29 22:20:11 by yocto            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	can_move_to(t_game *game, int y, int x)
{
	char	next;

	next = game->map[y][x];
	if (next == '1')
		return (0);
	else if (next == 'E' && game->c_c > 0)
		return (1);
	else if (next == 'E')
		return (2);
	else if (next == 'X')
		return (3);
	else if (next == 'C')
		return (4);
	else if (next == '0')
		return (5);
	return (0);
}

void	move_player(t_game *game, int new_y, int new_x)
{
	int	can_move;

	can_move = can_move_to(game, new_y, new_x);
	if (can_move == 1)
		move_on_exit(game, new_y, new_x);
	else if (can_move == 2)
		game_win(game);
	else if (can_move == 3)
		game_lose(game);
	else if (can_move == 4 || can_move == 5)
		move_on_floor(game, new_y, new_x, can_move);
	else
		return ;
	update_and_draw(game);
}

void	update_prev_tile(t_game *game)
{
	if (game->on_exit)
		game->map[game->p_y][game->p_x] = 'E';
	else
		game->map[game->p_y][game->p_x] = '0';
}

void	update_player_pos(t_game *game, int new_y, int new_x)
{
	game->p_y = new_y;
	game->p_x = new_x;
	game->map[game->p_y][game->p_x] = 'P';
}

void	update_and_draw(t_game *game)
{
	game->moves++;
	printf("Moves: %d\n", game->moves);
	draw_map(game);
}
