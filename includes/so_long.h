/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yocto <yocto@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 22:12:41 by yocto             #+#    #+#             */
/*   Updated: 2025/09/29 22:39:31 by yocto            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# define TILE_SIZE 64
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_ESC 65307
# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_LEFT 65361
# define KEY_RIGHT 65363

typedef struct s_flood
{
	int	found_c;
	int	found_e;
}	t_flood;

typedef struct game
{
	char	**map;
	int		x;
	int		y;
	int		p_c;
	int		e_c;
	int		c_c;
	int		p_x;
	int		p_y;
	int		x_c;
	int		on_exit;

	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_wall;
	void	*img_floor;
	void	*img_player_normal;
	void	*img_player_on_exit;
	void	*img_player;
	void	*img_exit;
	void	*img_collect;
	void	*img_enemy;
	int		img_w;
	int		img_h;
	int		moves;
}			t_game;
int			free_map(t_game *game);
int			read_map(const char *filename, t_game *game);
int			check_map(t_game *game);
char		*store_line(char *line);
char		*get_next_line(int fd);
int			check_filename(const char *filename);
void		init_window(t_game *game);
void		load_images(t_game *game);
int			handle_key(int keycode, t_game *game);
void		draw_map(t_game *game);
void		move_right(t_game *game);
void		move_left(t_game *game);
void		move_up(t_game *game);
void		move_down(t_game *game);
int			close_window(t_game *game);
void		move_player(t_game *game, int new_y, int new_x);
int			can_move_to(t_game *game, int y, int x);
void		update_player_pos(t_game *game, int new_y, int new_x);
void		update_prev_tile(t_game *game);
void		update_player_pos(t_game *game, int new_y, int new_x);
void		game_win(t_game *game);
void		game_lose(t_game *game);
void		on_e(t_game *game, int code);
void		update_and_draw(t_game *game);
void		free_images(t_game *game);
int			free_read(char *line, int fd, t_game *game);
int			read_sc(const char *filename, t_game *game);
int			check_walls(t_game *game);
int			check_statics(t_game *game);
int			check_statics_cell(t_game *game, int i, int j);
int			valid_path(t_game *game, char **c_map);
void		move_on_exit(t_game *game, int new_y, int new_x);
void		move_on_floor(t_game *game, int new_y, int new_x, int can_move);
int			p_error(int code);
void		*get_tile_image(t_game *game, char tile);

#endif
