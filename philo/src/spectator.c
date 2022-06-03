/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spectator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coleta <coleta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 17:05:11 by coleta            #+#    #+#             */
/*   Updated: 2022/06/03 16:43:26 by coleta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	spectator(t_date *date)
{
	int		i;
	long	time;

	while (date->number_of_times_each_philosopher_must_eat)
	{
		i = 0;
		while (i < date->number_of_philosophers && \
		date->number_of_times_each_philosopher_must_eat)
		{
			pthread_mutex_lock(&date->message);
			time = get_time() - date->philo[i].last_eat;
			if (time >= date->time_to_die)
			{
				date->philo[i].live = 0;
				pthread_mutex_unlock(&date->message);
				massage(&date->philo[i], "dead");
				pthread_mutex_lock(&date->message);
				return (1);
			}
			i ++;
			pthread_mutex_unlock(&date->message);
		}
	}
	printf("%s", PA);
	return (1);
}
