/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coleta <coleta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 19:38:58 by coleta            #+#    #+#             */
/*   Updated: 2022/05/31 20:12:11 by coleta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	eating(t_philo *philo)
{
	sem_wait(philo->date->take_fork);
	sem_wait(philo->date->fork);
	massage(philo, "take fork left");
	sem_wait(philo->date->fork);
	massage(philo, "take fork right");
	sem_post(philo->date->take_fork);
	massage(philo, "eat");
	philo->last_eat = get_time();
	philo->date->number_of_times_each_philosopher_must_eat--;
	ft_sleep(philo->date->time_to_eat);
	sem_post(philo->date->fork);
	sem_post(philo->date->fork);
	if (!philo->date->number_of_times_each_philosopher_must_eat)
		exit (5);
}

void	sleeping(t_philo *philo)
{
	massage(philo, "sleep");
	ft_sleep(philo->date->time_to_sleep);
}

void	think(t_philo *philo)
{
	massage(philo, "think");
}
