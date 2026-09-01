/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalfonso <nalfonso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 20:00:00 by nalfonso          #+#    #+#             */
/*   Updated: 2026/07/05 20:00:00 by nalfonso         ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

static char	*read_line_fd(int fd)
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

static int	collect_rows(int fd, char **rows, int start, int *total)
{
	char	*line;

	*total = start;
	line = read_line_fd(fd);
	while (line && line[0] != '\0')
	{
		if (*total >= 4096)
			return (free(line), 0);
		rows[*total] = line;
		(*total)++;
		line = read_line_fd(fd);
	}
	if (line)
		free(line);
	return (1);
}

int	parse_map_section(t_game *g, int fd, char *first_line)
{
	char	*rows[4096];
	int		total;
	int		i;
	int		len;

	rows[0] = first_line;
	if (!collect_rows(fd, rows, 1, &total))
		return (error_exit(g, "Map too large"));
	g->map.grid = malloc(sizeof(char *) * (total + 1));
	if (!g->map.grid)
		return (error_exit(g, "malloc failed"));
	g->map.rows = total;
	g->map.cols = 0;
	i = 0;
	while (i < total)
	{
		g->map.grid[i] = rows[i];
		len = strlen(rows[i]);
		if (len > g->map.cols)
			g->map.cols = len;
		i++;
	}
	g->map.grid[total] = NULL;
	return (1);
}
