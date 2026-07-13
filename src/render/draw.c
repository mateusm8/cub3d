/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalfonso <nalfonso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 20:00:00 by nalfonso          #+#    #+#             */
/*   Updated: 2026/07/05 20:00:00 by nalfonso         ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

void put_pixel(t_game *g, int x, int y, int color)
{
	char *pixel;

	if (x >= g->win_w|| x < 0 || y >= g->win_h || y < 0)
		return ;
	pixel = g->addr + (y * g->line_len + x *(g->bpp / 8));
	*(unsigned int *)pixel = color;
	// put_pixel(g, x + 1, y, color);
	// put_pixel(g, x, y + 1, color);
}

void draw(t_game *g)
{
	int x;
	int y;
	int half;

	half = g->win_h / 2;
	y = 0;
	while (y < g->win_h)
	{
		x = 0;
		while (x < g->line_len)
		{
			if (y < half)
				put_pixel(g, x, y, g->map.ceil_color);
			else
				put_pixel(g, x, y, g->map.floor_color);
			x++;
		}
		y++;
	}
}