/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalfonso <nalfonso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 22:49:30 by nalfonso          #+#    #+#             */
/*   Updated: 2026/07/05 15:25:37 by nalfonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef CUB3D_H
# define CUB3D_H

/* ── system includes ──────────────────────────────── */
# include <stdio.h>
# include <unistd.h>
# include <../minilibx-linux/mlx.h>
# include <../minilibx-linux/mlx_int.h>

/* ── structs ──────────────────────────────────────── */

typedef struct s_game
{
	void		*mlx; // Why i use this ???
	void		*win;
	double		width;
	double		lenght;
}	t_game;


# endif
