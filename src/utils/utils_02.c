/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_02.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalfonso <nalfonso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 14:38:46 by matmagal          #+#    #+#             */
/*   Updated: 2026/09/24 19:17:28 by nalfonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_whitespace(char c)
{
	return (c == ' ' || c == '\t');
}

int	rm_spc(char *line, int k)
{
	while (is_whitespace(line[k]))
		k++;
	return (k);
}
