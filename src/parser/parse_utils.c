/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalfonso <nalfonso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/24 19:05:52 by nalfonso          #+#    #+#             */
/*   Updated: 2026/09/24 19:16:54 by nalfonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	line_is_empty(char *line)
{
	int	i;

	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	return (line[i] == '\0' || line[i] == '\n');
}

int	is_map_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] == ' ')
		i++;
	if (line[i] == '\0' || line[i] == '\n')
		return (0);
	while (line[i] && line[i] != '\n')
	{
		if (line[i] != '0' && line[i] != '1' && line[i] != 'N'
			&& line[i] != 'S' && line[i] != 'E' && line[i] != 'W'
			&& line[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

int	is_walkable(char c)
{
	return (c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

int	validate_pos(t_game_info *game, int y, int x)
{
	if (y < 0 || y >= game->map_height)
		return (0);
	if (!game->map[y] || x < 0 || (size_t)x >= ft_strlen(game->map[y]))
		return (0);
	if (game->map[y][x] == ' ')
		return (0);
	return (1);
}

int	check_game_struct(t_game_info *game, char *line)
{
	if (game->has_ceil != 1 || game->has_floor != 1 || game->has_tex[NO] != 1
		|| game->has_tex[SO] != 1 || game->has_tex[WE] != 1
		|| game->has_tex[EA] != 1)
		return (1);
	if (add_map_line(game, line))
		return (1);
	return (0);
}
