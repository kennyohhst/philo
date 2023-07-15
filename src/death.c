/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkalika <kkalika@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 20:08:44 by kkalika           #+#    #+#             */
/*   Updated: 2023/07/15 16:20:56 by kkalika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	new_time_eat(t_philo *bob)
{
	if (!pthread_mutex_lock(bob->god->time))
		bob->eat = bob->eat + ft_time();
	pthread_mutex_unlock(bob->god->time);
}

void	new_time_sleep(t_philo *bob)
{
	if (!pthread_mutex_lock(bob->god->time))
		bob->sleep = bob->sleep + ft_time();
	pthread_mutex_unlock(bob->god->time);
}

void	new_time_die(t_philo *bob)
{
	if (!pthread_mutex_lock(bob->god->time))
		bob->die = bob->die + ft_time();
	pthread_mutex_unlock(bob->god->time);
}
int	check_death(t_philo *bob)
{
	if (pthread_mutex_lock(bob->god->death))
	{
		if ((ft_time() - bob->start_time) > bob->die)
		{
			printf("bob_%d welcome, you have %d sec left to live\n", bob->bobs_id, (ft_time() - bob->start_time) > bob->die);
			printf_msg(bob->god, "deded", bob->bobs_id);
			bob->god->bobs_blood = true;
			pthread_mutex_unlock(bob->god->death);
			return (1);	
		}
	}
	pthread_mutex_unlock(bob->god->time);
	return (0);
}
			// pthread_mutex_lock(bob->god->msg);

void	*death(void *god)
{
	t_god	*temp;
	int	i;

	i = 0;
	
	temp = (t_god *) god;
	
	while (i != temp->philo)
	{
		if (check_death(temp->philos[i]))
			return (NULL);
		i++;
		if (i == (temp->philo))
			i = 0;
	}
	// {
	// 	i++;
	// 	if (temp->philo == i)
	// 		i = 0;
	// }
	return (NULL);
}
