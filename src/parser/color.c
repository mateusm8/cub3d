/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matmagal <matmagal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 14:39:31 by matmagal          #+#    #+#             */
/*   Updated: 2026/09/01 11:24:17 by matmagal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_color_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	return ((line[i] == 'F' && line[i + 1] == ' ')
		|| (line[i] == 'C' && line[i + 1] == ' '));
}

int	parse_color_line(t_game_info *game, char *line)
{
	int	i;
	
	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if ((line[i] == 'F' && line[i + 1] == ' '))
		return (change_floor_status(game, i, line));
	if ((line[i] == 'C' && line[i + 1] == ' '))
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
	color = ft_atoi(nb);
	free(nb);
	if (color < 0 || color > 255)
		return (-1);
	return (color);
}

int	check_number(char *line, int start)
{
	int	c_count;

	c_count = 0;
	while (line[start] && line[start] != '\n')
	{
		if (!ft_isdigit(line[start]) && line[start] != ','
			&& line[start] != ' ' && line[start] != '\t')
			return (1);
		if (line[start] == ',')
			c_count++;
		start++;
	}
	if (c_count != 2)
		return (1);
	return (0);
}

char	*get_number(char *line, int start, int comma)
{
	int	c_start;
	int	end;
	int	count;
	char	*str;

	count = 1;
	while (count < comma)
	{
		while (line[start] && line[start] != ',')
			start++;
		if (line[start] != ',')
			return (NULL);
		start++;
		count++;
	}
	c_start = start;
	while (line[start] && line[start] != ',' && line[start] != '\n')
		start++;
	end = start;
	str = ft_substr(line, c_start, end - c_start);
	if (!str)
		return (NULL);
	return (aux_get_number(str));
}

char	*aux_get_number(char *str)
{
	char	*trimmed;
	
	trimmed = ft_strtrim(str, " \t");
	free(str);
	if (!trimmed || trimmed[0] == '\0')
	{
		free(trimmed);
		return (NULL);
	}
	return (trimmed);
}
