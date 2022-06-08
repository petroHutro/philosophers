/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coleta <coleta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 15:01:51 by coleta            #+#    #+#             */
/*   Updated: 2022/06/08 17:46:34 by coleta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

int	main(int argc, char **argv)
{
	t_date	date;

	if (parsing(argc, argv, &date))
		return (0);
	if (init(&date))
		return (clear(&date));
	if (spectator(&date))
		return (clear(&date));
}
