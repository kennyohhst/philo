/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_sim.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkalika <kkalika@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 18:09:21 by kkalika           #+#    #+#             */
/*   Updated: 2023/07/11 20:29:16 by kkalika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	grab_fork(t_god **data)
{
	int i;
	
	i = pthread_mutex_lock((*data)->philos[(*data)->table->id]->table->l_fork);
	if (i == 0)
	{
		i = pthread_mutex_lock((*data)->philos[(*data)->table->id]->table->next->l_fork);
		if (i == 0)
		{
			printf("bobs_id: %d\n table_id:	%d\n",
			(*data)->philos[(*data)->table->id]->bobs_id, (*data)->table->id);
			pthread_mutex_unlock((*data)->philos[(*data)->table->id]->table->next->l_fork);
			return (1);
		}
		else
			pthread_mutex_unlock((*data)->philos[(*data)->table->id]->table->l_fork);
	}
	else
	{
		pthread_mutex_unlock((*data)->philos[(*data)->table->id]->table->l_fork);
		return (0);
	}
	// sleep(1);


	
	return (1);
}

void	eat(t_god **data)
{
	(void) data;
	write(1, "eetuhhh\n", 9);
}

void	*life(void *data)
{ 
	t_god *temp;

	temp = (t_god *) data;
	while (1)
	{
		if(grab_fork(&temp))
		{
			write(1, "im here\n", 9);
			eat(&temp);
			// sleep(&temp);
		}
		temp->table = temp->table->next;
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
		pthread_create(&data->philos[i]->philo, NULL, &life, data);
		sleep(1);
		++i;
	}
}