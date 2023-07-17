/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkalika <kkalika@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 20:08:44 by kkalika           #+#    #+#             */
/*   Updated: 2023/07/17 20:44:47 by kkalika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	new_time_eat(t_philo *bob)
{
	pthread_mutex_lock(bob->god->death);
		bob->last_food = ft_time();
		// printf("die: %ld\neat: %ld\nsleep: %ld\n", bob->die, bob->eat, bob->sleep);
	pthread_mutex_unlock(bob->god->death);
}

void	new_time_sleep(t_philo *bob)
{
	pthread_mutex_lock(bob->god->death);
		// bob->start_time = ft_time();
	pthread_mutex_unlock(bob->god->death);
}

void	new_time_die(t_philo *bob)
{
	pthread_mutex_lock(bob->god->death);
	// bob->start_time = ft_time();
	// printf("start: %ld\n die: %ld\n", (bob->start_time / 1000), (bob->die / 1000));
	pthread_mutex_unlock(bob->god->death);
}
int	check_death(t_philo *bob)
{
	pthread_mutex_lock(bob->god->death);
	// printf("bob_%d welcome, you have %d sec left to live\n", bob->bobs_id, (ft_time() - bob->start_time) > bob->die);
	if ((ft_time() - bob->last_food) > (bob->die / 1000))
	{
		// printf("sum: %ld\n eat %ld\n", (ft_time() - bob->god->start_time), bob->eat);
		bob->god->bobs_blood = true;
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
		if (check_death(temp->philos[i]))
			return (NULL);
		i++;
		if (i == (temp->philo))
			i = 0;
	}
	return (NULL);
}
