/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedina- <rmedina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 18:08:53 by rmedina-          #+#    #+#             */
/*   Updated: 2024/03/26 22:45:26 by rmedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

static int  send_length(int pid, char *str)
{
	size_t	len;
	int		octet;

	octet = 0;
	len = ft_strlen(str);
	while (octet < 32)
	{
		if ((len & (1 << octet)) == 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		octet++;
	}
	return (SUCCESS);
}

static int checking_pid(char *argv)
{
	int	i;

	i = 0;
	while (argv[i] != '\0' && ft_isdigit(argv[i]))
		i++;
	if (argv[i] != '\0')
		return (ERROR);
	return (SUCCESS);
}

int main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
	{
		write(2, "Error argumentos", 17);
		return (ERROR);
	}
	if (checking_pid(argv[1]) == ERROR)
		return (ERROR);
	pid = ft_atoi(argv[1]);
	send_length(pid, argv[2]);
	return (SUCCESS);
}