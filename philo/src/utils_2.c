/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coleta <coleta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 15:26:49 by coleta            #+#    #+#             */
/*   Updated: 2022/05/26 15:59:34 by coleta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	valid(int argc, char **argv)
{
	int	i;

	if (argc != 5 && argc != 6)
		return (1);
	i = 0;
	while (argv[++i])
		if (ft_atoi(argv[i]) < 1)
			return (1);
	return (0);
}

int	parsing(int argc, char **argv, t_date *date)
{
	if (valid(argc, argv))
		return (1);
	date->number_of_philosophers = ft_atoi(argv[1]);
	date->time_to_die = ft_atoi(argv[2]);
	date->time_to_eat = ft_atoi(argv[3]);
	date->time_to_sleep = ft_atoi(argv[4]);
	date->number_of_times_each_philosopher_must_eat = -1;
	if (argc == 6)
		date->number_of_times_each_philosopher_must_eat = date->number_of_philosophers * ft_atoi(argv[5]);
	return (0);
}

static void	free_malloc(t_date *date)
{
	if (date->philo)
	{
		free(date->philo);
		date->philo = NULL;
	}
	if (date->threads)
	{
		free(date->threads);
		date->threads = NULL;
	}
	if (date->fork)
	{
		free(date->fork);
		date->fork = NULL;
	}
}

void	clear(t_date *date)
{
	int	i;

	pthread_mutex_destroy(&date->message);
	i = 0;
	while (i < date->number_of_philosophers)
	{
		date->philo[i].live = 0;
		if (&date->fork[i])
			pthread_mutex_destroy(&date->fork[i++]);
	}
	free_malloc(date);
}
