/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matmagal <matmagal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/04 11:11:53 by matmagal          #+#    #+#             */
/*   Updated: 2026/07/05 17:17:02 by matmagal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

typedef enum s_directions
{
	NO,
	SO,
	WE,
	EA
} t_directions;

typedef struct s_colors
{
	int	r;
	int	g;
	int	b;
} t_colors;

typedef struct s_player
{
	int		x;
	int		y;
	char	dir;
} t_player;

typedef struct s_game_info
{
	char		*map_name;
	char		*tex[4];
	t_colors	floor;
	t_colors	ceil;
	char		**map;
	int			map_width;
	int			map_height;
	t_player	player;
	int			player_count;
	int			has_tex[4];
	int			has_floor;
	int			has_ceil;
} t_game_info;

void	init_game_info(t_game_info *game);

#endif
