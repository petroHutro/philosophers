/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coleta <coleta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 19:38:58 by coleta            #+#    #+#             */
/*   Updated: 2022/06/10 15:54:09 by coleta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

void	eating(t_philo *philo)
{
	sem_wait(philo->date->take_fork);
	sem_wait(philo->date->fork);
	massage(philo, "has taken a fork");
	sem_wait(philo->date->fork);
	massage(philo, "has taken a fork");
	sem_post(philo->date->take_fork);
	massage(philo, "is eating");
	sem_wait(philo->date->wait);
	philo->last_eat = get_time();
	philo->date->number_of_times_each_philosopher_must_eat--;
	sem_post(philo->date->wait);
	ft_sleep(philo->date->time_to_eat);
	sem_post(philo->date->fork);
	sem_post(philo->date->fork);
	if (!philo->date->number_of_times_each_philosopher_must_eat)
		exit (5);
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
