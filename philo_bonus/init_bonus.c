/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coleta <coleta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 12:48:49 by coleta            #+#    #+#             */
/*   Updated: 2022/05/31 16:43:03 by coleta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static int	init_malloc(t_date *date)
{
	date->philo = malloc(sizeof(t_philo) * date->number_of_philosophers);
	if (!date->philo)
		return (1);
	return (0);
}

static int	init_sem(t_date *date)
{
	sem_unlink("Fork");
	sem_unlink("Message");
	sem_unlink("Take");
	date->take_fork = sem_open("Take", O_CREAT | O_EXCL, 644, 1);
	date->fork = sem_open("Fork", O_CREAT | O_EXCL, 644, date->number_of_philosophers);
	date->message = sem_open("Message", O_CREAT | O_EXCL, 644, 1);
	if (date->fork == SEM_FAILED || date->message == SEM_FAILED || date->take_fork  == SEM_FAILED)
		return (1);
	return (0);
}

int	init(t_date *date)
{
	int	i;

	if (init_malloc(date) || init_sem(date))
		return (1);
	i = 0;
	while (i < date->number_of_philosophers)
	{
		date->philo[i].date = date;
		date->philo[i].id = i;
		date->philo[i].live = 1;
		date->start = get_time();
		date->philo[i].last_eat = get_time();
		i ++;
	}
	return (0);
}
