/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forking_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coleta <coleta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 20:03:42 by coleta            #+#    #+#             */
/*   Updated: 2022/05/31 20:54:08 by coleta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	for_fork(t_philo *philo)
{
	pthread_t	thread;

	if (pthread_create(&thread, NULL, spectator, philo) != 0)
		return (1);
	if (pthread_detach(thread) != 0)
		return (1);
	while (philo->live)
	{
		eating(philo);
		sleeping(philo);
		think(philo);
	}
	exit (4);
}

void	forking(t_date *date)
{
	int		i;
	pid_t	pid;

	i = 0;
	while (i < date->number_of_philosophers)
	{
		pid = fork();
		if (pid == 0)
			for_fork(&date->philo[i]);
		else if (pid > 0)
			date->philo[i].pid = pid;
		else
			; //ERROR
		i ++;
	}
}
