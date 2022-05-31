/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coleta <coleta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 12:47:06 by coleta            #+#    #+#             */
/*   Updated: 2022/05/31 19:05:46 by coleta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	clear(t_date *date)
{
	int	rez;
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (1)
	{
		waitpid(-1, &rez, 0);
		rez = rez >> 8;
		if (rez == 4)
			break;
		if (rez == 5)
			n++;
		if (n == date->number_of_philosophers)
		{
			printf("EXIT\n");
			break;
		}
	}
	printf("CLEAR START\n");
	while (i < date->number_of_philosophers)
	{
		date->philo[i].live = 0;
		kill(date->philo[i].pid, 9);
		i++;
	}
	printf("CLEAR\n");
	exit(1);
}

int	main(int argc, char **argv)
{
	t_date	date;

	if (parsing(argc, argv, &date))
		printf("WRONG\n");
	if (init(&date))
		printf("Wrong\n");
	forking(&date);
	clear(&date);
}
