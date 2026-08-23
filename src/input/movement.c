/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalfonso <nalfonso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/23 20:42:47 by nalfonso          #+#    #+#             */
/*   Updated: 2026/08/23 21:26:33 by nalfonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

void	move_player(t_game *g, double posX, double posY, double planeX, double planeY)
{
	if (posX < 0 || posY < 0 || posX >= g->win_w || posY >= g->win_h || planeX < 0 || planeY < 0)
		return ;
	if (g->map.grid[(int)posY][(int)posX] == '1')
		return ;
	g->map.grid[(int)g->player.pos_y][(int)g->player.pos_x] = '0';
	g->map.grid[(int)posY][(int)posX] = 'N';
	g->player.pos_x = posX;
	g->player.pos_y = posY;
	g->player.dir_x = planeX;
	g->player.dir_y = planeY;
	render_frame(g);
}