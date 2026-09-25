/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalfonso <nalfonso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 23:01:29 by nalfonso          #+#    #+#             */
/*   Updated: 2026/09/25 23:17:53 by nalfonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void update_player(t_game *g)
{
	if (g->keys[K_W])
		relative_movement(g, 1);
	if (g->keys[K_S])
		relative_movement(g, 2);
	if (g->keys[K_A])
		relative_movement(g, 3);
	if (g->keys[K_D])
		relative_movement(g, 4);
	if (g->keys[K_LEFT])
		turning_player(g, -0.05);
	if (g->keys[K_RIGHT])
		turning_player(g, 0.05);
}

int	handle_close(t_game *g)
{
	mlx_loop_end(g->mlx);
	return (0);
}

int	handle_key(int key_code, void *param)
{
	t_game	*g;

	g = (t_game *)param;
	if (key_code == KEY_ESC)
		handle_close(g);
	else if (key_code == KEY_W)
		g->keys[K_W] = 1;
	else if (key_code == KEY_S)
		g->keys[K_S] = 1;
	else if (key_code == KEY_A)
		g->keys[K_A] = 1;
	else if (key_code == KEY_D)
		g->keys[K_D] = 1;
	else if (key_code == KEY_RIGHT)
		g->keys[K_RIGHT] = 1;
	if (key_code == KEY_LEFT)
		g->keys[K_LEFT] = 1;
	return (0);
}

int	handle_key_release(int key_code, void *param)
{
	t_game	*g;

	g = (t_game *)param;
	if (key_code == KEY_ESC)
		handle_close(g);
	else if (key_code == KEY_W)
		g->keys[K_W] = 0;
	else if (key_code == KEY_S)
		g->keys[K_S] = 0;
	else if (key_code == KEY_A)
		g->keys[K_A] = 0;
	else if (key_code == KEY_D)
		g->keys[K_D] = 0;
	else if (key_code == KEY_RIGHT)
		g->keys[K_RIGHT] = 0;
	else if (key_code == KEY_LEFT)
		g->keys[K_LEFT] = 0;
	return (0);
}
