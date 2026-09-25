/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalfonso <nalfonso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 18:19:57 by nalfonso          #+#    #+#             */
/*   Updated: 2026/09/25 19:20:39 by nalfonso         ###   ########.fr       */
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
		if (data->sidedist_x < data->sidedist_y)
		{
			data->sidedist_x += data->deltadist_x;
			data->map_x += data->step_x;
			if (data->map_x > g->map.cols || data->map_x < 0)
				return ;
			data->side = 0;
		}
		else
		{
			data->sidedist_y += data->deltadist_y;
			data->map_y += data->step_y;
			if (data->map_y > g->map.rows || data->map_y < 0)
				return ;
			data->side = 1;
		}
		if (g->map.grid[data->map_y][data->map_x] == '1')
			hit = 1;
	}
	distancecalculation(g, data, x);
}

void	set_parameters(t_game *g, t_data *data, int x)
{
	data->map_x = (int )g->player.pos_x;
	data->map_y = (int )g->player.pos_y;
	data->deltadist_x = fabs(1 / data->raydirx);
	data->deltadist_y = fabs(1 / data->raydiry);
	data->raydist_x = raydistance(g->player.pos_x, data->map_x,
			data->deltadist_x, data->step_x);
	data->raydist_y = raydistance(g->player.pos_y, data->map_y,
			data->deltadist_y, data->step_y);
	if (g->map.grid[data->map_y][data->map_x] == '1')
		return ;
	data->sidedist_x = data->raydist_x;
	data->sidedist_y = data->raydist_y;
	ray_calculation(g, data, x);
}

void	raycast(t_game *g)
{
	t_data	data;
	double	camera_x;
	int		x;

	x = -1;
	while (++x < g->win_w)
	{
		camera_x = (2.0 * (double)x) / (double)g->win_w - 1.0;
		data.raydirx = g->player.dir_x + g->player.plane_x * camera_x;
		data.raydiry = g->player.dir_y + g->player.plane_y * camera_x;
		data.step_x = direction(data.step_x, data.raydirx);
		data.step_y = direction(data.step_y, data.raydiry);
		set_parameters(g, &data, x);
	}
}
