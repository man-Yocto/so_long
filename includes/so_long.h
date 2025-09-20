#ifndef SO_LONG
#define SO_LONG
#include "libft/libft.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "mlx.h"
#define TILE_SIZE 64
#define KEY_W      119
#define KEY_A      97
#define KEY_S      115
#define KEY_D      100
#define KEY_ESC    65307
#define KEY_UP     65362
#define KEY_DOWN   65364
#define KEY_LEFT   65361
#define KEY_RIGHT  65363

typedef struct game{
char **map;
int x;
int y;
int P_c;
int E_c;
int C_c;
int p_x;
int p_y;
int X_c;
int on_exit;

void *mlx_ptr;
void *win_ptr;
void *img_wall;
void *img_floor;
void *img_player_normal;
void *img_player_on_exit;
void *img_player;
void *img_exit;
void *img_collect;
void *img_enemy;
int img_w;
int img_h;
int moves;
}game_t;
int	free_map(game_t *game);
int	read_map(const char *filename, game_t *game);
int	check_map(game_t *game);
char	*store_line(char *line);
char *get_next_line(int fd);
void	init_window(game_t *game);
void	load_images(game_t *game);
int handle_key(int keycode, game_t *game);
void	draw_map(game_t *game);
void	move_right(game_t *game);
void move_left(game_t *game);
void move_up(game_t *game);
void move_down(game_t *game);
int close_window(game_t *game);
void move_player(game_t *game, int new_y, int new_x);
int can_move_to(game_t *game, int y, int x);
void	update_player_pos(game_t *game, int new_y, int new_x);
void update_prev_tile(game_t *game);
void update_player_pos(game_t *game, int new_y, int new_x);
void game_win(game_t *game);
void game_lose(game_t *game);
void on_E(game_t *game, int code);
void	update_and_draw(game_t *game);
void free_images(game_t *game);
int free_read(char *line, int fd, game_t *game);
int read_sc(const char *filename, game_t *game);
int check_walls(game_t *game);
int check_statics(game_t *game);
int check_statics_cell(game_t *game, int i, int j);
int valid_path(game_t *game, char **c_map);
void	move_on_exit(game_t *game, int new_y, int new_x);
void move_on_floor(game_t *game, int new_y, int new_x, int can_move);
int p_error(int code);  


#endif