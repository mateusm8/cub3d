/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matmagal <matmagal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/04 11:35:56 by matmagal          #+#    #+#             */
/*   Updated: 2026/09/01 12:36:07 by matmagal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_game_info(t_game_info *game, char **av)
{
	*game = (t_game_info){0};
	game->map_name = ft_strdup(av[1]);
	if (!game->map_name)
		parser_error_exit(game, "Invalid map name");
}
