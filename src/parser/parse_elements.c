/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalfonso <nalfonso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 20:00:00 by nalfonso          #+#    #+#             */
/*   Updated: 2026/07/05 20:00:00 by nalfonso         ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

static char	*skip_spaces(char *s)
{
	while (*s == ' ' || *s == '\t')
		s++;
	return (s);
}

static int	set_texture(t_game *g, int idx, char *line)
{
	char	*path;

	if (g->tex[idx].path)
		return (error_exit(g, "Duplicate texture identifier"));
	path = skip_spaces(line);
	g->tex[idx].path = strdup(path);
	if (!g->tex[idx].path)
		return (error_exit(g, "malloc failed"));
	return (1);
}

static int	parse_color(t_game *g, char *s, int *out)
{
	int		r;
	int		gr;
	int		b;
	char	*p;

	p = skip_spaces(s);
	r = atoi(p);
	p = strchr(p, ',');
	if (!p)
		return (error_exit(g, "Invalid color format"));
	gr = atoi(p + 1);
	p = strchr(p + 1, ',');
	if (!p)
		return (error_exit(g, "Invalid color format"));
	b = atoi(p + 1);
	if (r < 0 || r > 255 || gr < 0 || gr > 255 || b < 0 || b > 255)
		return (error_exit(g, "Color values must be 0-255"));
	*out = (r << 16) | (gr << 8) | b;
	return (1);
}

int	parse_element(t_game *g, char *line)
{
	if (!strncmp(line, "NO ", 3))
		return (set_texture(g, NO, line + 3));
	if (!strncmp(line, "SO ", 3))
		return (set_texture(g, SO, line + 3));
	if (!strncmp(line, "WE ", 3))
		return (set_texture(g, WE, line + 3));
	if (!strncmp(line, "EA ", 3))
		return (set_texture(g, EA, line + 3));
	if (!strncmp(line, "F ", 2))
		return (parse_color(g, line + 2, &g->map.floor_color));
	if (!strncmp(line, "C ", 2))
		return (parse_color(g, line + 2, &g->map.ceil_color));
	return (error_exit(g, "Unknown element in map file"));
}
