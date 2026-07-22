/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalfonso <nalfonso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 18:19:57 by nalfonso          #+#    #+#             */
/*   Updated: 2026/07/22 22:49:05 by nalfonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

void raycast(t_game *g)
{
	int		i;
	double	cameraX;
	double	rayDirx = 0.0;
	double	rayDiry = 0.0;
	//double	rayDir = 0.0;

	i = 0;
	while (i < g->win_w)
	{
		//cameraX = camera_dir(g, (double)i);
		cameraX = (2.0 * (double)i) / (double)g->win_w - 1.0;
		rayDirx = g->player.dir_x + g->player.plane_x * cameraX;
		rayDiry = g->player.dir_y + g->player.plane_y * cameraX;
		//rayDir = rayDirx / rayDiry; rayDir = %f\n
		printf("Counter [%i]-| CameraX = %f | rayDirx = %f | rayDiry = %f |\n", i, cameraX , rayDirx, rayDiry);
		i++;
	}
}


// DDA variables 

// Formula for Lenght of the Ray 
// fabs(1/ rayDirX)

double	lenght_ray(t_game *g, double rayDir)
{
	double	lenght = 0.0;

	lenght = 1 / rayDir;

	return (lenght);
}

void checker(t_game *g, double rayDirX, double rayDirY)
{
	char	**map;
	int		y;
	int		x;
	double	deltaDisX;
	double	deltaDISy;

	map = g->map.grid;
	y = 0;
	while (y < g->win_h)
	{
		x = 0;
		while (x < g->win_w)
		{
			deltaDisX = lenght_ray(g, rayDirX);
			deltaDISy = lenght_ray(g, rayDirY);
			x++;
		}
		y++;
	}
}