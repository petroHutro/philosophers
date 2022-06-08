/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coleta <coleta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 17:01:33 by coleta            #+#    #+#             */
/*   Updated: 2022/06/08 21:43:38 by coleta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	init_malloc(t_date *date)
{
	date->philo = malloc(sizeof(t_philo) * date->number_of_philosophers);
	date->threads = malloc(sizeof(pthread_t) * date->number_of_philosophers);
	date->fork = malloc(sizeof(pthread_mutex_t) * date->number_of_philosophers);
	if (!date->fork || !date->threads || !date->philo)
		return (error(MAE));
	return (0);
}

static int	init_mutex(t_date *date)
{
	int	i;

	i = 0;
	while (i < date->number_of_philosophers)
		if (pthread_mutex_init(&date->fork[i++], NULL) != 0)
			return (error(MUE));
	if (pthread_mutex_init(&date->message, NULL))
		return (error(MUE));
	if (pthread_mutex_init(&date->wait, NULL))
		return (error(MUE));
	return (0);
}

static int	init_threads(t_date *date)
{
	int	i;

	i = 0;
	while (i < date->number_of_philosophers)
	{
		if (pthread_create(&date->threads[i], NULL, life, &date->philo[i]) != 0)
			return (error(PE));
		if (pthread_detach(date->threads[i]) != 0)
			return (error(PE));
		usleep(100);
		i ++;
	}
	return (0);
}

int	init(t_date *date)
{
	int	i;

	if (init_malloc(date) || init_mutex(date))
		return (1);
	i = 0;
	while (i < date->number_of_philosophers)
	{
		date->philo[i].date = date;
		date->philo[i].left_fork = &date->fork[i];
		date->philo[i].right_fork = &date->fork[(i + 1) \
		% date->number_of_philosophers];
		date->philo[i].id = i;
		date->philo[i].live = 1;
		date->philo[i].must_eat = \
		date->number_of_times_each_philosopher_must_eat;
		date->start = get_time();
		date->philo[i].last_eat = get_time();
		i ++;
	}
	date->number_of_times_each_philosopher_must_eat = date->number_of_philosophers;
	if (init_threads(date))
		return (1);
	return (0);
}
