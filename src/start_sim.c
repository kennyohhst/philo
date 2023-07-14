/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_sim.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkalika <kkalika@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 18:09:21 by kkalika           #+#    #+#             */
/*   Updated: 2023/07/14 23:17:02 by kkalika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	printf_msg(t_god *god, char *str, int i)
{
	if (pthread_mutex_lock(god->msg))
	{
		printf("%4ldms %d %s\n", ft_time() - god->philos[i]->start_time, god->philos[i]->bobs_id, str);
		pthread_mutex_unlock(god->msg);
	}
}
int	grab_fork(t_philo **philo)
{
		if (!pthread_mutex_lock((*philo)->table->l_fork))
		{
			printf_msg((*philo)->god, "has taken a fork", (*philo)->bobs_id);
			if (!pthread_mutex_lock((*philo)->table->next->l_fork))
			{
				printf_msg((*philo)->god, "has taken a fork", (*philo)->bobs_id);
				eat_sleep_think((*philo));
			}
		}
	return (1);
}

void	let_go(t_philo *philo)
{
	// sleep(5);
	pthread_mutex_unlock(philo->table->l_fork);
	pthread_mutex_unlock(philo->table->next->l_fork);
}
void	eat_sleep_think(t_philo *philo)
{
	printf_msg(philo->god, "is eating", philo->bobs_id);
	new_time_die(philo);
	usleep(philo->eat);
	new_time_eat(philo);
	let_go(philo);
	printf_msg(philo->god, "is sleeping", philo->bobs_id);
	usleep(philo->sleep);
	new_time_sleep(philo);
	// printf("%4ldms %d is sleeping\n", ft_time() - philo->start_time, philo->bobs_id);
}

int	ft_stop(t_philo *temp)
{
	if (pthread_mutex_lock(temp->god->death))
	{
		if (temp->god->bobs_blood)
		{
			printf_msg(temp->god, " died", temp->bobs_id);
			pthread_mutex_unlock(temp->god->death);
			return (1) ;
		}
		pthread_mutex_unlock(temp->god->death);
	}
	return (0);
}


void	data_race_check(t_philo *bob)
{
	if (pthread_mutex_lock(bob->god->time))
	{
		printf("bob_%d\n", bob->bobs_id);
		pthread_mutex_unlock(bob->god->time);
	}	
}




void	*life(void *philo)
{ 
	t_philo *bob;

	bob = (t_philo *) philo;

	// while (1)
	// 	data_race_check(bob);
	set_time(bob);
	while (1)
	{
		if (ft_stop(bob))
		{
			break ;
		}
		grab_fork(&bob);
		printf_msg(bob->god, "is thinking", bob->bobs_id);
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
	pthread_create(&data->check_death, NULL, &death, data);
}