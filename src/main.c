/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalfonso <nalfonso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 22:07:11 by nalfonso          #+#    #+#             */
/*   Updated: 2026/07/05 16:48:25 by nalfonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

int main(int ac, char **av)
{
	t_game	g;

	g.win = NULL;
	g.win_w = 32;
	g.win_l = 32;
	g.mlx = mlx_init();
	if (!g.mlx)
	return (write(2, "Error\nmlx_init failed\n", 23), 1);
	g.win = mlx_new_window(g.mlx, 800, 600, "cub3d");
	if (!g.win)
	return (write(2, "Error\nmlx_new_windows failed\n", 30), 1);
	if (ac == 1 && av)
	printf("Cub3d\n");
	mlx_loop(g.mlx);	
	return 0;
}
