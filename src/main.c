/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalfonso <nalfonso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 22:07:11 by nalfonso          #+#    #+#             */
/*   Updated: 2026/07/05 15:28:50 by nalfonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

int main(int ac, char **av)
{
	t_game	g;

	if (ac == 1 && av)
		printf("Cub3d\n");
		
	g.win = NULL;
	g.mlx = NULL;
	g.lenght = 64;
	g.width = 64;
	g.win = mlx_new_window(g.mlx, g.width * 64, g.lenght *64, "cub3d");
	if (!g.win)
		return (write(2, "Error\nmlx_new_windows failed\n", 30), 1);	
	return 0;
}
