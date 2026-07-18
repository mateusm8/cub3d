/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalfonso <nalfonso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 18:19:57 by nalfonso          #+#    #+#             */
/*   Updated: 2026/07/19 00:55:28 by nalfonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"
static double camera_dir(t_game *g, int i)
{
	
}

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
		cameraX = camera_dir(g, i);
		if (i == g->win_w)
			break;
		rayDirx = g->player.dir_x + (g->player.plane_x * cameraX);
		rayDiry = g->player.dir_y + (g->player.plane_y * cameraX);
		rayDir = rayDirx / rayDiry;
		printf("rayDirx = %d, rayDiry = %d, rayDir = %d", rayDirx, rayDiry, rayDir);
		i++;
	}
}
