/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalfonso <nalfonso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/23 20:42:47 by nalfonso          #+#    #+#             */
/*   Updated: 2026/09/27 20:00:05 by nalfonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	turning_player(t_game *g, double angle)
{
	double	olddirx;
	double	oldplanex;

	olddirx = g->player.dir_x;
	oldplanex = g->player.plane_x;
	g->player.dir_x = olddirx * cos(angle) - g->player.dir_y * sin(angle);
	g->player.dir_y = olddirx * sin(angle) + g->player.dir_y * cos(angle);
	g->player.plane_x = oldplanex * cos(angle) - g->player.plane_y * sin(angle);
	g->player.plane_y = oldplanex * sin(angle) + g->player.plane_y * cos(angle);
}

static void	update_info(t_game *g, double posX, double posY)
{
	g->player.pos_x = posX;
	g->player.pos_y = posY;
}

static void	set_movement(t_game *g, double *pos_x, double *pos_y, int code)
{
	double	speed;

	speed = 0.05;
	if (code == 1)
	{
		*pos_x += g->player.dir_x * speed;
		*pos_y += g->player.dir_y * speed;
	}
	else if (code == 2)
	{
		*pos_x -= g->player.dir_x * speed;
		*pos_y -= g->player.dir_y * speed;
	}
	else if (code == 3)
	{
		*pos_x += -g->player.dir_y * speed;
		*pos_y += g->player.dir_x * speed;
	}
	else if (code == 4)
	{
		*pos_x += g->player.dir_y * speed;
		*pos_y += -g->player.dir_x * speed;
	}
}

void	relative_movement(t_game *g, int code)
{
	double	pos_x;
	double	pos_y;

	pos_x = g->player.pos_x;
	pos_y = g->player.pos_y;
	set_movement(g, &pos_x, &pos_y, code);
	if (!player_collision(g, pos_x, pos_y))
		update_info(g, pos_x, pos_y);
}
