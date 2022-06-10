/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coleta <coleta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 14:07:21 by coleta            #+#    #+#             */
/*   Updated: 2022/06/10 15:53:42 by coleta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	eating(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	massage(philo, "has taken a fork");
	pthread_mutex_lock(philo->right_fork);
	massage(philo, "has taken a fork");
	massage(philo, "is eating");
	pthread_mutex_lock(&philo->date->wait);
	philo->last_eat = get_time();
	philo->must_eat--;
	if (philo->must_eat == 0)
		philo->date->number_of_times_each_philosopher_must_eat--;
	pthread_mutex_unlock(&philo->date->wait);
	ft_sleep(philo->date->time_to_eat);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void	sleeping(t_philo *philo)
{
	massage(philo, "is sleeping");
	ft_sleep(philo->date->time_to_sleep);
}

void	think(t_philo *philo)
{
	massage(philo, "is thinking");
}

void	*life(void *philo_info)
{
	t_philo	*philo;

	philo = (t_philo *)philo_info;
	while (1)
	{
		eating(philo);
		sleeping(philo);
		think(philo);
	}
	return (NULL);
}
