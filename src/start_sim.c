/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_sim.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkalika <kkalika@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 18:09:21 by kkalika           #+#    #+#             */
/*   Updated: 2023/07/21 18:16:45 by kkalika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	printf_msg(t_god *god, char *str, int i, long stamp)
{
	pthread_mutex_lock(god->msg);
	(void) stamp;
	if (!ft_strncmp(str, "died", 5))
		printf("%ld %d %s\n", ft_time() - god->start_time, god->philos[i]->bobs_id, str);
	else
		printf("%ld %d %s\n", ft_time() - god->start_time,
			god->philos[i]->bobs_id, str);
	pthread_mutex_unlock(god->msg);
}

int	eat_sleep_think(t_philo *philo)
{
	if (!ft_stop(philo))
	{
		new_time_eat(philo);
		printf_msg(philo->god, "is eating", philo->bobs_id, 0);
		pthread_mutex_lock(&philo->nomnom);
		philo->eating_amount--;
		pthread_mutex_unlock(&philo->nomnom);
		
		ft_usleep(philo->eat);
	}
	drop_fork_fork(philo->table);
	drop_fork_fork(philo->table->next);
	if (!ft_stop(philo))
	{
		printf_msg(philo->god, "is sleeping", philo->bobs_id, 0);
		ft_usleep(philo->sleep);
	}
	return (0);
}

int	ft_stop(t_philo *bob)
{



	
	pthread_mutex_lock(bob->god->death);

	if (bob->god->bobs_blood)
	{
		pthread_mutex_unlock(bob->god->death);
		return (1);
	}
	pthread_mutex_unlock(bob->god->death);
	return (0);
	// pthread_mutex_lock(bob->god->death);
	// if (bob->stop && !bob->god->bobs_blood)
	// {
	// 	bob->god->bobs_blood = true;
	// 	pthread_mutex_unlock(bob->god->death);
	// 	pthread_mutex_unlock(bob->god->msg);
	// 	return (1);
	// }
	// else if (bob->god->bobs_blood)
	// {
	// 	pthread_mutex_unlock(bob->god->death);
	// 	return (1);
	// }
	// pthread_mutex_unlock(bob->god->death);
	// return (0);
}

void	*bobs_single(t_philo *bob)
{
	printf("0 0 has taken a fork\n");
	usleep(bob->die);
	printf("%ld 0 has died\n", bob->die / 1000);
	return (NULL);
}

void	start_sim(t_god *data)
{
	int	i;

	i = 0;
	data->start_time = ft_time();
	while (i < data->philo)
	{
		pthread_mutex_init(&data->philos[i]->nomnom, NULL);
		pthread_mutex_init(data->philos[i]->table->l_fork, NULL);
		pthread_create(&data->philos[i]->philo, NULL, &life, data->philos[i]);
		++i;
	}
	pthread_create(&data->check_death, NULL, &death, data);
}
