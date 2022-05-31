/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_philo_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coleta <coleta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 12:48:31 by coleta            #+#    #+#             */
/*   Updated: 2022/05/30 20:21:29 by coleta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_PHILO_H
# define S_PHILO_H

# include <stdlib.h>
# include <pthread.h>
# include <semaphore.h>
# include <sys/time.h>
# include <unistd.h>
# include <signal.h>

typedef struct s_philo
{
	long			last_eat;
	size_t			live;
	size_t			id;
	struct s_date	*date;
	pid_t			pid;
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
	sem_t			*fork;
	sem_t			*message;
	sem_t			*take_fork;

}t_date;

#endif
