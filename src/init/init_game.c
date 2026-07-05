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

# include "cub3d.h"

static void	zero_game(t_game *g)
{
	int	i;

	g->mlx = NULL;
	g->win = NULL;
	g->img = NULL;
	g->addr = NULL;
	g->win_w = WIN_W;
	g->win_h = WIN_H;
	g->map.grid = NULL;
	g->map.rows = 0;
	g->map.cols = 0;
	g->map.floor_color = -1;
	g->map.ceil_color = -1;
	i = 0;
	while (i < 4)
	{
		g->tex[i].path = NULL;
		g->tex[i].img = NULL;
		i++;
	}
}

int	init_game(t_game *g)
{
	zero_game(g);
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
