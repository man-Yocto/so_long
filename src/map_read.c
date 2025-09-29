/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yocto <yocto@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 22:07:48 by yocto             #+#    #+#             */
/*   Updated: 2025/09/29 22:45:27 by yocto            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_filename(const char *filename)
{
	int	len;

	if (!filename)
		return (0);
	len = ft_strlen(filename);
	if (len < 4)
		return (0);
	if (ft_strncmp(filename + len - 4, ".ber", 4) != 0)
		return (0);
	return (1);
}

int	read_map(const char *filename, t_game *game)
{
	int		fd;
	int		i;
	char	*line;

	if (!read_sc(filename, game))
		return (0);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	game->map = malloc(sizeof(char *) * game->y);
	if (!game->map)
		return (close(fd), 0);
	i = -1;
	line = get_next_line(fd);
	while (++i < game->y && line)
	{
		game->map[i] = store_line(line);
		if (!game->map[i])
			return (free_read(line, fd, game));
		line = get_next_line(fd);
	}
	close(fd);
	if (i != game->y)
		return (free_map(game));
	return (1);
}
