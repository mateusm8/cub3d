/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matmagal <matmagal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/04 11:35:17 by matmagal          #+#    #+#             */
/*   Updated: 2026/07/13 12:21:12 by matmagal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	map_check(t_game_info *game)
{
	int	fd;
	char *line;

	fd = open(game->map_name, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		
	}
}

int main(int ac, char **av)
{
	t_game_info *game;

	if (ac == 2)
	{
		parse_one(av);
		game = malloc(sizeof(t_game_info));
		if (!game)
			return (1);
		init_game_info(game, av);
		free(game);
	}
	else
	{
		printf ("Error\nUsage: ./cub3D map.cub\n");
		return (1);
	}
	return (0);
}
