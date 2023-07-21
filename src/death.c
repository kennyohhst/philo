/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkalika <kkalika@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 20:08:44 by kkalika           #+#    #+#             */
/*   Updated: 2023/07/21 18:09:40 by kkalika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	new_time_eat(t_philo *bob)
{
	pthread_mutex_lock(bob->god->death);
	bob->last_food = ft_time();
	pthread_mutex_unlock(bob->god->death);
}

bool	nomnom(t_god *data)
{
	int	i;

	i = 0;
	while (i != data->philo)
	{
		pthread_mutex_lock(&data->philos[i]->nomnom);
		if (data->philos[i]->eating_amount > 0)
		{
			pthread_mutex_unlock(&data->philos[i]->nomnom);
			return (false);
		}
		pthread_mutex_unlock(&data->philos[i]->nomnom);
		i++;
	}
	pthread_mutex_lock(data->death);
	data->bobs_blood = true;
	pthread_mutex_unlock(data->death);
	return (true);
}

int	check_death(t_philo *bob, t_god *data)
{
	pthread_mutex_lock(bob->god->death);
	if (bob->last_food && (ft_time() - bob->last_food) > (bob->die / 1000))
	{
		bob->god->bobs_blood = true;
		data->death_stamp = ft_time() - data->start_time;
		printf_msg(bob->god, "died", bob->bobs_id, bob->god->death_stamp);
		pthread_mutex_unlock(bob->god->death);
		return (1);
	}
	pthread_mutex_unlock(bob->god->death);
	return (0);
	// int	i;

	// pthread_mutex_lock(bob->god->death);
	// if (bob->last_food && (ft_time() - bob->last_food) > (bob->die / 1000))
	// {
	// 	i = 0;
	// 	data->death_stamp = ft_time() - data->start_time;
	// 	printf_msg(bob->god, "died", bob->bobs_id, bob->god->death_stamp);
	// 	while (i != data->philo)
	// 	{
	// 		data->philos[i]->stop = true;
	// 		i++;
	// 	}
	// 	bob->god->bobs_blood = false;
	// 	pthread_mutex_unlock(bob->god->death);
	// 	return (1);
	// }
	// pthread_mutex_unlock(bob->god->death);
	// return (0);
}

void	*death(void *god)
{
	t_god	*data;
	int		i;

	data = (t_god *) god;
	if (data->philo == 1)
		return (NULL);
	while (1)
	{
		i = 0;
		while (i != data->philo)
		{
			if (check_death(data->philos[i], data))
				return (NULL);
			i++;
		}
		if (data->fifth_arg && nomnom(data))
			return (NULL);
	}
	return (NULL);
}
