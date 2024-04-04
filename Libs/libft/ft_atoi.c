/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedina- <rmedina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 17:51:23 by ruben             #+#    #+#             */
/*   Updated: 2024/04/04 16:07:16 by rmedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	a;
	int	nb;
	int	sign;

	sign = 1;
	a = 0;
	nb = 0;
	while (str[a] == ' ' || str[a] == '\n'
		|| str[a] == '\t' || str[a] == '\r'
		|| str[a] == '\f' || str[a] == '\v')
		a++;
	if (str[a] == '-')
	{
		sign = -1;
		a++;
	}
	else if (str[a] == '+')
		a++;
	while (str[a] >= 48 && str[a] <= 57)
	{
		nb = (nb * 10) + (str[a] - '0');
		a++;
	}
	return (nb * sign);
}

