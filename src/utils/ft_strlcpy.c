/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matmagal <matmagal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 18:35:28 by matmagal          #+#    #+#             */
/*   Updated: 2026/09/01 11:43:10 by matmagal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size != 0)
	{
		while (i < size - 1 && src[i])
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}

/*int	main(void)
{
	char src[] = "Hello World";
	char dst[50];

	printf("%zu, %s\n", ft_strlcpy(dst, src, 14), dst);
	printf("%zu\n", ft_strlen(src));
	for (int i = 0; i < 20; i++)
    	printf("src[%d] = %c (ASCII: %d)\n", i, src[i], src[i]);

}*/
