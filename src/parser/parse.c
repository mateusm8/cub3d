/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalfonso <nalfonso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 20:00:00 by nalfonso          #+#    #+#             */
/*   Updated: 2026/07/05 20:00:00 by nalfonso         ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

static char	*read_line(int fd)
{
	char	*line;
	char	buf[1];
	int		i;
	int		ret;

	line = malloc(4096);
	if (!line)
		return (NULL);
	i = 0;
	ret = 1;
	while (i < 4095)
	{
		ret = read(fd, buf, 1);
		if (ret <= 0 || buf[0] == '\n')
			break ;
		line[i++] = buf[0];
	}
	line[i] = 0;
	if (ret < 0)
		return (free(line), NULL);
	return (line);
}

int	parse_element(t_game *g, char *line);
int	parse_map_section(t_game *g, int fd, char *first_line);

int	parse_file(t_game *g, char *path)
{
	int		fd;
	char	*line;

	if (strlen(path) < 4
		|| strncmp(path + strlen(path) - 4, ".cub", 4) != 0)
		return (error_exit(g, "Map file must end with .cub"));
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (error_exit(g, "Cannot open map file"));
	line = read_line(fd);
	while (line)
	{
		if (line[0] == '1' || line[0] == ' ')
		{
			if (!parse_map_section(g, fd, line))
				return (close(fd), free(line), 0);
			break ;
		}
		if (line[0] != '\0' && !parse_element(g, line))
			return (close(fd), free(line), 0);
		free(line);
		line = read_line(fd);
	}
	close(fd);
	return (1);
}
