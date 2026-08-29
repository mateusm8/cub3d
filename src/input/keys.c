/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalfonso <nalfonso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 23:01:29 by nalfonso          #+#    #+#             */
/*   Updated: 2026/08/27 20:55:32 by nalfonso         ###   ########.fr       */
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
	//printf("%d\n", key_code);
	if (key_code == KEY_ESC)
		handle_close(g);
	else if(key_code == KEY_W)
		relative_movement(g, 0.5, 'F');
	else if(key_code == KEY_S)
		relative_movement(g, 0.5, 'B');
	else if(key_code == KEY_A)
		relative_movement(g, 0.5, 'L');
	else if(key_code == KEY_D)
		relative_movement(g, 0.5, 'R');
	else if(key_code == KEY_RIGHT)
		turning_player(g, 0.04);
	else if(key_code == KEY_LEFT)
		turning_player(g, -0.04);
	return (0);
}
