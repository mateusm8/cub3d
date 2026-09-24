/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalfonso <nalfonso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 14:39:31 by matmagal          #+#    #+#             */
/*   Updated: 2026/09/24 19:16:20 by nalfonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_color_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	return ((line[i] == 'F' && is_whitespace(line[i + 1]))
		|| (line[i] == 'C' && is_whitespace(line[i + 1])));
}

int	parse_color_line(t_game_info *game, char *line)
{
	int	i;

	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if ((line[i] == 'F' && is_whitespace(line[i + 1])))
		return (change_floor_status(game, i, line));
	if ((line[i] == 'C' && is_whitespace(line[i + 1])))
		return (change_ceil_status(game, i, line));
	return (1);
}

int	change_floor_status(t_game_info *game, int i, char *line)
{
	int	st;
	int	color;

	st = rm_spc(line, i + 2);
	if (check_number(line, st))
		return (1);
	if (game->has_floor != 0)
		return (1);
	color = pick_color(line, st, 1);
	if (color == -1)
		return (1);
	game->floor.r = color;
	color = pick_color(line, st, 2);
	if (color == -1)
		return (1);
	game->floor.g = color;
	color = pick_color(line, st, 3);
	if (color == -1)
		return (1);
	game->floor.b = color;
	game->has_floor = 1;
	return (0);
}

int	change_ceil_status(t_game_info *game, int i, char *line)
{
	int	st;
	int	color;

	st = rm_spc(line, i + 2);
	if (check_number(line, st))
		return (1);
	if (game->has_ceil != 0)
		return (1);
	color = pick_color(line, st, 1);
	if (color == -1)
		return (1);
	game->ceil.r = color;
	color = pick_color(line, st, 2);
	if (color == -1)
		return (1);
	game->ceil.g = color;
	color = pick_color(line, st, 3);
	if (color == -1)
		return (1);
	game->ceil.b = color;
	game->has_ceil = 1;
	return (0);
}

int	pick_color(char *line, int start, int comma)
{
	char	*nb;
	int		color;

	nb = get_number(line, start, comma);
	if (!nb)
		return (-1);
	color = convert_number(nb);
	free(nb);
	if (color < 0 || color > 255)
		return (-1);
	return (color);
}
