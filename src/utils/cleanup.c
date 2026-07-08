/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalfonso <nalfonso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 22:28:27 by nalfonso          #+#    #+#             */
/*   Updated: 2026/07/05 20:00:00 by nalfonso         ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

static void	free_map(t_map *map)
{
	int	i;

	if (!map->grid)
		return ;
	i = 0;
	while (i < map->rows)
	{
		free(map->grid[i]);
		i++;
	}
	free(map->grid);
	map->grid = NULL;
}

static void	free_textures(t_game *g)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		free(g->tex[i].path);
		g->tex[i].path = NULL;
		if (g->tex[i].img)
			mlx_destroy_image(g->mlx, g->tex[i].img);
		i++;
	}
}

void	cleanup(t_game *g)
{
	free_map(&g->map);
	if (g->mlx)
		free_textures(g);
	if (g->img && g->mlx)
		mlx_destroy_image(g->mlx, g->img);
	if (g->win && g->mlx)
		mlx_destroy_window(g->mlx, g->win);
	if (g->mlx)
	{
		mlx_destroy_display(g->mlx);
		free(g->mlx);
	}
}
