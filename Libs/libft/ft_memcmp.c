/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedina- <rmedina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 16:11:55 by ruben             #+#    #+#             */
/*   Updated: 2024/04/04 16:06:57 by rmedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			count;
	unsigned char	*word1;
	unsigned char	*word2;

	word1 = (unsigned char *)s1;
	word2 = (unsigned char *)s2;
	count = 0;
	while (count < n)
	{
		if (!(word1[count] == word2[count]))
		{
			return (word1[count] - word2[count]);
		}
		else
		{
			count++;
		}
	}
	return (0);
}

