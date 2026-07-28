/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matmagal <matmagal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 17:30:20 by matmagal          #+#    #+#             */
/*   Updated: 2026/07/28 14:39:49 by matmagal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	parse_one(t_game_info *game)
{
	if (!check_file(game->map_name, ".cub"))
	{
		printf("Error\nInvalid file extension (expected .cub)\n");
		free(game);
		exit (1);
	}
}

void	parse_file(t_game_info *game)
{
	int	fd;
	int	in_map;
	char *line;
	
	fd = open (game->map_name, O_RDONLY);
	if (fd < 0)
		error_exit();
	line = get_next_line(fd);
	in_map = 0;
	while (line)
	{
		in_map = is_in_map(game, line, in_map);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}

int	add_tex_flag(t_game_info *game, t_directions dir)
{
	game->has_tex[dir]++;
	return (0);
}

int	is_in_map(t_game_info *game, char *line, int in_map)
{
	if (!in_map)
	{
		if (line_is_empty(line))
			;
		else if (is_texture_line(line))
			parse_texture_line(game, line);
		else if (is_color_line(line))
			parse_color_line(game, line);
		else if (is_map_line(line))
		{
			in_map = 1;
			add_map_line(game, line);
		}
		else
			error_exit("Invalid header line");
	}
	else
	{
		if (is_header_line(line))
			error_exit("Header found after map");
		else if (is_map_line(line) || line_is_empty(line))
			add_map_line(game, line);
		else
			error_exit("Invalid map line");
	}
	return (in_map);
}

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
	while (line[i] == ' ' || line[i] == '\t')
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
