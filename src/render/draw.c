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

/*
** Writes a single pixel color into the image buffer.
** Offset formula: y * line_len + x * (bpp / 8)
** bpp is bits per pixel, divide by 8 to get bytes per pixel.
*/
void	put_pixel(t_game *g, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= g->win_w || y < 0 || y >= g->win_h)
		return ;
	dst = g->addr + (y * g->line_len + x * (g->bpp / 8));
	*(unsigned int *)dst = color;
}

/*
** Fills the top half of the screen with the ceiling color
** and the bottom half with the floor color.
** Called once per frame before raycasting draws the walls.
*/
void	draw_floor_ceiling(t_game *g)
{
	int	x;
	int	y;
	int	half;

	half = g->win_h / 2;
	y = 0;
	while (y < g->win_h)
	{
		x = 0;
		while (x < g->win_w)
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
