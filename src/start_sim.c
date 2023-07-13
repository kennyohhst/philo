/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_sim.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkalika <kkalika@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 18:09:21 by kkalika           #+#    #+#             */
/*   Updated: 2023/07/13 20:56:56 by kkalika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	grab_fork(t_philo **philo)
{
	// if (!(*philo)->table->grab)
	// {
		pthread_mutex_lock((*philo)->table->l_fork);
		pthread_mutex_lock((*philo)->table->next->l_fork);
		// pthread_mutex_unlock((*philo)->table->l_fork);
		// pthread_mutex_unlock((*philo)->table->l_fork);
	// 	(*philo)->table->grab = true;
	// 	printf("%d has taken a fork\n", (*philo)->bobs_id);
	// 	if (!(*philo)->table->next->grab)
	// 	{
	// 		(*philo)->table->next->grab = true;
	// 		(*philo)->die = ft_time() + (*philo)->die;
	// 		return (1);
	// 	}
	// 	else
	// 	{
	// 		(*philo)->table->grab = false;
	// 	}		
	// }
	// else
	// {
	// 	(*philo)->table->grab = false;
	// 	return (0);
	// }
	return (1);
}

void	let_go(t_philo *philo)
{
	pthread_mutex_unlock(philo->table->l_fork);
	pthread_mutex_unlock(philo->table->next->l_fork);
}
void	eat_sleep_think(t_philo *philo)
{
	printf("%4ldms %d is eating\n", ft_time() - philo->start_time, philo->bobs_id);
	while (ft_time() <= philo->eat)
		;
	philo->eat = ft_time() + philo->eat;
	printf("%d is sleeping\n", philo->bobs_id);
	while (ft_time() <= philo->sleep)
		;
	philo->sleep = ft_time() + philo->sleep;
}


void	*life(void *philo)
{ 
	t_philo *temp;
	temp = (t_philo *) philo;

	temp->start_time = ft_time();
	while (1)
	{
		if (death(temp))
		{
			temp->dead = true;
			return (NULL);
		}
		if (grab_fork(&temp) && !(death(temp)))
		{
			printf("%d has taken a fork\n", temp->bobs_id);
			eat_sleep_think(temp);
			let_go(temp);
		}
		else
			printf("%d is thinking\n", temp->bobs_id);
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