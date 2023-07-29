/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: code <code@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 17:48:01 by kkalika           #+#    #+#             */
/*   Updated: 2023/07/29 03:40:10 by code             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	main(int argc, char **argv)
{
	t_god	*data;
	long	i;
	long	err_n;

	i = 0;
	data = parse(argc, argv);
	if (!data)
		return (EXIT_FAILURE);
	err_n = start_sim(data);
	while (i != err_n)
	{
		pthread_join(data->philos[i]->philo, NULL);
		i++;
	}
	data->philo = err_n;
	pthread_join(data->check_death, NULL);
	freelosopher(data);
	return (0);
}
