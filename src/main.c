/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matmagal <matmagal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/04 11:35:17 by matmagal          #+#    #+#             */
/*   Updated: 2026/09/01 11:33:13 by matmagal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main(int ac, char **av)
{
	t_game_info *game;

	if (ac == 2)
	{
		game = malloc(sizeof(t_game_info));
		if (!game)
			return (1);
		init_game_info(game, av);
		parse_one(game);
		free_game(game);
	}
	else
	{
		printf ("Error\nUsage: ./cub3D map.cub\n");
		return (1);
	}
	return (0);
}
