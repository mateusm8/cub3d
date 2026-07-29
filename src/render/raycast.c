/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalfonso <nalfonso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 18:19:57 by nalfonso          #+#    #+#             */
/*   Updated: 2026/07/29 18:24:50 by nalfonso         ###   ########.fr       */
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

void ray_calculation(t_game *g, double sideDistX, double sideDistY, double deltaDistX, double deltaDistY, int mapX, int mapY, int stepX, int stepY)
{
 
  int hit = 0;
  //int side;

  while (hit == 0)
  {
	if (sideDistX < sideDistY)
	  {
		sideDistX += deltaDistX;
		mapX += stepX;
		//side = 0;
	  }
	  else
	  {
		sideDistY += deltaDistY;
		mapY += stepY;
		//side = 1;
	  }
	  if (g->map.grid[mapX][mapY] > 0)
		hit = 1;
	printf(" MapX = %i, MapY = %i  sideDistX [%f] , sideDistY [%f] \n", mapX, mapY, sideDistX, sideDistY);
  }
}

void checker(t_game *g, double rayDirX, double rayDirY, int stepX, int stepY)
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
	printf(" mapX = %i | mapY = %i | deltaDistX = %f | deltaDistY = %f | rayDistX = %f | rayDistX = %f", mapX, mapY, deltaDisX, deltaDisY, rayDistX, rayDistY);
	ray_calculation(g, rayDistX, rayDistY, deltaDisX, deltaDisY, mapX, mapY, stepX, stepY);
}


void raycast(t_game *g)
{
	int		x;
	int		y;
	int		stepX;
	int		stepY;
	double	cameraX;
	double	rayDirx = 0.0;
	double	rayDiry = 0.0;
	
	y = 0;
	while (y < g->win_h)
	{
		x = -1;
		while (++x < g->win_w)
		{
			cameraX = (2.0 * (double)x) / (double)g->win_w - 1.0;
			rayDirx = g->player.dir_x + g->player.plane_x * cameraX;
			rayDiry = g->player.dir_y + g->player.plane_y * cameraX;
			stepX = direction(stepX, rayDirx);
			stepY = direction(stepY, rayDiry);
			printf("Counter [%i][%i]-| CameraX = %f | rayDirx = %f | rayDiry = %f | stepX = %i | stepY = %i",y, x, cameraX , rayDirx, rayDiry, stepX, stepY);
			checker(g, rayDirx, rayDiry, stepX, stepY);
		}
		y++;
	}
}



/* 
distance =  posX - mapX;
rayDistance = deltaDisX * distance == 

rayDistanceX = (posX - mapx) * deltaDisX;
rayDistanceX = (mapX + 1 - posX) * deltaDistX;


rayDistanceY = (posY - mapx) * deltaDisY;
rayDistanceY = (mapY + 1 - posX) * deltaDistY;
 */

 

