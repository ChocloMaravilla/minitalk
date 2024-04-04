/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedina- <rmedina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 16:49:47 by ruben             #+#    #+#             */
/*   Updated: 2024/04/04 16:06:13 by rmedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	c;
	size_t	f;

	f = ft_strlen(dst);
	if (!src || f >= size)
		return (ft_strlen(src) + size);
	c = 0;
	while (src[c] && c + f < size - 1)
	{
		dst[f + c] = src[c];
		c++;
	}
	dst[f + c] = '\0';
	return (f + ft_strlen(src));
}

