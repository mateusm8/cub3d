/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matmagal <matmagal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 13:23:28 by matmagal          #+#    #+#             */
/*   Updated: 2026/09/01 11:34:14 by matmagal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	parser_error_exit(t_game_info *game, char *msg)
{
	free_game_info(game);
	if (msg)
		printf("Error\n%s\n", msg);
	else
		printf("Error\n");
	exit (1);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map && map[i])
		free(map[i++]);
	free(map);
}

void	free_tex(t_game_info *game)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		free(game->tex[i]);
		i++;
	}
}

void	free_game_info(t_game_info *game)
{
	if (game)
	{
		if (game->map)
			free_map(game->map);
		if (game->map_name)
			free(game->map_name);
		free_tex(game);
		free(game);
	}
}
