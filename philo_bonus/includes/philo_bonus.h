/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coleta <coleta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 12:48:34 by coleta            #+#    #+#             */
/*   Updated: 2022/06/03 18:08:38 by coleta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdio.h>
# include "s_philo_bonus.h"

int		parsing(int argc, char **argv, t_date *date);
int		init(t_date *date);
void	*spectator(void *date_v);
void	eating(t_philo *philo);
void	sleeping(t_philo *philo);
void	think(t_philo *philo);
int		forking(t_date *date);
long	get_time(void);
void	massage(t_philo *philo, char *str);
void	ft_sleep(int time_ms);
int		ft_atoi(const char *str);
int		error(char *str);
void	clear(t_date *date);
void	wait_fork(t_date *date);

# ifndef PHILO_ERROS
#  define PHILO_ERROS

#  define AE "Argument error\n"
#  define NE "Error number of Arguments\n"
#  define MAE "Malloc error\n"
#  define MUE "Mutex error\n"
#  define PE "Pthread error\n"
#  define SE "Semaphore error\n"
#  define PA "Philosophers ate\n"
#  define FE "Fork error\n"
# endif

#endif
