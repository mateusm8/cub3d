/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matmagal <matmagal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 14:39:31 by matmagal          #+#    #+#             */
/*   Updated: 2026/07/28 19:07:27 by matmagal         ###   ########.fr       */
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

void	parse_color_line(t_game_info *game, char *line)
{
	int	i;
	
	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if ((line[i] == 'F' && line[i + 1] == ' '))
		change_floor_status(game, i, line);
	if ((line[i] == 'C' && line[i + 1] == ' '))
		change_ceil_status(game, i, line);
}

void	change_floor_status(t_game_info *game, int i, char *line)
{
	int	st;

	st = rm_spc(line, i + 2);
	check_number(line, st);
	if (game->has_floor == 0)
	{
		game->floor.r = pick_color(line, st, 1);
		game->floor.g = pick_color(line, st, 2);
		game->floor.b = pick_color(line, st, 3);
		game->has_floor = 1;
	}
	else
		error_exit();
}

void	change_ceil_status(t_game_info *game, int i, char *line)
{
	int	st;

	st = rm_spc(line, i + 2);
	check_number(line, st);
	if (game->has_ceil == 0)
	{
		game->ceil.r = pick_color(line, st, 1);
		game->ceil.g = pick_color(line, st, 2);
		game->ceil.b = pick_color(line, st, 3);
		game->has_ceil = 1;
	}
	else
		error_exit();
}

int	pick_color(char *line, int start, int comma)
{
	char	*nb;
	int		color;

	nb = get_number(line, start, comma);
	color = ft_atoi(nb);
	free(nb);
	if (color < 0 || color > 255)
		error_exit();
	return (color);
}

void	check_number(char *line, int start)
{
	int	c_count;

	c_count = 0;
	while (line[start] && line[start] != '\n')
	{
		if (!ft_isdigit(line[start]) && line[start] != ','
			&& line[start] != ' ' && line[start] != '\t')
			error_exit();
		if (line[start] == ',')
			c_count++;
		start++;
	}
	if (c_count != 2)
		error_exit();
}

char	*get_number(char *line, int start, int comma)
{
	int	i;
	int	k;
	int	c_count;
	char	*str;
	char	*trimmed;

	i = 0;
	c_count = 0;
	while (line[start + i] && c_count < comma)
	{
		if (line[start + i] == ',')
			c_count++;
		i++;
	}
	k = i;
	while (k >= 0 && line[start + k] != ',')
		k--;
	str = ft_substr(line, start + k, i - k);
	if (!str)
		error_exit();
	trimmed = ft_strtrim(str, " \t");
	free(str);
	if (!trimmed)
		error_exit();
	return (trimmed);
}
