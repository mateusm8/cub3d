/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalfonso <nalfonso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 23:01:29 by nalfonso          #+#    #+#             */
/*   Updated: 2026/07/18 14:34:16 by nalfonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

int handle_close(t_game *g)
{
	//cleanup(g); Find the cause of this 
	(void)g;
	exit(0);
	return (0);
}


int handle_key(int key_code, void *param)
{
	t_game	*g;

	g = (t_game *)param;
	if (key_code == KEY_ESC)
		handle_close(g);
	return (0);
}
