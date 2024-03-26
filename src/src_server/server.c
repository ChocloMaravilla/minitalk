/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedina- <rmedina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 20:42:51 by rmedina-          #+#    #+#             */
/*   Updated: 2024/03/26 22:57:42 by rmedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

static void  handlesignals(int sig)
{
}

int main(void)
{
    pid_t   pid;
    int     len;

    pid = getpid();
    ft_printf("%d", pid);
    signal(SIGUSR1, handlesignals);
    signal(SIGUSR2, handlesignals);
}