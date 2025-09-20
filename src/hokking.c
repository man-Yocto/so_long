#include "../includes/so_long.h"


int can_move_to(game_t *game, int y, int x)
{
    char next = game->map[y][x];
    if (next == '1')
        return (0);// Wall, cannot move
    else if (next == 'E' && game->C_c > 0)
        return (1);// allow standing on exit, but not winning yet
    else if(next == 'E')
        return (2);// allow moving onto exit if no collectibles left
    else if(next == 'X')
        return (3);// enemy so dead
    else if (next == 'C')
        return (4);// collectible-- and update the map
    else if (next == '0')
        return (5);// empty space so all these things let us know that 
 
       //everywhere the player goes he made the place as an 0 after leaving it insted the exit
    return (0);
    }
    void	move_player(game_t *game, int new_y, int new_x)
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
void	update_prev_tile(game_t *game)
{
    if (game->on_exit)
        game->map[game->p_y][game->p_x] = 'E';
    else
        game->map[game->p_y][game->p_x] = '0';
}
void	update_player_pos(game_t *game, int new_y, int new_x)
{
    game->p_y = new_y;
    game->p_x = new_x;
    game->map[game->p_y][game->p_x] = 'P';
}

    void	update_and_draw(game_t *game)
{
    game->moves++;
    printf("Moves: %d\n", game->moves);
    draw_map(game);
}

