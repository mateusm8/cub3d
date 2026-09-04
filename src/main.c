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

int	render_frame(t_game *g);

// void init_t_game(t_game *g, t_game_info *game)
// {
// 	g->mlx = NULL;
// 	g->win = NULL;
// 	g->img = NULL;
// 	g->addr = NULL;
// 	g->win_w = WIN_W;
// 	g->win_h = WIN_H;

// }

// void	transfer_game_data(t_game *g, t_game_info *game)
// {
// 	int	i;

// 	g->map.rows = game->map_height;
// 	g->map.cols = game->map_width;
// 	i = 0;
// 	g->map.grid = malloc(sizeof(char *) * (game->map_height + 1));
// 	if (!g->map.grid)
// 		parser_error_exit(game, "Error");
// 	while (i < game->map_height)
// 	{
// 		g->map.grid[i] = ft_strdup(game->map[i]);
// 		if (!g->map.grid[i])
// 			parser_error_exit(game, "Error");
// 		i++;
// 	}
// 	init_t_game(g, game);
	
// }

int	main(int ac, char **av)
{
	t_game	g;
	t_game_info *game;

	if (ac != 2)
		return (write(2, "Error\nUsage: ./Cub3d <map.cub>\n", 31), 1);
	game = malloc(sizeof(t_game_info));
	if (!game)
		return (1);
	init_game_info(game, av);\
	//printf("test %s\n", game->map_name);
	parse_one(game);
	//transfer_game_data(&g, game);
	if (!init_game(&g))
		return (error_exit(&g, "Init failed"), 1);
	init_player(&g);
	// if (!parse_file(&g, av[1]))
	// 	return (1);
	// mlx_loop_hook(g.mlx, render_frame, &g);
	// mlx_hook(g.win, 2, 1L << 0, handle_key, &g);
	// mlx_hook(g.win, 17, 0, handle_close, &g);
	// mlx_loop(g.mlx);
	printf("text %s\n", game->tex[NO]);
	cleanup(&g);
	free_game_info(game);
	return (0);
}
