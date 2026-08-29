/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matmagal <matmagal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 13:23:28 by matmagal          #+#    #+#             */
/*   Updated: 2026/08/29 10:31:41 by matmagal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	error_exit(t_game_info *game, char *msg)
{
	if (game)
	{
		if (game->map)
			free_map(game->map);
		free(game);
	}
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
