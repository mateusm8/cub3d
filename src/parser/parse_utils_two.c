/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils_two.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalfonso <nalfonso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/24 19:09:29 by nalfonso          #+#    #+#             */
/*   Updated: 2026/09/24 19:10:47 by nalfonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	parse_player(t_game_info *game, char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if ((line[i] == 'N' || line[i] == 'S'
				|| line[i] == 'E' || line[i] == 'W'))
		{
			game->player.dir = line[i];
			game->player.x = i;
			game->player.y = game->map_height;
			game->player_count++;
			if (game->player_count > 1)
				return (1);
			line[i] = '0';
		}
		i++;
	}
	return (0);
}

void	validate_map(t_game_info *game)
{
	if (!game->map || game->map_height == 0)
		parser_error_exit(game, "Map does not exist");
	if (game->player_count != 1)
		parser_error_exit(game, "Number of players must be one");
	if (!validade_walls(game))
		parser_error_exit(game, "Map is not closed by walls");
}

int	validade_walls(t_game_info *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (game->map[y][x])
		{
			if (is_walkable(game->map[y][x]))
			{
				if (!validate_pos(game, y - 1, x)
					|| !validate_pos(game, y + 1, x)
					|| !validate_pos(game, y, x - 1)
					|| !validate_pos(game, y, x + 1))
					return (0);
			}
			x++;
		}
		y++;
	}
	return (1);
}
