/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalfonso <nalfonso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/06 20:25:17 by nalfonso          #+#    #+#             */
/*   Updated: 2026/09/06 21:23:54 by nalfonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

void	load_textures(t_game *g)
{
	int	i;

	i = 0;
	while(i < 4)
	{
		g->tex[i].img = mlx_xpm_file_to_image(g->mlx, g->tex[i].path, &g->tex[i].width, &g->tex[i].height);
		if (!g->tex[i].img)
		{
			error_exit(g, "Init Textures failed\n");
			return ;
		}
		mlx_get_data_addr(g->tex[i].img, &g->tex[i].bpp, &g->tex[i].line_len, &g->tex[i].endian);
		i++;
	}
}
