/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matmagal <matmagal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 17:30:20 by matmagal          #+#    #+#             */
/*   Updated: 2026/07/05 17:43:07 by matmagal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	parse_one(char **av)
{
	if (!check_file(av[1], ".cub"))
	{
		printf("Error\nInvalid file extension (expected .cub)\n");
		exit (1);
	}
}
