/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalfonso <nalfonso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 18:19:57 by nalfonso          #+#    #+#             */
/*   Updated: 2026/07/19 15:58:09 by nalfonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

/* static double camera_dir(t_game *g, double x)
{
	// cameraX = 2 * x / win_w - 1

	double	cameraX = 0.0;

	cameraX = (2 * x) / (g->win_w - 1);

	return (cameraX);
} */

void raycast(t_game *g)
{
	int		i;
	double	cameraX;
	double	rayDirx = 0.0;
	double	rayDiry = 0.0;
	double	rayDir = 0.0;

	i = 0;
	while (i < g->win_w)
	{
		//cameraX = camera_dir(g, (double)i);
		cameraX = (2.0 * (double)i) / (double)g->win_w - 1;
		rayDirx = g->player.dir_x + (g->player.plane_x * cameraX);
		rayDiry = g->player.dir_y + (g->player.plane_y * cameraX);
		rayDir = rayDirx / rayDiry;
		printf("Counter [%i] -- rayDirx = %f, rayDiry = %f, rayDir = %f\n",i , rayDirx, rayDiry, rayDir);
		i++;
	}
}
