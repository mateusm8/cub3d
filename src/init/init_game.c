/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalfonso <nalfonso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 22:29:41 by nalfonso          #+#    #+#             */
/*   Updated: 2026/07/05 20:00:00 by nalfonso         ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	zero_game(t_game *g, t_game_info *game)
{
	int	i;

	g->mlx = NULL;
	g->win = NULL;
	g->img = NULL;
	g->addr = NULL;
	g->win_w = WIN_W;
	g->win_h = WIN_H;
	i = 0;
	while (i < 4)
	{
		g->tex[i].path = ft_strdup(game->tex[i]);
		if (!g->tex[i].path)
			parser_error_exit(game, "Error");
		g->tex[i].img = NULL;
		i++;
	}
}

void	transfer_game_data(t_game *g, t_game_info *game)
{
	int	i;

	g->map.rows = game->map_height;
	g->map.cols = game->map_width;
	g->map.ceil_color = (game->ceil.r << 16)
		| (game->ceil.g << 8) | game->ceil.b;
	g->map.floor_color = (game->floor.r << 16)
		| (game->floor.g << 8) | game->floor.b;
	i = 0;
	while (game->map[i])
		i++;
	g->map.grid = malloc(sizeof(char *) * (i + 1));
	if (!g->map.grid)
		parser_error_exit(game, "Error");
	i = 0;
	while (game->map[i])
	{
		g->map.grid[i] = ft_strdup(game->map[i]);
		if (!g->map.grid[i])
			parser_error_exit(game, "Error");
		i++;
	}
	g->map.grid[i] = NULL;
	zero_game(g, game);
}

int	init_game(t_game *g)
{
	int	i;

	i = 0;
	while (i <= K_COUNT)
	{
		g->keys[i] = 0;
		i++;
	}
	g->mlx = mlx_init();
	if (!g->mlx)
		return (0);
	g->win = mlx_new_window(g->mlx, g->win_w, g->win_h, "cub3d");
	if (!g->win)
		return (0);
	g->img = mlx_new_image(g->mlx, g->win_w, g->win_h);
	if (!g->img)
		return (0);
	g->addr = mlx_get_data_addr(g->img, &g->bpp, &g->line_len, &g->endian);
	return (1);
}
