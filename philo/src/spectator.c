/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spectator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coleta <coleta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 17:05:11 by coleta            #+#    #+#             */
/*   Updated: 2022/06/10 15:53:39 by coleta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	check_number(t_date *date)
{
	if (date->number_of_times_each_philosopher_must_eat == 0)
	{
		printf("%s", PA);
		return (1);
	}
	return (0);
}

int	spectator(t_date *date)
{
	int		i;
	long	time;

	while (1)
	{
		i = 0;
		while (i < date->number_of_philosophers)
		{
			pthread_mutex_lock(&date->wait);
			if (check_number(date))
				return (1);
			time = get_time() - date->philo[i].last_eat;
			if (time >= date->time_to_die)
			{
				massage(&date->philo[i], "died");
				pthread_mutex_lock(&date->message);
				return (1);
			}
			pthread_mutex_unlock(&date->wait);
			i++;
		}
	}
	return (1);
}
