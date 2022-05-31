/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coleta <coleta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 12:50:19 by coleta            #+#    #+#             */
/*   Updated: 2022/05/31 18:21:58 by coleta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

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
		date->number_of_times_each_philosopher_must_eat =  ft_atoi(argv[5]);
	return (0);
}

static void	norm_l(int *i, int *z, long *n)
{
	*i = 0;
	*z = 1;
	*n = 0;
}

int	ft_atoi(const char *str)
{
	long	n;
	int		i;
	int		z;

	norm_l(&i, &z, &n);
	while (str[i] == ' ' || (str[i] > 8 && str[i] < 14))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			z = -1;
		i++;
	}
	while (str[i] != '\0' && (str[i] >= 48 && str[i] <= 57))
	{
		if (n * z > 2147483647)
			return (-1);
		else
			if (n * z < -2147483648)
				return (0);
		n = n * 10 + (str[i] - 48);
		i ++;
	}
	return (n * z);
}

long	get_time(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return ((current_time.tv_sec * 1000) + (current_time.tv_usec / 1000));
}

void	massage(t_philo *philo, char *str)
{
	sem_wait(philo->date->message);
	printf("%ld %lu %s\n", get_time() - philo->date->start, philo->id + 1, str);
	sem_post(philo->date->message);
}

void	ft_sleep(int time_ms)
{
	long	time_now;

	time_now = get_time();
	usleep(time_ms * 920);
	while (get_time() < time_now + (long)time_ms)
		usleep(100);
}
