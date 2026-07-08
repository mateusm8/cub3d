/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalfonso <nalfonso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 22:29:41 by nalfonso          #+#    #+#             */
/*   Updated: 2026/07/05 20:00:00 by nalfonso         ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

void	init_player(t_game *g)
{
	g->player.pos_x = 2.0;
	g->player.pos_y = 2.0;
	g->player.dir_x = -1.0;
	g->player.dir_y = 0.0;
	g->player.plane_x = 0.0;
	g->player.plane_y = 0.66;
}

