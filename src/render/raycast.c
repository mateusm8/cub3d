/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalfonso <nalfonso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 18:19:57 by nalfonso          #+#    #+#             */
/*   Updated: 2026/09/24 18:58:32 by nalfonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	raydistance(double pos, int map, double deltaDistance, int step)
{
	double	raydistance;

	if (step > 0)
		raydistance = ((double)map + 1.0 - pos) * deltaDistance;
	else
		raydistance = (pos - (double)map) * deltaDistance;
	return (raydistance);
}

void	distancecalculation(t_game *g, t_data *data, int x)
{
	double	perpwalldist;
	int		drawstart;
	int		drawend;
	int		y;

	perpwalldist = 0.0;
	init_perwall(data, &perpwalldist);
	data->lineheight = (int)(WIN_H / perpwalldist);
	draw_parameters(&drawstart, &drawend, data->lineheight);
	textures_paramaters(g, data, perpwalldist, drawstart);
	y = drawstart;
	while (y <= drawend)
	{
		data->tex_y = (int)data->tex_pos & (g->tex->height - 1);
		data->tex_pos += data->step;
		data->pixel = g->tex[data->tex].addr + (data->tex_y
				* g->tex[data->tex].line_len
				+ data->tex_x * (g->tex[data->tex].bpp / 8));
		data->color = *(unsigned int *)data->pixel;
		put_pixel(g, x, y, data->color);
		y++;
	}
}

void	ray_calculation(t_game *g, t_data *data, int x)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (data->sideDistX < data->sideDistY)
		{
			data->sideDistX += data->deltaDistX;
			data->mapX += data->stepX;
			if (data->mapX > g->map.cols || data->mapX < 0)
				return ;
			data->side = 0;
		}
		else
		{
			data->sideDistY += data->deltaDistY;
			data->mapY += data->stepY;
			if (data->mapY > g->map.rows || data->mapY < 0)
				return ;
			data->side = 1;
		}
		if (g->map.grid[data->mapY][data->mapX] == '1')
			hit = 1;
	}
	distancecalculation(g, data, x);
}

void	set_parameters(t_game *g, t_data *data, int x)
{
	data->mapX = (int )g->player.pos_x;
	data->mapY = (int )g->player.pos_y;
	data->deltaDistX = fabs(1 / data->rayDirX);
	data->deltaDistY = fabs(1 / data->rayDirY);
	data->rayDistX = raydistance(g->player.pos_x, data->mapX,
			data->deltaDistX, data->stepX);
	data->rayDistY = raydistance(g->player.pos_y, data->mapY,
			data->deltaDistY, data->stepY);
	if (g->map.grid[data->mapY][data->mapX] == '1')
		return ;
	data->sideDistX = data->rayDistX;
	data->sideDistY = data->rayDistY;
	ray_calculation(g, data, x);
}

void	raycast(t_game *g)
{
	t_data	data;
	double	camera_x;
	int		x;

	init_data(&data);
	x = -1;
	while (++x < g->win_w)
	{
		camera_x = (2.0 * (double)x) / (double)g->win_w - 1.0;
		data.rayDirX = g->player.dir_x + g->player.plane_x * camera_x;
		data.rayDirY = g->player.dir_y + g->player.plane_y * camera_x;
		data.stepX = direction(data.stepX, data.rayDirX);
		data.stepY = direction(data.stepY, data.rayDirY);
		set_parameters(g, &data, x);
	}
}
