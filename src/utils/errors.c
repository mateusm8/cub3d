/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalfonso <nalfonso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 22:28:27 by nalfonso          #+#    #+#             */
/*   Updated: 2026/07/05 20:00:00 by nalfonso         ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

int	error_exit(t_game *g, char *msg)
{
	write(2, "Error\n", 6);
	write(2, msg, strlen(msg));
	write(2, "\n", 1);
	cleanup(g);
	return (0);
}
