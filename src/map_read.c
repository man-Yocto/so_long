#include "../includes/so_long.h"

int	read_map(const char *filename, game_t *game)
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
    i = 0;
    while (i < game->y && (line = get_next_line(fd)))
    {
        game->map[i] = store_line(line);
        if (!game->map[i++])
            return (free_read(line, fd, game));
    }
    close(fd);
    if (i != game->y)
        return (free_map(game));
    return (1);
}