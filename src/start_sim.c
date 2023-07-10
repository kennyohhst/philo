/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_sim.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkalika <kkalika@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 18:09:21 by kkalika           #+#    #+#             */
/*   Updated: 2023/07/10 23:14:55 by kkalika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	grab_fork(t_philo **bob)
{
	(void) bob;
	return (0);
}

void	eat(t_philo **bob)
{
	(void) bob;
	write(1, "eetuhhh\n", 9);
}

void	*life(void *philo)
{ 
	t_philo *temp;

	temp = (t_philo *) philo;
	while (1)
	{
		if(grab_fork(&temp))
		{
			eat(&temp);
			// sleep(&temp);
		}
		// else
			// thinking(&temp);	
		// died(&temp);
	}

	return (NULL);
}

void	start_sim(t_god *data)
{
	int	i;

	i = 0;
	while (i != data->philo)
	{
		pthread_create(&data->philos[i]->philo, NULL, &life, data->philos[i]);
		++i;
	}
}