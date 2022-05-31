/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spectator_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coleta <coleta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 18:22:24 by coleta            #+#    #+#             */
/*   Updated: 2022/05/31 20:49:32 by coleta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*spectator(void *philo_v)
{
	long	time;
	t_philo	*philo;

	philo = (t_philo*)philo_v;
	while (1)
	{
		time = get_time() - philo->last_eat;
		if (time > philo->date->time_to_die)
		{
			philo->live = 0;
			sem_wait(philo->date->take_fork);
			massage(philo, "dead");
			sem_wait(philo->date->message);
			exit(4);
		}
	}
}
