/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalfonso <nalfonso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 18:19:57 by nalfonso          #+#    #+#             */
/*   Updated: 2026/09/15 22:50:09 by nalfonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

double	rayDistance(double pos, int map, double deltaDistance, int step)
{
	double	rayDistance;

	if (step > 0)
		rayDistance = ((double)map + 1.0 - pos) * deltaDistance;
	else
		rayDistance = (pos - (double)map) * deltaDistance;
	return (rayDistance);
}

int	direction(int step, double	rayDir)
{
	if (rayDir < 0)
		step = -1;
	else
		step = 1;	
	return (step);
}

void	distanceCalculation(t_game *g, int side, double sideDistX, double deltaDistX, double sideDistY, double deltaDistY, int x,  int stepX, int stepY, double rayDirX, double rayDirY)
{
	double	perpWallDist;
	int		lineHeight;
	int		drawStart;
	int		drawEnd;
	int		y;
	int		tex;
	char 	*pixel;
	int 	color;
	int		tex_x;
	int		tex_y;
	double		hitY;
	double		hitX;
	double		wallHit;
	double		tex_pos;
	double		step;

	if (side == 0)
		perpWallDist = sideDistX - deltaDistX;
	else if(side == 1)
		perpWallDist = sideDistY - deltaDistY;
	if (perpWallDist < epsilon)
		perpWallDist = 0.0001;
	lineHeight = (int)(WIN_H/perpWallDist);
	drawStart = -lineHeight / 2 + (WIN_H / 2);
	drawEnd = (lineHeight / 2) + (WIN_H / 2);
	if (drawStart < 0)
		drawStart = 0;
	if (drawEnd >= WIN_H)
		drawEnd = WIN_H - 1;
	hitY = g->player.pos_y + perpWallDist * rayDirY;
	hitX = g->player.pos_x + perpWallDist * rayDirX;
	if (side == 0)
		wallHit = hitY;
	else
		wallHit = hitX;
	wallHit -= floor(wallHit);
	tex = select_texture(stepX, stepY, side);
	step = (double)g->tex->height / lineHeight;
	tex_x = wallHit * g->tex->width;
	tex_pos = (drawStart - WIN_H / 2 + lineHeight / 2) * step;
	y = drawStart;
	while(y <= drawEnd)
	{
		tex_y = (int)tex_pos & (g->tex->height - 1);
		tex_pos += step;
		pixel = g->tex[tex].addr + (tex_y * g->tex[tex].line_len + tex_x * (g->tex[tex].bpp / 8));
		color = *(unsigned int *)pixel;
		put_pixel(g, x, y, color);
		y++;
	}
}

void ray_calculation(t_game *g, double sideDistX, double sideDistY, double deltaDistX, double deltaDistY, int mapX, int mapY, int stepX, int stepY, int x, double rayDirX, double rayDirY)
{
 
  int hit = 0;
  int side;

  while (hit == 0)
  {
	if (sideDistX < sideDistY)
	{
		sideDistX += deltaDistX;
		mapX += stepX;
		if (mapX > g->map.cols || mapX < 0)
			return ;	
		side = 0;
	}
	else
	{
		sideDistY += deltaDistY;
		mapY += stepY;
		if (mapY > g->map.rows || mapY < 0)
			return ;
		side = 1;
	}
	if (g->map.grid[mapY][mapX] == '1')
		hit = 1;
	}
	// return hit
	if (hit == 1)
		distanceCalculation(g ,side, sideDistX, deltaDistX, sideDistY, deltaDistY, x, stepX, stepY, rayDirX, rayDirY);
}

int checker(t_game *g, double rayDirX, double rayDirY, int stepX, int stepY, int x)
{
	double	deltaDisX;
	double	deltaDisY;
	double	rayDistX;
	double	rayDistY;
	int		mapX;
	int		mapY;

	mapX = (int )g->player.pos_x;
	mapY = (int )g->player.pos_y;
	deltaDisX = fabs(1 / rayDirX);
	deltaDisY = fabs(1 / rayDirY);
	rayDistX = rayDistance(g->player.pos_x, mapX, deltaDisX, stepX);
	rayDistY = rayDistance(g->player.pos_y, mapY, deltaDisY, stepY);
	if ((g->map.grid[mapY][mapX] == '1'))
		return (1);
	ray_calculation(g, rayDistX, rayDistY, deltaDisX, deltaDisY, mapX, mapY, stepX, stepY, x, rayDirX, rayDirY);
	return (0);
}


void raycast(t_game *g)
{
	int		x;
	int		stepX;
	int		stepY;
	double	cameraX;
	double	rayDirx = 0.0;
	double	rayDiry = 0.0;

	x = -1;
	while (++x < g->win_w)
	{
		cameraX = (2.0 * (double)x) / (double)g->win_w - 1.0;
		rayDirx = g->player.dir_x + g->player.plane_x * cameraX;
		rayDiry = g->player.dir_y + g->player.plane_y * cameraX;
		stepX = direction(stepX, rayDirx);
		stepY = direction(stepY, rayDiry);
		if (checker(g, rayDirx, rayDiry, stepX, stepY, x))
			break;
	}
}
