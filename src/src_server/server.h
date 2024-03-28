/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedina- <rmedina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 21:47:55 by rmedina-          #+#    #+#             */
/*   Updated: 2024/03/28 01:23:46 by rmedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# define SUCCESS 0
# define ERROR 1

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <signal.h>
# include "../../Libs/ft_printf/ft_printf.h"

typedef struct s_ints
{
    int boolean;
    int current_bit;
    int len_malloc;
}   t_ints;


#endif