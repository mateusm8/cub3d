/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalfonso <nalfonso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 17:30:20 by matmagal          #+#    #+#             */
/*   Updated: 2026/09/24 19:10:22 by nalfonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	parse_one(t_game_info *game)
{
	if (!check_file(game->map_name, ".cub"))
		parser_error_exit(game, "Invalid file extension (expected .cub)");
	parse_cub_file(game);
	validate_map(game);
}

void	parse_cub_file(t_game_info *game)
{
	int		fd;
	int		in_map;
	char	*line;

	fd = open (game->map_name, O_RDONLY);
	if (fd < 0)
		parser_error_exit(game, "Invalid fd");
	line = get_next_line(fd);
	in_map = 0;
	while (line)
	{
		if (is_in_map(game, line, &in_map))
		{
			free(line);
			close(fd);
			parser_error_exit(game, "Invalid map file");
		}
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}

int	is_in_map(t_game_info *game, char *line, int *in_map)
{
	if (!*in_map)
	{
		if (line_is_empty(line))
			return (0);
		if (is_texture_line(line))
			return (parse_texture_line(game, line));
		if (is_color_line(line))
			return (parse_color_line(game, line));
		if (is_map_line(line))
		{
			if (check_game_struct(game, line))
				return (1);
			*in_map = 1;
			return (0);
		}
		return (1);
	}
	if (line_is_empty(line))
		return (1);
	if (is_map_line(line))
		return (add_map_line(game, line));
	return (1);
}

int	add_map_line(t_game_info *game, char *line)
{
	char	**tmp;
	size_t	old_size;
	size_t	new_size;
	int		len;

	old_size = (game->map_height + 1) * sizeof(char *);
	new_size = (game->map_height + 2) * sizeof(char *);
	tmp = ft_realloc(game->map, old_size, new_size);
	if (!tmp)
		return (1);
	game->map = tmp;
	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		len--;
	game->map[game->map_height] = ft_substr(line, 0, len);
	if (!game->map[game->map_height])
		return (1);
	game->map[game->map_height + 1] = NULL;
	if (len > game->map_width)
		game->map_width = len;
	if (parse_player(game, game->map[game->map_height]))
		return (1);
	game->map_height++;
	return (0);
}
