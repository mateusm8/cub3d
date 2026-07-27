/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalfonso <nalfonso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 18:19:57 by nalfonso          #+#    #+#             */
/*   Updated: 2026/07/27 22:57:52 by nalfonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

void checker(t_game *g, double rayDirX, double rayDirY);

void raycast(t_game *g)
{
	int		i;
	double	cameraX;
	double	rayDirx = 0.0;
	double	rayDiry = 0.0;

	i = 0;
	while (i < g->win_w)
	{
		cameraX = (2.0 * (double)i) / (double)g->win_w - 1.0;
		rayDirx = g->player.dir_x + g->player.plane_x * cameraX;
		rayDiry = g->player.dir_y + g->player.plane_y * cameraX;
		printf("Counter [%i]-| CameraX = %f | rayDirx = %f | rayDiry = %f | ", i, cameraX , rayDirx, rayDiry);
		checker(g, rayDirx, rayDiry);
		i++;
	}
}

// DDA variables 

// Formula for Lenght of the Ray 
// fabs(1/ rayDirX)

void checker(t_game *g, double rayDirX, double rayDirY)
{
	double	deltaDisX;
	double	deltaDisY;
	int		mapX;
	int		mapY;

	mapX = (int )g->player.pos_x;
	mapY = (int )g->player.pos_y;
	deltaDisX = fabs(1 / rayDirX);
	deltaDisY = fabs(1 / rayDirY);
	printf(" mapX = %i | mapY = %i | deltaDistX = %f | deltaDistY = %f\n", mapX, mapY, deltaDisX, deltaDisY);
}


/* 
distance =  posX - mapX;
rayDistance = deltaDisX * distance == rayDistance = (posX - mapx) * deltaDisX;
 */


 void implemetation(t_game *g, double sideDistX, double sideDistY, int mapX, int mapY)
{
 
  int hit = 0;
  int side;

  while (hit == 0)
  {
	if (sideDistX < sideDistY)
      {
        sideDistX += deltaDisX;
		mapX += stepX;
		side = 0;
      }
      else
      {
        sideDistY += deltaDistY;
		mapY += stepY;
		side = 1;
      }
	  if (g->map.grid[mapX][mapY] > 0)
		hit = 1;
  }
}
