#include "../includes/so_long.h"
void	game_win(game_t *game)
{
    write(1, "You win!\n", 10);
    close_window(game);
    exit(0);
}

void	game_lose(game_t *game)
{
    write(1, "You lose!\n", 10);
    close_window(game);
    exit(0);
}
void on_E(game_t *game, int code)
{
    if (code == 0)
    {
        game->on_exit = 0;
        game->img_player = game->img_player_normal;
        
    }
    else{
        game->on_exit =  1;
        game->img_player = game->img_player_on_exit;

        
    }
}
void	move_on_exit(game_t *game, int new_y, int new_x)
{
    update_prev_tile(game);
    on_E(game, 1);
    update_player_pos(game, new_y, new_x);
}

void	move_on_floor(game_t *game, int new_y, int new_x, int can_move)
{
    if (can_move == 4)
        game->C_c--;
    update_prev_tile(game);
    on_E(game, 0);
    update_player_pos(game, new_y, new_x);
}


