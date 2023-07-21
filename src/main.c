/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkalika <kkalika@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 17:48:01 by kkalika           #+#    #+#             */
/*   Updated: 2023/07/21 20:06:01 by kkalika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	main(int argc, char **argv)
{
	t_god	*data;
	long	i;

	i = 0;
	data = parse(argc, argv);
	data->bobs_blood = false;
	if (!data)
		return (EXIT_FAILURE);
	init_mutex(data);
	start_sim(data);
	while (i != data->philo)
	{
		pthread_join(data->philos[i]->philo, NULL);
		i++;
	}
	pthread_join(data->check_death, NULL);
	freelosopher(data);
	return (0);
}
