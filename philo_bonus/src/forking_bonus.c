/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forking_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coleta <coleta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 20:03:42 by coleta            #+#    #+#             */
/*   Updated: 2022/06/10 15:47:41 by coleta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

void	wait_fork(t_date *date)
{
	int	rez;
	int	n;

	n = 0;
	while (1)
	{
		waitpid(-1, &rez, 0);
		rez = rez >> 8;
		if (rez == 4)
			break ;
		if (rez == 5)
			n++;
		if (n == date->number_of_philosophers)
		{
			printf("%s", PA);
			break ;
		}
	}
}

int	for_fork(t_philo *philo)
{
	pthread_t	thread;

	if (pthread_create(&thread, NULL, spectator, philo) != 0)
		return (error(PE));
	if (pthread_detach(thread) != 0)
		return (error(PE));
	while (1)
	{
		sem_wait(philo->date->wait);
		if (!philo->live)
			exit (4);
		sem_post(philo->date->wait);
		eating(philo);
		sleeping(philo);
		think(philo);
	}
}

int	forking(t_date *date)
{
	int		i;
	pid_t	pid;

	i = 0;
	while (i < date->number_of_philosophers)
	{
		pid = fork();
		if (pid == 0)
		{
			if (for_fork(&date->philo[i]))
				return (1);
		}
		else if (pid > 0)
			date->philo[i].pid = pid;
		else
			return (error(FE));
		i ++;
	}
	return (1);
}
