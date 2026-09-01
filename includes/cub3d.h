/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matmagal <matmagal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/04 11:11:53 by matmagal          #+#    #+#             */
/*   Updated: 2026/09/01 11:32:57 by matmagal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "get_next_line.h"

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

void	init_game_info(t_game_info *game, char **av);
void	parse_one(t_game_info *game);
void	parse_file(t_game_info *game);
int		is_in_map(t_game_info *game, char *line, int *in_map);
int		line_is_empty(char *line);
int		is_map_line(char *line);
int		is_header_line(char *line);
int		add_map_line(t_game_info *game, char *line);
int		add_tex_flag(t_game_info *game, t_directions dir);
int		is_texture_line(char *line);
int		parse_texture_line(t_game_info *game, char *line);
int		change_tex_status(t_game_info *game, int i, char *line,
			t_directions tex);
int		is_color_line(char *line);
int		parse_color_line(t_game_info *game, char *line);
int		change_floor_status(t_game_info *game, int i, char *line);
int		change_ceil_status(t_game_info *game, int i, char *line);
int		check_file(char *map_name, char *extension);
int		ft_strlen(char *str);
char	*ft_strdup(const char *str);
char	*ft_substr(const char *s, unsigned int start, size_t len);
int		ft_fitstr(char *line, int start);
int		rm_spc(char *line, int k);
int		ft_atoi(const char *str);
int		ft_isdigit(char c);
char	*ft_strtrim(char const *s1, char const *set);
void	*ft_memcpy(void *dest, const void *src, size_t num);
void	*ft_realloc(void *ptr, size_t old, size_t new);
int		check_game_struct(t_game_info *game, char *line);
int		parse_player(t_game_info *game, char *line);
void	error_exit(t_game_info *game, char *msg);
int		check_number(char *line, int start);
char	*get_number(char *line, int start, int comma);
char	*aux_get_number(char *str);
int		pick_color(char *line, int start, int comma);
void	validate_map(t_game_info *game);
int		validate_pos(t_game_info *game, int y, int x);
int		is_walkable(char c);
int		validade_walls(t_game_info *game);
void	free_map(char **map);
void	free_tex(t_game_info *game);
void	free_game(t_game_info *game);

#endif
