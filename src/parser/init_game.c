/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matmagal <matmagal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/04 11:35:56 by matmagal          #+#    #+#             */
/*   Updated: 2026/07/05 17:17:16 by matmagal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_game_info(t_game_info *game)
{
	game->map_name = NULL;
	game->map = NULL;
	game->tex[NO] = NULL;
	game->tex[SO] = NULL;
	game->tex[WE] = NULL;
	game->tex[EA] = NULL;
	game->floor.r = 0;
	game->floor.g = 0;
	game->floor.b = 0;
	game->ceil.r = 0;
	game->ceil.g = 0;
	game->ceil.b = 0;
	game->map_width = 0;
	game->map_height = 0;
	game->player.x = 0;
	game->player.y = 0;
	game->player.dir = '\0';
	game->player_count = 0;
	game->has_tex[NO] = 0;
	game->has_tex[SO] = 0;
	game->has_tex[WE] = 0;
	game->has_tex[EA] = 0;
	game->has_floor = 0;
	game->has_ceil = 0;
}
