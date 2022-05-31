/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coleta <coleta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 15:01:51 by coleta            #+#    #+#             */
/*   Updated: 2022/05/28 20:53:47 by coleta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

int	main(int argc, char **argv)
{
	t_date	date;

	if (parsing(argc, argv, &date))
		printf("Wrong 1\n");
	if (init(&date))
		clear(&date);
	if (spectator(&date))
		clear(&date);
}
// исправиить АААААААА