/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedina- <rmedina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 20:42:51 by rmedina-          #+#    #+#             */
/*   Updated: 2024/04/02 21:11:15 by rmedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

static void handlesignals(int sig)
{
	static int count = 0;
	static int lenght = 0;
	static int flag = 0;
	static char *str;
	
	if(flag == 0)
	{
		if(sig == SIGUSR1)
			lenght |= (1 << count);
		else
			lenght |= (0 << count);
		count++;
		if(count == 32)
		{
			printf("#------TEST_DEBUGER_FLAG_1------#\n");
			str = (char *)malloc(sizeof(char)*(lenght + 1));
			iterator = lenght;
			flag = 1;
			count = 0;
			printf("lenght_count: %i\n", lenght);
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
		// ft_printf("count_me: %i\n", count);
		if(count == 8)
		{
			printf("#-----TEST_DEBUGER_FLAG_2------#\n");
			printf("str: %c\n", str[lenght]);
			lenght++;
			if(str[lenght] == '\0')
			{
				// ft_printf("\nlenght_str :%i\n", lenght);
				// ft_printf("flag: %i\n", flag);
				// ft_printf("str: %c\n", str[lenght]);
				ft_printf("%s\n", str);
				free(str);
				lenght = 0;
				count = 0;
				flag = 0;
			}
			printf("Pasa por aqui\n");
			// lenght = 0;
		}
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
