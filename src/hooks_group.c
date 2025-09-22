#include "../includes/so_long.h"

void	move_up(game_t *game)    
{ 
    move_player(game, game->p_y - 1, game->p_x); 
}

void	move_down(game_t *game)  
{ 
    move_player(game, game->p_y + 1, game->p_x);
}

void	move_left(game_t *game)  
{
     move_player(game, game->p_y, game->p_x - 1); 
}

void	move_right(game_t *game) 
{
    move_player(game, game->p_y, game->p_x + 1); 
}

int handle_key(int keycode, game_t *game)
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