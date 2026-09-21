/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalfonso <nalfonso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 18:19:57 by nalfonso          #+#    #+#             */
/*   Updated: 2026/09/20 22:32:27 by nalfonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"


// This is still the same structure

double	rayDistance(double pos, int map, double deltaDistance, int step)
{
	double	rayDistance;

	if (step > 0)
		rayDistance = ((double)map + 1.0 - pos) * deltaDistance;
	else
		rayDistance = (pos - (double)map) * deltaDistance;
	return (rayDistance);
}

void	distanceCalculation(t_game *g, t_data *data, int side, double sideDistX, double sideDistY, int x)
{
	double	perpWallDist;
	int		lineHeight;
	int		drawStart;
	int		drawEnd;
	int		y;

	if (side == 0)
		perpWallDist = sideDistX - data->deltaDistX;
	else if(side == 1)
		perpWallDist = sideDistY - data->deltaDistY;
	if (perpWallDist < epsilon)
		perpWallDist = 0.0001;
	lineHeight = (int)(WIN_H/perpWallDist);
	draw_parameters(&drawStart, &drawEnd, lineHeight);
	textures_paramaters(g, data, perpWallDist, side, drawStart, lineHeight);
	y = drawStart;
	while(y <= drawEnd)
	{
		data->tex_y = (int)data->tex_pos & (g->tex->height - 1);
		data->tex_pos += data->step;
		data->pixel = g->tex[data->tex].addr + (data->tex_y * g->tex[data->tex].line_len + data->tex_x * (g->tex[data->tex].bpp / 8));
		data->color = *(unsigned int *)data->pixel;
		put_pixel(g, x, y, data->color);
		y++;
	}
}

void ray_calculation(t_game *g, t_data *data, double sideDistX, double sideDistY, int x)
{
	int hit = 0;
	int side;
	
	while (hit == 0)
	{
	if (sideDistX < sideDistY)
	{
		sideDistX += data->deltaDistX;
		data->mapX += data->stepX;
		if (data->mapX > g->map.cols || data->mapX < 0)
			return ;	
		side = 0;
	}
	else
	{
		sideDistY += data->deltaDistY;
		data->mapY += data->stepY;
		if (data->mapY > g->map.rows || data->mapY < 0)
			return ;
		side = 1;
	}
	if (g->map.grid[data->mapY][data->mapX] == '1')
		hit = 1;
	}
	distanceCalculation(g, data ,side, sideDistX, sideDistY, x);
}

void	set_parameters(t_game *g, t_data *data, int x)
{
	data->mapX = (int )g->player.pos_x;
	data->mapY = (int )g->player.pos_y;
	data->deltaDistX = fabs(1 / data->rayDirX);
	data->deltaDistY = fabs(1 / data->rayDirY);
	data->rayDistX = rayDistance(g->player.pos_x, data->mapX, data->deltaDistX, data->stepX);
	data->rayDistY = rayDistance(g->player.pos_y, data->mapY, data->deltaDistY, data->stepY);
	if ((g->map.grid[data->mapY][data->mapX] == '1'))
		return ;
	ray_calculation(g, data, data->rayDistX, data->rayDistY, x);
}


void raycast(t_game *g)
{
	t_data	data;
	int		x;
	double	cameraX;

	init_data(&data);
	x = -1;
	while (++x < g->win_w)
	{
		cameraX = (2.0 * (double)x) / (double)g->win_w - 1.0;
		data.rayDirX = g->player.dir_x + g->player.plane_x * cameraX;
		data.rayDirY = g->player.dir_y + g->player.plane_y * cameraX;
		data.stepX = direction(data.stepX, data.rayDirX);
		data.stepY = direction(data.stepY, data.rayDirY);
		set_parameters(g, &data, x);
	}
}
