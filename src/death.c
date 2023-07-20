/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkalika <kkalika@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 20:08:44 by kkalika           #+#    #+#             */
/*   Updated: 2023/07/20 21:26:34 by kkalika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	new_time_eat(t_philo *bob)
{
	pthread_mutex_lock(bob->god->death);
	// printf("hi\n");
		bob->last_food = ft_time();
		// printf("die: %ld\neat: %ld\nsleep: %ld\n", bob->die, bob->eat, bob->sleep);
	pthread_mutex_unlock(bob->god->death);
}

void	new_time_sleep(t_philo *bob)
{
	pthread_mutex_lock(bob->god->death);
		// bob->god->start_time = ft_time();
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
	int	i;
	pthread_mutex_lock(bob->god->death);
	// printf("bob_%d welcome, you have %d sec left to live\n", bob->bobs_id, (ft_time() - bob->last_food) > bob->die);
	// printf("bob_%d	death:	%ld	current:	%ld last_meal:	%ld\n", bob->bobs_id, bob->die, ft_time(), bob->last_food);
	if (bob->last_food && (ft_time() - bob->last_food) > (bob->die / 1000))
	{
		i = bob->god->philo;
		printf("\t%ld %d has died\n", (ft_time() - bob->god->start_time), bob->bobs_id);

		while (i > 0)
		{
			printf("%i\n", i);
			bob->god->philos[i]->stop = true;
			printf("%i\t[%i]\n", i, i > 0);
			i--;
		}
		printf("%ld %d has died\n", (ft_time() - bob->god->start_time), bob->bobs_id);
		
		// bob->stop = true;
		bob->god->bobs_blood = false;
// printf("\t%ld - %s[%i] bob_%d\n", (ft_time() - bob->god->start_time), __func__, __LINE__, bob->bobs_id);
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
