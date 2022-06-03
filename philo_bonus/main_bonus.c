/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coleta <coleta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 12:47:06 by coleta            #+#    #+#             */
/*   Updated: 2022/06/03 17:55:24 by coleta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo_bonus.h"

int	main(int argc, char **argv)
{
	t_date	date;

	if (parsing(argc, argv, &date))
		return (0);
	if (init(&date))
		clear(&date);
	if (forking(&date))
	{
		wait_fork(&date);
		clear(&date);
	}
}
