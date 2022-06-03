/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coleta <coleta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 16:52:59 by coleta            #+#    #+#             */
/*   Updated: 2022/06/03 16:54:10 by coleta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

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
		if (str[i++] == '-')
			z = -1;
	while (str[i] >= 48 && str[i] <= 57)
	{
		if (n * z > 2147483647)
			return (-1);
		if (n * z < -2147483648)
			return (0);
		n = n * 10 + (str[i++] - 48);
		if ((str[i] < 48 || str[i] > 57) && str[i] != '\0')
			return (-1);
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
