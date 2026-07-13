/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_01.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matmagal <matmagal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 17:26:37 by matmagal          #+#    #+#             */
/*   Updated: 2026/07/06 12:08:37 by matmagal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	map_start(char *str)
{
	int	i;
	int	last_slash;

	if (!str)
		return (0);
	i = 0;
	last_slash = -1;
	while (str[i])
	{
		if (str[i] == '/')
			last_slash = i;
		i++;
	}
	return (last_slash + 1);
}

int	check_file(char *map_name, char *extension)
{
	int	i;
	int	k;
	int	start;
	int	fd;

	k = 0;
	start = map_start(map_name);
	if (ft_strlen(map_name + start) <= ft_strlen(extension))
		return (0);
	i = start + ft_strlen(map_name + start) - ft_strlen(extension);
	fd = open(map_name, O_RDONLY);
	if (fd < 0)
		return (0);
	while (extension[k])
	{
		if (map_name[i + k] != extension[k])
			return (close(fd), 0);
		k++;
	}
	if (map_name[i + k] != '\0' || extension[k] != '\0')
		return (close(fd), 0);
	close (fd);
	return (1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *str)
{
	size_t	i;
	char	*ptr;

	i = 0;
	ptr = (char *) malloc((ft_strlen(str) + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	while (i < ft_strlen((char *) str))
	{
		ptr[i] = str[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
