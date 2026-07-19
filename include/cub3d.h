/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalfonso <nalfonso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 22:49:30 by nalfonso          #+#    #+#             */
/*   Updated: 2026/07/05 20:00:00 by nalfonso         ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

# ifndef CUB3D_H
# define CUB3D_H

/* ── system includes ──────────────────────────────── */
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <unistd.h>
# include <../minilibx-linux/mlx.h>

/* ── window ───────────────────────────────────────── */
# define WIN_W 1200
# define WIN_H 800

/* ── key codes ───────────────────────────────────────── */

# define KEY_ESC	65307
# define KEY_W		119
# define KEY_S		115
# define KEY_A		97
# define KEY_D		100
# define KEY_RIGHT
# define KEY_LEFT

/* ── texture index ────────────────────────────────── */
# define NO 0
# define SO 1
# define WE 2
# define EA 3

/* ── structs ──────────────────────────────────────── */
typedef struct s_texture
{
	char	*path;
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		width;
	int		height;
}	t_texture;

typedef struct s_map
{
	char	**grid;
	int		rows;
	int		cols;
	int		floor_color;
	int		ceil_color;
}	t_map;

typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}	t_player;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			bpp;
	int			line_len;
	int			endian;
	int			win_w;
	int			win_h;
	t_player	player;
	t_texture	tex[4];
	t_map		map;
}	t_game;

/* ── prototypes ───────────────────────────────────── */
int		init_game(t_game *g);
void	init_player(t_game *g);
void	cleanup(t_game *g);
int		error_exit(t_game *g, char *msg);
int		parse_file(t_game *g, char *path);
int		handle_key(int key_code, void *param);
int		handle_close(t_game *g);
void	raycast(t_game *g);

# endif
