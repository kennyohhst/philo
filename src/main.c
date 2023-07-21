/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkalika <kkalika@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 17:48:01 by kkalika           #+#    #+#             */
/*   Updated: 2023/07/21 17:04:21 by kkalika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	checkleaks()
{
	system("leaks philo");
}

int	main(int argc, char **argv)
{
	t_god	*data;
	long i;

	i = 0;
	// atexit(checkleaks);
	data = parse(argc, argv);
	data->bobs_blood = false;
	if (!data)
		return (EXIT_FAILURE);
	// printf("%d\n", data->eating_amount);
	init_mutex(data);
	// if (argc == 5)
		start_sim(data);
	pthread_mutex_unlock(data->msg);
	while (i != data->philo)
	{
		pthread_join(data->philos[i]->philo, NULL);
		i++;
	}
	pthread_join(data->check_death, NULL);
	freelosopher(data);
	return (0);
}
