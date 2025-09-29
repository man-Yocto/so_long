/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yocto <yocto@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 22:11:19 by yocto             #+#    #+#             */
/*   Updated: 2025/09/29 22:48:57 by yocto            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	ft_memset(&game, 0, sizeof(t_game));
	if (argc != 2)
	{
		write(2, "Usage: ./so_long map.ber\n", 25);
		return (1);
	}
	if (!check_filename(argv[1]))
		return (p_error(-5));
	if (!read_map(argv[1], &game))
		return (1);
	if (!check_map(&game))
	{
		free_map(&game);
		return (1);
	}
	init_window(&game);
	load_images(&game);
	draw_map(&game);
	mlx_hook(game.win_ptr, 17, 0, close_window, &game);
	mlx_key_hook(game.win_ptr, handle_key, &game);
	mlx_loop(game.mlx_ptr);
	return (0);
}
