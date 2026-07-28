/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matmagal <matmagal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 19:49:47 by matmagal          #+#    #+#             */
/*   Updated: 2026/07/28 20:36:23 by matmagal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	*ft_realloc(void *ptr, size_t old, size_t new)
{
	void	*new_ptr;
	size_t	copy_size;
	if (ptr == NULL)
		return (malloc(new));
	if (new == 0)
	{
		free(ptr);
		return (NULL);
	}
	new_ptr = malloc(new);
	if (!new_ptr)
		return (NULL);
	copy_size = old;
	if (new < old)
		copy_size = new;
	ft_memcpy(new_ptr, ptr, copy_size);
	free(ptr);
	return (new_ptr);
}
