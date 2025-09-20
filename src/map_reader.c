/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yocto <yocto@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 16:25:40 by yocto             #+#    #+#             */
/*   Updated: 2025/09/20 23:36:43 by yocto            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	free_map(game_t *game)
{
    int	i;

    i = 0;
    while (i < game->y)
    {
        free(game->map[i]);
        i++;
    }
    free(game->map);
    return (0);
}

int	free_read(char *line, int fd, game_t *game)
{
    free(line);
    close(fd);
    free_map(game);
    return (0);
}

static int	check_line(char *line, game_t *game, int *first)
{
    int	len;

    len = ft_strlen(line);
    if (len > 0 && line[len - 1] == '\n')
    {
        line[len - 1] = '\0';
        len--;
    }
    if (*first)
    {
        game->x = len;
        *first = 0;
    }
    if (len != game->x)
        return (0);
    return (1);
}

int	read_sc(const char *filename, game_t *game)
{
    int		fd;
    int		first;
    char	*line;
    int		tall;

    fd = open(filename, O_RDONLY);
    if (fd == -1)
        return (0);
    first = 1;
    tall = 0;
    while ((line = get_next_line(fd)))
    {
        if (!check_line(line, game, &first))
        {
            free_read(line, fd, game);
            return (0);
        }
        tall++;
        free(line);  
    }
    game->y = tall;
    close(fd);
    return (1);
}
char	*store_line(char *line)
{
    int	len;

    len = ft_strlen(line);
    if (len > 0 && line[len - 1] == '\n')
        line[len - 1] = '\0';
    return (line);
}


