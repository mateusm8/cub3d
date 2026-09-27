/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_02.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalfonso <nalfonso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 14:38:46 by matmagal          #+#    #+#             */
/*   Updated: 2026/09/27 19:07:48 by nalfonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_whitespace(char c)
{
	return (c == ' ' || c == '\t');
}

int	rm_spc(char *line, int k)
{
	while (is_whitespace(line[k]))
		k++;
	return (k);
}

int	is_valid_position(t_game *g, int x, int y)
{
	if (y < 0 || y >= g->win_h)
		return (0);
	if (x < 0 || x >= (int)ft_strlen(g->map.grid[y]))
		return (0);
	return (1);
}
