/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedina- <rmedina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 20:10:53 by ruben             #+#    #+#             */
/*   Updated: 2024/04/04 16:06:42 by rmedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	count;

	c = (char)c;
	count = 0;
	while (s[count])
	{
		if (s[count] == c)
			return ((char *)(s + count));
		count++;
	}
	if (!c)
		return ((char *)(s + count));
	return (NULL);
}

