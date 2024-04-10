/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedina- <rmedina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 21:47:55 by rmedina-          #+#    #+#             */
/*   Updated: 2024/04/10 22:11:55 by rmedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# define SUCCESS 0
# define ERROR 1
# define ERROR_SIGNAL -1

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <signal.h>
# include "../../Libs/ft_printf/ft_printf.h"
# include "../../Libs/libft/libft.h"

void	reset_var(char **str, int *lenght, int *flag);
#endif
