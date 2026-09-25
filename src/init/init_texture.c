/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalfonso <nalfonso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/06 20:08:48 by nalfonso          #+#    #+#             */
/*   Updated: 2026/09/24 19:50:24 by nalfonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	load_textures(t_game *g)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		g->tex[i].img = mlx_xpm_file_to_image(g->mlx, g->tex[i].path,
				&g->tex[i].width, &g->tex[i].height);
		if (!g->tex[i].img)
			return (1);
		g->tex[i].addr = mlx_get_data_addr(g->tex[i].img, &g->tex[i].bpp,
				&g->tex[i].line_len, &g->tex[i].endian);
		if (!g->tex[i].addr)
			return (1);
		i++;
	}
	return (0);
}
