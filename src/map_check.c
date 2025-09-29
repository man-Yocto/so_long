/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yocto <yocto@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 22:06:39 by yocto             #+#    #+#             */
/*   Updated: 2025/09/29 22:45:14 by yocto            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map(t_game *game)
{
	char	**c_map;
	int		i;

	if (!check_walls(game))
		return (0);
	if (!check_statics(game))
		return (0);
	c_map = malloc(sizeof(char *) * game->y);
	if (!c_map)
		return (0);
	i = -1;
	while (++i < game->y)
	{
		c_map[i] = ft_strdup(game->map[i]);
		if (!c_map[i])
		{
			while (i > 0)
				free(c_map[--i]);
			free(c_map);
			return (0);
		}
	}
	if (!valid_path(game, c_map))
		return (0);
	return (1);
}

int	p_error(int code)
{
	if (code == -1)
		write(2, "Error\nMap is not surrounded by walls\n", 37);
	else if (code == -2)
		write(2, "Error\nMap contains invalid character\n", 37);
	else if (code == -3)
		write(2, "Error\nMap must have 1P, 1E, and at least 1C\n", 45);
	else if (code == -4)
		write(2, "Error\nNo valid path to collect all items and reach exit\n",
			56);
	else if (code == -5)
		write(2, "Error\nInvalid file extension (use .ber)\n", 40);
	return (0);
}
