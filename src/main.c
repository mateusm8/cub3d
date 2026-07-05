/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matmagal <matmagal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/04 11:35:17 by matmagal          #+#    #+#             */
/*   Updated: 2026/07/04 11:48:56 by matmagal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main(int ac, char **av)
{
	t_game_info *game;

	game = malloc(sizeof(t_game_info));
	if (!game)
		return (1);
	init_game_info(game);
	free(game);
	return (0);
}
