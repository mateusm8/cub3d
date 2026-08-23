/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalfonso <nalfonso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 23:01:29 by nalfonso          #+#    #+#             */
/*   Updated: 2026/08/23 21:38:07 by nalfonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

int handle_close(t_game *g)
{
	//exit(0);
	mlx_loop_end(g->mlx);
	return (0);
}


int handle_key(int key_code, void *param)
{
	t_game	*g;

	g = (t_game *)param;
	if (key_code == KEY_ESC)
		handle_close(g);
	else if(key_code == KEY_W)
		move_player(g, g->player.pos_x, g->player.pos_y + 1.0, g->player.plane_x, g->player.plane_y);
	else if(key_code == KEY_S)
		move_player(g, g->player.pos_x, g->player.pos_y - 1.0, g->player.plane_x, g->player.plane_y);
	else if(key_code == KEY_A)
		move_player(g, g->player.pos_x - 1.0, g->player.pos_y, g->player.plane_x, g->player.plane_y);
	else if(key_code == KEY_D)
		move_player(g, g->player.pos_x + 1.0, g->player.pos_y, g->player.plane_x, g->player.plane_y);
	else if(key_code == KEY_RIGHT)
		move_player(g, g->player.pos_x, g->player.pos_y + 1.0, g->player.plane_x + 1.0, g->player.plane_y);
	else if(key_code == KEY_LEFT)
		move_player(g, g->player.pos_x, g->player.pos_y + 1.0, g->player.plane_x - 1.0, g->player.plane_y);
	return (0);
}
