/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yocto <yocto@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 21:59:43 by yocto             #+#    #+#             */
/*   Updated: 2025/09/29 22:28:20 by yocto            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	*get_tile_image(t_game *game, char tile)
{
	if (tile == '1')
		return (game->img_wall);
	else if (tile == '0')
		return (game->img_floor);
	else if (tile == 'P')
		return (game->img_player);
	else if (tile == 'E')
		return (game->img_exit);
	else if (tile == 'C')
		return (game->img_collect);
	else if (tile == 'X')
		return (game->img_enemy);
	return (NULL);
}

void	draw_map(t_game *game)
{
	int		i;
	int		j;
	void	*img;

	i = -1;
	while (++i < game->y)
	{
		j = -1;
		while (++j < game->x)
		{
			img = get_tile_image(game, game->map[i][j]);
			mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, img, j
				* TILE_SIZE, i * TILE_SIZE);
		}
	}
}
