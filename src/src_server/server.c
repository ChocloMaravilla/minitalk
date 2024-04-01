/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedina- <rmedina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 20:42:51 by rmedina-          #+#    #+#             */
/*   Updated: 2024/04/01 20:10:33 by rmedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

static void handlesignals(int sig)
{
	static int count = 0;
	static int lenght = 0;
	static int iterator = 0;
	static int flag = 0;
	static char *str;
	
	if(flag == 0)
	{
		if(sig == SIGUSR1)
			lenght |= (1 << count);
		else
			lenght |= (0 << count);
		// printf("count_lenght: %i\n", count);
		count++;
		if(count == 32)
		{
			printf("TEST_DEBUGER_FLAG_1\n");
			str = (char *)malloc(sizeof(char)*(lenght + 1));
			flag = 1;
			count = 0;
			printf("\nlenght_count: %i\n", lenght);
			lenght = 0;
		}
	}
	else
	{
		if(sig == SIGUSR1)
			str[lenght] = (str[lenght] | (1 << count));
		else
			str[lenght] = (str[lenght] | (0 << count));
		count++;
		// printf("\nlenght_str :%i\n", lenght);
		printf("count: %i\n", count);
		// printf("flag: %i\n", flag);
		// printf("str: %c\n", str[lenght]);
		if(count == 7)
		{
			printf("TEST_DEBUGER_FLAG_2\n");
			if(str[lenght] == '\0')
			{
				ft_printf("%s\n", str);
				free(str);
				lenght = 0;
				count = 0;
				flag = 0;
			}
		}
		lenght++;
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
