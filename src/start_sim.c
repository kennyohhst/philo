/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_sim.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: code <code@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 18:09:21 by kkalika           #+#    #+#             */
/*   Updated: 2023/07/30 15:25:15 by code             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	printf_msg(t_god *god, char *str, int i, unsigned long c_t)
{
	pthread_mutex_lock(&god->msg);
	if (ft_stop(god))
	{
		if (!ft_strncmp(str, "died", 4))
			printf("%ld %d %s\n", ft_time() - god->start_time,
				god->philos[i]->bobs_id, str);
		pthread_mutex_unlock(&god->msg);
		return ;
	}
	printf("%ld %d %s\n", c_t - god->start_time,
		god->philos[i]->bobs_id, str);
	pthread_mutex_unlock(&god->msg);
}

void	eat_sleep_think(t_philo *philo)
{
	new_time_eat(philo);
	printf_msg(philo->god, "is eating", philo->bobs_id, ft_time());
	ft_usleep(philo->eat);
	pthread_mutex_unlock(&philo->table->l_fork);
	pthread_mutex_unlock(&philo->table->next->l_fork);
	pthread_mutex_lock(&philo->nomnom);
	philo->eating_amount--;
	pthread_mutex_unlock(&philo->nomnom);
	printf_msg(philo->god, "is sleeping", philo->bobs_id, ft_time());
	ft_usleep(philo->sleep);
	printf_msg(philo->god, "is thinking", philo->bobs_id, ft_time());
	
}

int	ft_stop(t_god *data)
{
	int	i;

	pthread_mutex_lock(&data->blood_check);
	i = data->bobs_blood;
	pthread_mutex_unlock(&data->blood_check);
	return (i);
}

void	bobs_single(t_philo *bob)
{
	pthread_mutex_lock(&bob->table->l_fork);
	printf("0 0 has taken a fork\n");
	usleep(bob->die);
	printf("%ld 0 has died\n", bob->die);
}

long	start_sim(t_god *data)
{
	long	i;

	i = 0;
	data->start_time = ft_time();
	pthread_mutex_lock(&data->start);
	while (i < data->philo)
	{
		pthread_mutex_init(&data->philos[i]->nomnom, NULL);
		pthread_mutex_init(&data->philos[i]->table->l_fork, NULL);
		if(pthread_create(&data->philos[i]->philo, NULL, &life, data->philos[i]))
			return (protect_create(data), i);
		++i;
	}
	pthread_mutex_unlock(&data->start);
	usleep(20);
	if (pthread_create(&data->check_death, NULL, &death, data))
		return (protect_create(data), i);
	return (i);
}
