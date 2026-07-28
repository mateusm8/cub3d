/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matmagal <matmagal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 14:36:52 by matmagal          #+#    #+#             */
/*   Updated: 2026/07/28 14:41:42 by matmagal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_texture_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	return ((line[i] == 'N' && line[i + 1] == 'O' && line[i + 2] == ' ')
		|| (line[i] == 'S' && line[i + 1] == 'O' && line[i + 2] == ' ')
		|| (line[i] == 'W' && line[i + 1] == 'E' && line[i + 2] == ' ')
		|| (line[i] == 'E' && line[i + 1] == 'A' && line[i + 2] == ' '));
}

void	parse_texture_line(t_game_info *game, char *line)
{
	int	i;
	
	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if ((line[i] == 'N' && line[i + 1] == 'O' && line[i + 2] == ' '))
		change_tex_status(game, i, line, NO);
	if ((line[i] == 'S' && line[i + 1] == 'O' && line[i + 2] == ' '))
		change_tex_status(game, i, line, SO);
	if ((line[i] == 'W' && line[i + 1] == 'E' && line[i + 2] == ' '))
		change_tex_status(game, i, line, WE);
	if ((line[i] == 'E' && line[i + 1] == 'A' && line[i + 2] == ' '))
		change_tex_status(game, i, line, EA);
}

void	change_tex_status(t_game_info *game, int i, char *line, t_directions tex)
{
	int	st;
	
	st = rm_spc(line, i + 3);
	if (game->has_tex[tex] == 0)
	{	
		game->tex[tex] = ft_substr(line, st, ft_fitstr(line, st));
		if (game->tex[tex] == NULL)
			error_exit();
		game->has_tex[tex] = 1;
	}
	else
		error_exit();
}
