/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalfonso <nalfonso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 22:07:11 by nalfonso          #+#    #+#             */
/*   Updated: 2026/07/05 20:00:00 by nalfonso         ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	t_game			g;
	t_game_info		*game;

	if (ac != 2)
		return (write(2, "Error\nUsage: ./Cub3d <map.cub>\n", 31), 1);
	game = malloc(sizeof(t_game_info));
	if (!game)
		return (1);
	init_game_info(game, av);
	parse_one(game);
	transfer_game_data(&g, game);
	if (!init_game(&g))
		return (error_exit(&g, "Init failed"), 1);
	if (load_textures(&g))
		return (error_exit(&g, "Init Textures failed\n"), 1);
	init_player(&g, game);
	mlx_loop_hook(g.mlx, render_frame, &g);
	mlx_hook(g.win, 2, 1L << 0, handle_key, &g);
	mlx_hook(g.win, 3, 1L << 1, handle_key_release, &g);
	mlx_hook(g.win, 17, 0, handle_close, &g);
	mlx_loop(g.mlx);
	cleanup(&g);
	free_game_info(game);
	return (0);
}
