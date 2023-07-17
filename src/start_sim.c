/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_sim.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkalika <kkalika@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 18:09:21 by kkalika           #+#    #+#             */
/*   Updated: 2023/07/17 20:23:37 by kkalika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	printf_msg(t_god *god, char *str, int i)
{
	pthread_mutex_lock(god->msg);
	printf("%4ldms %d %s\n", ft_time() - god->start_time, god->philos[i]->bobs_id, str);
	pthread_mutex_unlock(god->msg);
}

void	let_go(t_philo *philo)
{
	(void)	philo;
	// sleep(5);
	// pthread_mutex_unlock(philo->table->l_fork);
	// pthread_mutex_unlock(philo->table->next->l_fork);
}
int	eat_sleep_think(t_philo *philo)
{
	if (ft_stop(philo))
		return (1);
	new_time_die(philo);
	printf_msg(philo->god, "is eating", philo->bobs_id);
	ft_usleep(philo->eat);
	drop_fork_fork(philo->table);
	drop_fork_fork(philo->table->next);
	new_time_eat(philo);
	printf_msg(philo->god, "is sleeping", philo->bobs_id);
	ft_usleep(philo->sleep);
	// new_time_sleep(philo);
	return (0);
}

int	ft_stop(t_philo *bob)
{
	pthread_mutex_lock(bob->god->death);
	if (bob->god->bobs_blood)
	{
		printf("hello\n");
		printf_msg(bob->god, " died", bob->bobs_id);
		pthread_mutex_unlock(bob->god->death);
		return (1) ;
	}
	pthread_mutex_unlock(bob->god->death);
	return (0);
}

void	*life(void *philo)
{ 
	t_philo *bob;

	bob = (t_philo *) philo;
	pthread_detach(bob->philo);
	while (1 && !ft_stop(bob))
	{
		if (ft_stop(bob))
			return (NULL);
		if (!grab_fork(&bob))
			return (NULL);
		printf_msg(bob->god, "is thinking", bob->bobs_id);
		if (ft_stop(bob))
			return (NULL);
	}
	return (NULL);
}

void	start_sim(t_god *data)
{
	int	i;

	i = 0;
	data->start_time = ft_time();
	// set_time(data->start_time);
	while (i < data->philo)
	{
		pthread_mutex_init(data->philos[i]->time_bob, NULL);
		pthread_mutex_init(data->philos[i]->table->l_fork, NULL);
		pthread_create(&data->philos[i]->philo, NULL, &life, data->philos[i]);
		++i;
	}
	pthread_create(&data->check_death, NULL, &death, data);

}