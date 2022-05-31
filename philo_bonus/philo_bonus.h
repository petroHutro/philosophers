/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coleta <coleta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 12:48:34 by coleta            #+#    #+#             */
/*   Updated: 2022/05/31 16:04:30 by coleta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include "s_philo_bonus.h"

int		parsing(int argc, char **argv, t_date *date);
int		init(t_date *date);
void	*spectator(void *date_v);
void	eating(t_philo *philo);
void	sleeping(t_philo *philo);
void	think(t_philo *philo);
void	forking(t_date *date);
long	get_time(void);
void	massage(t_philo *philo, char *str);
void	ft_sleep(int time_ms);
int		ft_atoi(const char *str);

#endif
