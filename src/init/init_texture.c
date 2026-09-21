/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalfonso <nalfonso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/06 20:08:48 by nalfonso          #+#    #+#             */
/*   Updated: 2026/09/20 22:37:37 by nalfonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_data(t_data *data)
{
	data->rayDirX = 0.0;
	data->rayDirY = 0.0;
	data->stepX = 0;
	data->stepY = 0;
	data->deltaDistX = 0.0;
	data->deltaDistY = 0.0;
	data->mapX = 0;
	data->mapX = 0;
	data->rayDirX = 0.0;
	data->rayDirX = 0.0;
}

void	load_textures(t_game *g)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		g->tex[i].img = mlx_xpm_file_to_image(g->mlx, g->tex[i].path,
				&g->tex[i].width, &g->tex[i].height);
		if (!g->tex[i].img)
		{
			error_exit(g, "Init Textures failed\n");
			return ;
		}
		g->tex[i].addr = mlx_get_data_addr(g->tex[i].img, &g->tex[i].bpp,
				&g->tex[i].line_len, &g->tex[i].endian);
		i++;
	}
}
