/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yocto <yocto@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 16:25:35 by yocto             #+#    #+#             */
/*   Updated: 2025/09/29 22:39:31 by yocto            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_walls(t_game *game)
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

int	check_statics_cell(t_game *game, int i, int j)
{
	if (game->map[i][j] == 'P')
	{
		game->p_c++;
		game->p_x = j;
		game->p_y = i;
	}
	else if (game->map[i][j] == 'E')
		game->e_c++;
	else if (game->map[i][j] == 'C')
		game->c_c++;
	else if (game->map[i][j] == 'X')
		game->x_c++;
	else if (game->map[i][j] != '0' && game->map[i][j] != '1')
		return (p_error(-2));
	return (1);
}

int	check_statics(t_game *game)
{
	int	i;
	int	j;

	game->p_c = 0;
	game->e_c = 0;
	game->c_c = 0;
	game->x_c = 0;
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
	if (game->p_c != 1 || game->e_c != 1 || game->c_c < 1)
		return (p_error(-3));
	return (1);
}

void	flood_fill(char **map, int x, int y, t_flood *flood)
{
	if (map[y][x] == '1' || map[y][x] == 'V')
		return ;
	if (map[y][x] == 'C')
		flood->found_c++;
	if (map[y][x] == 'E')
		flood->found_e = 1;
	map[y][x] = 'V';
	flood_fill(map, x + 1, y, flood);
	flood_fill(map, x - 1, y, flood);
	flood_fill(map, x, y + 1, flood);
	flood_fill(map, x, y - 1, flood);
}

int	valid_path(t_game *game, char **c_map)
{
	t_flood	flood;
	int		i;

	flood.found_c = 0;
	flood.found_e = 0;
	flood_fill(c_map, game->p_x, game->p_y, &flood);
	i = 0;
	while (i < game->y)
	{
		free(c_map[i]);
		i++;
	}
	free(c_map);
	if (flood.found_c != game->c_c || !flood.found_e)
		return (p_error(-4));
	return (1);
}
