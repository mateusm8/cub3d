/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalfonso <nalfonso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/27 19:44:51 by nalfonso          #+#    #+#             */
/*   Updated: 2026/09/27 20:06:47 by nalfonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	colision(t_game *g, double posX, double posY)
{
	int	map_x;
	int	map_y;

	map_x = (int)posX;
	map_y = (int)posY;
	if (map_y < 0 || map_y >= g->win_h || map_x < 0 || map_x >= g->win_w)
		return (1);
	return (g->map.grid[(int)posY][(int)posX] == '1');
}

int	player_collision(t_game *g, double x, double y)
{
	double	r;

	r = 0.01;
	if (colision(g, x + r, y))
		return (1);
	if (colision(g, x - r, y))
		return (1);
	if (colision(g, x, y + r))
		return (1);
	if (colision(g, x, y - r))
		return (1);
	return (0);
}
