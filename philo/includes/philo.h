/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coleta <coleta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 15:01:44 by coleta            #+#    #+#             */
/*   Updated: 2022/06/03 16:39:12 by coleta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include "s_philo.h"

long	get_time(void);
int		ft_atoi(const char *str);
int		init(t_date *date);
void	*life(void *date);
int		spectator(t_date *date);
void	massage(t_philo *philo, char *str);
void	ft_sleep(int time_ms);
int		clear(t_date *date);
int		parsing(int argc, char **argv, t_date *date);
int		error(char *str);

# ifndef PHILO_ERROS
#  define PHILO_ERROS

#  define AE "Argument error\n"
#  define NE "Error number of Arguments\n"
#  define MAE "Malloc error\n"
#  define MUE "Mutex error\n"
#  define PE "Pthread error\n"
#  define PA "Philosophers ate\n"
# endif

#endif
