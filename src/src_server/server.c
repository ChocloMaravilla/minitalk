/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedina- <rmedina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 20:42:51 by rmedina-          #+#    #+#             */
/*   Updated: 2024/03/28 16:44:34 by rmedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

static void handlesignals(int sig)
{
	static int count = 0;
	static int lenght = 0;
	static int flag = 0;
	static int iterator = 0;
	static char *str;
	
	if(flag == 0)
	{
		if(sig == SIGUSR1)
			lenght |= (1 << count);
		count++;
		if(count == 32)
		{
			printf("TEST_DEBUGER_FLAG_1\n");
			str = (char *)malloc(sizeof(char)*(lenght + 1));
			flag = 1;
			lenght = 0;
			count = 0;
		}
	}
	else if(flag == 1)
	{
		if(sig == SIGUSR1)
			lenght |= (1 << count);
		count++;
		// printf("%i\n",count);
		if(count == 8)
		{
			printf("TEST_DEBUGER_FLAG_2\n");
			printf("lenght: %i\n", lenght);
			str[iterator] = lenght;
			if(str[iterator + 1])
			{
				ft_printf("%s\n", str);
				free(str);
				lenght = 0;
				count = 0;
				flag = 0;
				iterator = 0;	
			}
		}
		iterator++;
	}	
}

int main(void)
{
	pid_t	pid;


	pid = getpid();
	ft_printf("%i\n", pid);
	if((signal(SIGUSR1, handlesignals)) == SIG_ERR)
	{
		write(2,"Error en el manejo de señales con el signal",45);
		return (ERROR);
	}
	else if((signal(SIGUSR2, handlesignals)) == SIG_ERR)
	{
		write(2,"Error en el manejo de señales con el signal",45);
		return (ERROR);
	}
	while(1)
		sleep(1);
	return (0);
}
