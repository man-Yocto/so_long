/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yocto <yocto@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 16:25:35 by yocto             #+#    #+#             */
/*   Updated: 2025/09/20 19:33:16 by yocto            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"



int	check_walls(game_t *game)
{
    int	i;
    int	j;

    if (game->x == 0 || game->y == 0)
        return (p_error(-1));
    i = 0;
    while (i < game->y)
    {
        j = 0;
        while (j < game->x)
        {
            if (i == 0 || i == game->y - 1 || j == 0 || j == game->x - 1)
            {
                if (game->map[i][j] != '1')
                    return (p_error(-1));
            }
            j++;
        }
        i++;
    }
    return (1);
}

int	check_statics_cell(game_t *game, int i, int j)
{
    if (game->map[i][j] == 'P')
    {
        game->P_c++;
        game->p_x = j;
        game->p_y = i;
    }
    else if (game->map[i][j] == 'E')
        game->E_c++;
    else if (game->map[i][j] == 'C')
        game->C_c++;
    else if(game->map[i][j] == 'X')
        game->X_c++;
    else if (game->map[i][j] != '0' && game->map[i][j] != '1')
        return (p_error(-2));
        
    return (1);
}
int	check_statics(game_t *game)
{
    int	i;
    int	j;

    game->P_c = 0;
    game->E_c = 0;
    game->C_c = 0;
    game->X_c = 0;
    i = 0;
    while (i < game->y)
    {
        j = 0;
        while (j < game->x)
        {
            if (!check_statics_cell(game, i, j))
                return (0);
            j++;
        }
        i++;
    }
    if (game->P_c != 1 || game->E_c != 1 || game->C_c < 1)
        return (p_error(-3));
    return (1);
}

void	flood_fill(char **map, int x, int y, int *found_c, int *found_e)
{
    if (map[y][x] == '1' || map[y][x] == 'V')
        return ;
    if (map[y][x] == 'C')
        (*found_c)++;
    if (map[y][x] == 'E')
        *found_e = 1;
    map[y][x] = 'V';
    flood_fill(map, x + 1, y, found_c, found_e);
    flood_fill(map, x - 1, y, found_c, found_e);
    flood_fill(map, x, y + 1, found_c, found_e);
    flood_fill(map, x, y - 1, found_c, found_e);
}

int	valid_path(game_t *game, char **c_map)
{
    int	found_c;
    int	found_e;
    int	i;

    found_c = 0;
    found_e = 0;
    flood_fill(c_map, game->p_x, game->p_y, &found_c, &found_e);
    i = 0;
    while (i < game->y)
    {
        free(c_map[i]);
        i++;
    }
    free(c_map);
    if (found_c != game->C_c || !found_e)
        return (p_error(-4));
    return (1);
}


