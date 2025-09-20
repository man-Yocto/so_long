#include "../includes/so_long.h"

int	check_map(game_t *game)
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
//i think we have  a problem with this allocation

int	p_error(int code)
{
    if (code == -1)
        write(2, "Error\nMap is not surrounded by walls\n", 37);
    else if (code == -2)
        write(2, "Error\nMap contains invalid character\n", 37);
    else if (code == -3)
        write(2, "Error\nMap must have 1P, 1E, and at least 1C\n", 45);
    else if (code == -4)
        write(2, "Error\nNo valid path to collect all items and reach exit\n", 56);
    return (0);
}