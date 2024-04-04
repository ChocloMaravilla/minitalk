/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedina- <rmedina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 19:34:32 by rmedina-          #+#    #+#             */
/*   Updated: 2024/04/04 16:06:14 by rmedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	e;
	char	*d;
	char	*s;
	size_t	i;

	d = (char *)dst;
	s = (char *)src;
	i = ft_strlen(src);
	e = 0;
	if (!src || size == 0)
		return (i);
	while (s[e] && e < size - 1)
	{
		d[e] = s[e];
		e++;
	}
	d[e] = '\0';
	return (i);
}

