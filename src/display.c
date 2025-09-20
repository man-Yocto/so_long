/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yocto <yocto@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 19:55:21 by yocto             #+#    #+#             */
/*   Updated: 2025/09/20 23:47:31 by yocto            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/so_long.h"

void	free_images(game_t *game)
{
    if (game->img_wall)
        mlx_destroy_image(game->mlx_ptr, game->img_wall);
    if (game->img_floor)
        mlx_destroy_image(game->mlx_ptr, game->img_floor);
    if (game->img_player_normal)
        mlx_destroy_image(game->mlx_ptr, game->img_player_normal);
    if (game->img_player_on_exit)
        mlx_destroy_image(game->mlx_ptr, game->img_player_on_exit);
    if (game->img_exit)
        mlx_destroy_image(game->mlx_ptr, game->img_exit);
    if (game->img_collect)
        mlx_destroy_image(game->mlx_ptr, game->img_collect);
    if (game->img_enemy)
        mlx_destroy_image(game->mlx_ptr, game->img_enemy);
    if (game->win_ptr)
        mlx_destroy_window(game->mlx_ptr, game->win_ptr);
}
int close_window(game_t *game)
{
    free_images(game);
    free_map(game); 
    exit(0);
    return (0);
}
void	init_window(game_t *game)
{
    game->mlx_ptr = mlx_init();
    game->win_ptr = mlx_new_window(game->mlx_ptr, game->x * TILE_SIZE, game->y * TILE_SIZE, "so_long");
    mlx_hook(game->win_ptr, 17, 0, close_window, game);
}

void	load_images(game_t *game)
{
    game->img_wall = mlx_xpm_file_to_image(game->mlx_ptr, "images/wall.xpm", &game->img_w, &game->img_h);
    game->img_floor = mlx_xpm_file_to_image(game->mlx_ptr, "images/floor.xpm", &game->img_w, &game->img_h);
    game->img_player_normal = mlx_xpm_file_to_image(game->mlx_ptr, "images/player.xpm", &game->img_w, &game->img_h);
    game->img_player_on_exit = mlx_xpm_file_to_image(game->mlx_ptr, "images/P+E.xpm", &game->img_w, &game->img_h);
    game->img_player = game->img_player_normal;
    game->img_exit = mlx_xpm_file_to_image(game->mlx_ptr, "images/exit.xpm", &game->img_w, &game->img_h);
    game->img_collect = mlx_xpm_file_to_image(game->mlx_ptr, "images/collect.xpm", &game->img_w, &game->img_h);
    game->img_enemy = mlx_xpm_file_to_image(game->mlx_ptr, "images/enemy.xpm", &game->img_w, &game->img_h);
    if (!game->img_wall || !game->img_floor || !game->img_player
    || !game->img_exit || !game->img_collect || !game->img_enemy)
{
    write(2, "Error\nFailed to load one or more images\n", 40);
    free_images(game);
    exit(1);
}

}
void	draw_map(game_t *game)
{
    int i;
    int j;
    void *img;

    i = 0;
    while (i < game->y)
    {
        j = 0;
        while (j < game->x)
        {
            if (game->map[i][j] == '1')
                img = game->img_wall;
            else if (game->map[i][j] == '0')
                img = game->img_floor;
            else if (game->map[i][j] == 'P')
                img = game->img_player;
            else if (game->map[i][j] == 'E')
                img = game->img_exit;
            else if (game->map[i][j] == 'C')
                img = game->img_collect;
            else if (game->map[i][j] == 'X')
                img = game->img_enemy;
            mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, img, j * TILE_SIZE, i * TILE_SIZE);
            j++;
        }
        i++;
    }
}
