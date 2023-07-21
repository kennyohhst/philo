/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkalika <kkalika@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 20:08:44 by kkalika           #+#    #+#             */
/*   Updated: 2023/07/21 15:08:51 by kkalika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	new_time_eat(t_philo *bob)
{
	pthread_mutex_lock(bob->god->death);
		bob->last_food = ft_time();
	pthread_mutex_unlock(bob->god->death);
}

void	new_time_sleep(t_philo *bob)
{
	pthread_mutex_lock(bob->god->death);
	pthread_mutex_unlock(bob->god->death);
}

void	new_time_die(t_philo *bob)
{
	pthread_mutex_lock(bob->god->death);

	pthread_mutex_unlock(bob->god->death);
}
int	check_death(t_philo *bob, t_god *data)
{
	pthread_mutex_lock(bob->god->death);
	if (bob->last_food && (ft_time() - bob->last_food) > (bob->die / 1000))
	{
		int	i;
		i = 0;
		// printf("%ld %d has died\n", (ft_time() - bob->god->start_time), bob->bobs_id);
		data->death_stamp = ft_time() - data->start_time;
		while (i != data->philo)
		{
			// printf("%i\n", i);
			// printf("%i\t[%i]\n", i, i > 0);
			data->philos[i]->stop = true;
			i++;
		}
		// printf("%ld %d has died\n", (ft_time() - bob->god->start_time), bob->bobs_id);
		
		bob->god->bobs_blood = false;
		pthread_mutex_unlock(bob->god->death);
		return (1);
	}
	pthread_mutex_unlock(bob->god->death);
	return (0);
}

void	*death(void *god)
{
	t_god	*temp;
	int	i;

	i = 0;
	temp = (t_god *) god;
	// pthread_detach(temp->check_death);
	while (i != temp->philo)
	{
		if (check_death(temp->philos[i], temp))
		{
printf("death is fucking done with it!\n");

			return (NULL);
		}
		i++;
		if (i == (temp->philo))
			i = 0;
	}
	return (NULL);
}
