/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_sim.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkalika <kkalika@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 18:09:21 by kkalika           #+#    #+#             */
/*   Updated: 2023/07/12 16:58:50 by kkalika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	grab_fork(t_philo **philo)
{
	pthread_mutex_lock((*philo)->table->l_fork);

	pthread_mutex_lock((*philo)->table->next->l_fork);
	printf("bob_%d is eating\n", (*philo)->bobs_id);
	// sleep(1);
	pthread_mutex_unlock((*philo)->table->next->l_fork);

	pthread_mutex_unlock((*philo)->table->l_fork);
	printf("bob_%d done eating\n", (*philo)->bobs_id);
	return (1);
}

void	eat(t_god **data)
{
	(void) data;
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
			printf("bob_%d is inside statement with: %d\n", temp->bobs_id, temp->table->id);
		}
		printf("bob_%d is sleeping: %d\n", temp->bobs_id, temp->table->id);
		// sleep(5);

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
		// sleep(1);
		++i;
		
	}
}