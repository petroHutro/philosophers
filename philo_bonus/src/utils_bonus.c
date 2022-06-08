/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coleta <coleta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 12:50:19 by coleta            #+#    #+#             */
/*   Updated: 2022/06/07 18:51:58 by coleta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

int	error(char *str)
{
	printf("%s", str);
	return (1);
}

static int	valid(int argc, char **argv)
{
	int	i;

	if (argc != 5 && argc != 6)
		return (error(NE));
	i = 0;
	while (argv[++i])
		if (ft_atoi(argv[i]) < 1)
			return (error(AE));
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
		date->number_of_times_each_philosopher_must_eat = ft_atoi(argv[5]);
	return (0);
}

static void	sem_free(t_date *date)
{
	if (date->fork)
	{
		sem_close(date->fork);
		sem_unlink("Fork");
	}
	if (date->message)
	{
		sem_close(date->message);
		sem_unlink("Message");
	}
	if (date->take_fork)
	{
		sem_close(date->take_fork);
		sem_unlink("Take");
	}
}

void	clear(t_date *date)
{
	int	i;

	i = 0;
	while (i < date->number_of_philosophers)
	{
		date->philo[i].live = 0;
		if (date->philo[i].pid)
			kill(date->philo[i].pid, 9);
		i++;
	}
	if (date->philo)
	{
		free(date->philo);
		date->philo = NULL;
	}
	sem_free(date);
	exit(1);
}
