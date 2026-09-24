/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalfonso <nalfonso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/24 19:14:42 by nalfonso          #+#    #+#             */
/*   Updated: 2026/09/24 19:15:43 by nalfonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	convert_number(char *nb)
{
	int	i;
	int	nbr;

	i = 0;
	nbr = 0;
	while (nb[i])
	{
		nbr = nbr * 10 + (nb[i] - '0');
		if (nbr > 255)
			return (-1);
		i++;
	}
	return (nbr);
}

int	check_number(char *line, int start)
{
	int	c_count;

	c_count = 0;
	while (line[start] && line[start] != '\n')
	{
		if (!ft_isdigit(line[start]) && line[start] != ','
			&& line[start] != ' ' && line[start] != '\t')
			return (1);
		if (line[start] == ',')
			c_count++;
		start++;
	}
	if (c_count != 2)
		return (1);
	return (0);
}

char	*get_number(char *line, int start, int comma)
{
	int		c_start;
	int		end;
	int		count;
	char	*str;

	count = 1;
	while (count < comma)
	{
		while (line[start] && line[start] != ',')
			start++;
		if (line[start] != ',')
			return (NULL);
		start++;
		count++;
	}
	c_start = start;
	while (line[start] && line[start] != ',' && line[start] != '\n')
		start++;
	end = start;
	str = ft_substr(line, c_start, end - c_start);
	if (!str)
		return (NULL);
	return (aux_get_number(str));
}

char	*aux_get_number(char *str)
{
	char	*trimmed;
	int		i;

	i = 0;
	trimmed = ft_strtrim(str, " \t");
	free(str);
	if (!trimmed || trimmed[0] == '\0')
	{
		free(trimmed);
		return (NULL);
	}
	while (trimmed[i])
	{
		if (!ft_isdigit(trimmed[i]))
		{
			free(trimmed);
			return (NULL);
		}
		i++;
	}
	return (trimmed);
}
