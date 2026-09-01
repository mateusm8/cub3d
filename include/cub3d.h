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
# include <math.h>
# include "../minilibx-linux/mlx.h"
# include "get_next_line.h"

/* ── window ───────────────────────────────────────── */
# define WIN_W 1200
# define WIN_H 800

/* ── key codes ───────────────────────────────────────── */

# define KEY_ESC	65307
# define KEY_W		119
# define KEY_S		115
# define KEY_A		97
# define KEY_D		100
# define KEY_RIGHT	65361
# define KEY_LEFT	65363

/* ── texture index ────────────────────────────────── */
# define NO 0
# define SO 1
# define WE 2
# define EA 3

/* Parser data */
typedef int	t_directions;

typedef struct s_colors
{
	int	r;
	int	g;
	int	b;
}	t_colors;

typedef struct s_parse_player
{
	int		x;
	int		y;
	char	dir;
}	t_parse_player;

typedef struct s_game_info
{
	char		*map_name;
	char		*tex[4];
	t_colors	floor;
	t_colors	ceil;
	char		**map;
	int		map_width;
	int		map_height;
	t_parse_player	player;
	int		player_count;
	int		has_tex[4];
	int		has_floor;
	int		has_ceil;
}	t_game_info;

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
void	raycast(t_game *g);
void 	put_pixel(t_game *g, int x, int y, int color);
int		render_frame(t_game *g);

/* ── player move ───────────────────────────────────── */
void	move_player(t_game *g, double posX, double posY);
int		handle_key(int key_code, void *param);
int		handle_close(t_game *g);
void	turning_player(t_game *g, double angle);
void	relative_movement(t_game *g, double speed, char code);


/* Parser */
void	init_game_info(t_game_info *game, char **av);
void	parse_one(t_game_info *game);
void	parse_cub_file(t_game_info *game);
int	is_in_map(t_game_info *game, char *line, int *in_map);
int	line_is_empty(char *line);
int	is_map_line(char *line);
int	add_map_line(t_game_info *game, char *line);
int	is_texture_line(char *line);
int	parse_texture_line(t_game_info *game, char *line);
int	change_tex_status(t_game_info *game, int i, char *line, t_directions tex);
int	is_color_line(char *line);
int	parse_color_line(t_game_info *game, char *line);
int	change_floor_status(t_game_info *game, int i, char *line);
int	change_ceil_status(t_game_info *game, int i, char *line);
int	check_file(char *map_name, char *extension);
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *str);
char	*ft_substr(const char *s, unsigned int start, size_t len);
int	rm_spc(char *line, int k);
int	ft_isdigit(char c);
char	*ft_strtrim(char const *s1, char const *set);
void	*ft_memcpy(void *dest, const void *src, size_t num);
void	*ft_realloc(void *ptr, size_t old, size_t new);
int	check_game_struct(t_game_info *game, char *line);
int	parse_player(t_game_info *game, char *line);
void	parser_error_exit(t_game_info *game, char *msg);
int	check_number(char *line, int start);
char	*get_number(char *line, int start, int comma);
char	*aux_get_number(char *str);
int	pick_color(char *line, int start, int comma);
void	validate_map(t_game_info *game);
int	validate_pos(t_game_info *game, int y, int x);
int	is_walkable(char c);
int	validade_walls(t_game_info *game);
void	free_map(char **map);
void	free_tex(t_game_info *game);
void	free_game_info(t_game_info *game);
int	convert_number(char *nb);
int	is_whitespace(char c);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);

# endif
