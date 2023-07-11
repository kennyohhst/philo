/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_sim.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: code <code@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 18:09:21 by kkalika           #+#    #+#             */
/*   Updated: 2023/07/11 21:52:11 by code             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	grab_fork(t_philo **philo)
{
	int i;
	
	i = pthread_mutex_lock((*philo)->table->l_fork);
	if (i == 0)
	{
		i = pthread_mutex_lock((*philo)->table->next->l_fork);
		if (i == 0)
		{
			// printf("bobs_id: %d\n table_id:	%d\n", (*data)->philos[(*data)->table->id]->bobs_id, (*data)->table->id);
			printf("%d locked by: %d\n", (*philo)->table->id, (*philo)->bobs_id);
			pthread_mutex_unlock((*philo)->table->next->l_fork);
			return (1);
		}
		else
			pthread_mutex_unlock((*philo)->table->l_fork);
	}
	else
	{
		pthread_mutex_unlock((*philo)->table->l_fork);	
		return (0);
	}
	// sleep(1);

	// (*data)->table = (*data)->table->next;

	
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
			write(1, "im here\n", 9);
			printf("bob_%d thinks he is at table_%d\n", temp->bobs_id, temp->table->id);
		}
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
		sleep(1);
		++i;
		
	}
}