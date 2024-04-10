/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedina- <rmedina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 18:08:53 by rmedina-          #+#    #+#             */
/*   Updated: 2024/04/10 21:34:16 by rmedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src_header/minitalk.h"

static int send_str(int pid, char *str)
{
	unsigned int	len;
	unsigned int	octet;
	unsigned int	count;
	
	count = 0;
	len = ft_strlen(str);
	while (count <= len)
	{
		octet = 0;
		while(octet < 8)
		{
			if (((str[count] >> octet) & 1) == 1)
				kill(pid, SIGUSR1);
			else if(((str[count] >> octet) & 1) == 0)
				kill(pid, SIGUSR2);
			usleep(200);
			octet++;
		}
		count++;
	}
	return (SUCCESS);
}

static int  send_length(int pid, char *str)
{
	int		len;
	int		octet;
	octet = 0;
	len = ft_strlen(str);
	while (octet < 32)
	{
		if (((len >> octet) & 1) == 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		octet++;
		usleep(1000);
	}
	return (SUCCESS);
}

static int checking_pid( char *argv)
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
		write(2, "Error to many or few arguments", 31);
		return (ERROR);
	}
	if(!argv[2] || argv[2] == NULL)
		return (0);
	if (checking_pid(argv[1]) == ERROR)
		return (ERROR);
	pid = ft_atoi(argv[1]);
	send_length(pid, argv[2]);
	send_str(pid, argv[2]);
	return (SUCCESS);
}
