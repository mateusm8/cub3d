/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalfonso <nalfonso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 22:29:41 by nalfonso          #+#    #+#             */
/*   Updated: 2026/07/05 20:00:00 by nalfonso         ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

static void direction(t_game *g, t_game_info *game)
{
	if (game->player.dir == 'N')
	{
		g->player.dir_x = -1.0;
		g->player.dir_y = 0.0;
	}
	if (game->player.dir == 'S')
	{
		g->player.dir_x = 1.0;
		g->player.dir_y = 0.0;
	}
	if (game->player.dir == 'W')
	{
		g->player.dir_x = 0.0;
		g->player.dir_y = -1.0;
	}
	if (game->player.dir == 'E')
	{
		g->player.dir_x = 0.0;
		g->player.dir_y = 1.0;
	}
}


void	init_player(t_game *g, t_game_info *game)
{
	g->player.pos_x = game->player.x;
	g->player.pos_y = game->player.y;
	direction(g, game);
	g->player.plane_x = 0.0;
	g->player.plane_y = 0.66;
}

