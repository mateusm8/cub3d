/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalfonso <nalfonso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 22:07:11 by nalfonso          #+#    #+#             */
/*   Updated: 2026/07/05 20:00:00 by nalfonso         ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

int	render_frame(t_game *g);

int	main(int ac, char **av)
{
	t_game	g;

	if (ac != 2)
		return (write(2, "Error\nUsage: ./Cub3d <map.cub>\n", 31), 1);
	if (!init_game(&g))
		return (error_exit(&g, "Init failed"), 1);
	init_player(&g);
	if (!parse_file(&g, av[1]))
		return (1);
	mlx_loop_hook(g.mlx, render_frame, &g);
	mlx_hook(g.win, 2, 1L << 0, handle_key, &g);
	mlx_hook(g.win, 17, 0, handle_close, &g);
	mlx_loop(g.mlx);
	cleanup(&g);
	return (0);
}
