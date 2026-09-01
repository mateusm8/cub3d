/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_02.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matmagal <matmagal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 14:38:46 by matmagal          #+#    #+#             */
/*   Updated: 2026/09/01 12:20:13 by matmagal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_whitespace(char c)
{
	return (c == ' ' || c == '\t');
}

int	rm_spc(char *line, int k)
{
	while(is_whitespace(line[k]))
		k++;
	return (k);	
}
