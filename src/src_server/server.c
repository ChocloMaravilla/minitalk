/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedina- <rmedina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 20:42:51 by rmedina-          #+#    #+#             */
/*   Updated: 2024/04/09 22:18:58 by rmedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src_header/minitalk.h"

void str_fill(unsigned int *lenght, int *flag, unsigned char **str, int *count)
{
	if ((*str)[*lenght] == '\0')
		reset_var(str, lenght, flag);
	else
		*lenght += 1;
	*count = 0;
}
void reset_var(unsigned char **str, unsigned int *lenght, int *flag)
{
	ft_printf("%s\n", *str);
	free(*str);
	*lenght = 0;
	*flag = 0;
}

void str_memory( unsigned int *lenght, int *flag, unsigned char **str, int *count)
{
	*str = (unsigned char *)malloc(sizeof(*lenght));
	*flag = 1;
	*count = 0;
	*lenght = 0;
}
static void handlesignals(int sig)
{
	static int count = 0;
	static unsigned int lenght = 0;
	static int flag = 0;
	static unsigned char *str;
	
	if(flag == 0)
	{
		if(sig == SIGUSR1)
			lenght |= (1 << count);
		count++;
		if(count == 32)
			str_memory(&lenght, &flag,  &str, &count);
	}
	else
	{
		if(sig == SIGUSR1)
			str[lenght] = (str[lenght] | (1 << count));
		count++;
		if(count == 8)
			str_fill(&lenght, &flag, &str, &count);
	}
}

int main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_printf("%i\n", pid);
	if((signal(SIGUSR1, handlesignals)) == ((void *)ERROR_SIGNAL))
	{
		write(2,"Error en el manejo de señales con el signal",45);
		return (ERROR);
	}
	else if((signal(SIGUSR2, handlesignals)) == ((void *)ERROR_SIGNAL))
	{
		write(2,"Error en el manejo de señales con el signal",45);
		return (ERROR);
	}
	while(1)
		sleep(1);
	return (0);
}
