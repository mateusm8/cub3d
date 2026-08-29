/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalfonso <nalfonso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/23 20:42:47 by nalfonso          #+#    #+#             */
/*   Updated: 2026/08/27 22:56:48 by nalfonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

void	move_player(t_game *g, double posX, double posY)
{
	if (posX < 0 || posY < 0 || posX >= g->win_w || posY >= g->win_h)
		return ;
	if (g->map.grid[(int)posY][(int)posX] == '1')
		return ;
	g->map.grid[(int)g->player.pos_y][(int)g->player.pos_x] = '0';
	g->map.grid[(int)posY][(int)posX] = 'N';
	g->player.pos_x = posX;
	g->player.pos_y = posY;
	render_frame(g);
}

void turning_player(t_game *g, double angle)
{
	double	oldDirX;
	double oldPlaneX;

	oldDirX = g->player.dir_x;
	oldPlaneX = g->player.plane_x;
	g->player.dir_x = oldDirX * cos(angle) - g->player.dir_y * sin(angle);
	g->player.dir_y = oldDirX * sin(angle) + g->player.dir_y * cos(angle);
	g->player.plane_x = oldPlaneX * cos(angle) - g->player.plane_y * sin(angle);
	g->player.plane_y = oldPlaneX * sin(angle) + g->player.plane_y * cos(angle);
	//(x' = x·cos(a) − y·sin(a), y' = x·sin(a) + y·cos(a)
	render_frame(g);
}

static int	colision(t_game *g, double posX, double posY)
{
	
	if (g->map.grid[(int)posY][(int)posX] == '1')
		return (1);
	return(0);
}

void	relative_movement(t_game *g, double speed, char code)
{
	double	posX;	//decalre this in the function 
	double	posY;

	posX = g->player.pos_x;
	posY = g->player.pos_y;
	if (code == 'F')
	{
		posX += g->player.dir_x * speed;
		posY += g->player.dir_y * speed;
		if (colision(g, posX, posY))
			return ;
		g->player.pos_x = posX;
		g->player.pos_y = posY;
		g->map.grid[(int)g->player.pos_y][(int)g->player.pos_x] = '0';
		g->map.grid[(int)g->player.pos_y][(int)g->player.pos_x] = 'N';
		render_frame(g);

	}
	else if (code == 'B')
	{
		posX -= g->player.dir_x * speed;
		posY -= g->player.dir_y * speed;
		if (colision(g, posX, posY))
			return ;
		g->player.pos_x = posX;
		g->player.pos_y = posY;
		g->map.grid[(int)g->player.pos_y][(int)g->player.pos_x] = '0';
		g->map.grid[(int)g->player.pos_y][(int)g->player.pos_x] = 'N';
		render_frame(g);
	}
	else if (code == 'L')
	{
		posX += -g->player.dir_y * speed;
		posY += g->player.dir_x * speed;
		if (colision(g, posX, posY))
			return ;
		g->player.pos_x = posX;
		g->player.pos_y = posY;
		g->map.grid[(int)g->player.pos_y][(int)g->player.pos_x] = '0';
		g->map.grid[(int)g->player.pos_y][(int)g->player.pos_x] = 'N';
		render_frame(g);
	}
	else if (code == 'R')
	{
		posX += g->player.dir_y * speed;
		posY += -g->player.dir_x * speed;
		if (colision(g, posX, posY))
			return ;
		g->player.pos_x = posX;
		g->player.pos_y = posY;
		g->map.grid[(int)g->player.pos_y][(int)g->player.pos_x] = '0';
		g->map.grid[(int)g->player.pos_y][(int)g->player.pos_x] = 'N';
		render_frame(g);
	}
}





// For the same lines that i repeat in relative movement, i can do a function thah just to the update since is the same lines implement later in this way update_info();