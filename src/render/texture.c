/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalfonso <nalfonso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/06 20:25:17 by nalfonso          #+#    #+#             */
/*   Updated: 2026/09/25 19:24:07 by nalfonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	select_texture(int stepX, int stepY, int side)
{
	if (side == 0)
	{
		if (stepX > 0)
			return (NO);
		else
			return (SO);
	}
	else
	{
		if (stepY > 0)
			return (WE);
		else
			return (EA);
	}
}

int	direction(int step, double rayDir)
{
	if (rayDir < 0)
		step = -1;
	else
		step = 1;
	return (step);
}

void	init_perwall(t_data *data, double *perpWallDist)
{
	if (data->side == 0)
		*perpWallDist = data->sidedist_x - data->deltadist_x;
	else if (data->side == 1)
		*perpWallDist = data->sidedist_y - data->deltadist_y;
	if (*perpWallDist < EPSILON)
		*perpWallDist = 0.0001;
}

void	draw_parameters(int *drawStart, int *drawEnd, int lineHeight)
{
	*drawStart = -lineHeight / 2 + (WIN_H / 2);
	*drawEnd = (lineHeight / 2) + (WIN_H / 2);
	if (*drawStart < 0)
		drawStart = 0;
	if (*drawEnd >= WIN_H)
		*drawEnd = WIN_H - 1;
}

void	textures_paramaters(t_game *g, t_data *data, double perpWallDist,
	int drawStart)
{
	data->hit_y = g->player.pos_y + perpWallDist * data->raydiry;
	data->hit_x = g->player.pos_x + perpWallDist * data->raydirx;
	if (data->side == 0)
		data->wallhit = data->hit_y;
	else
		data->wallhit = data->hit_x;
	data->wallhit -= floor(data->wallhit);
	data->tex = select_texture(data->step_x, data->step_y, data->side);
	data->step = (double)g->tex->height / data->lineheight;
	data->tex_x = data->wallhit * g->tex->width;
	data->tex_pos = (drawStart - WIN_H / 2 + data->lineheight / 2) * data->step;
}
