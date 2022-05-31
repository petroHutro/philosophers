/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_philo.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coleta <coleta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 17:40:37 by coleta            #+#    #+#             */
/*   Updated: 2022/05/26 15:43:47 by coleta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_PHILO_H
# define S_PHILO_H

# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_philo
{
	long			last_eat;
	size_t			live;
	size_t			id;
	struct s_date	*date;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
}t_philo;

typedef struct s_date
{
	long			number_of_philosophers;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	long			number_of_times_each_philosopher_must_eat;
	long			start;
	t_philo			*philo;
	pthread_t		*threads;
	pthread_mutex_t	*fork;
	pthread_mutex_t	message;

}t_date;

#endif
