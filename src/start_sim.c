/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_sim.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkalika <kkalika@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 18:09:21 by kkalika           #+#    #+#             */
/*   Updated: 2023/07/21 15:09:18 by kkalika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	printf_msg(t_god *god, char *str, int i, long stamp)
{
	pthread_mutex_lock(god->msg);
	
	if (!ft_strncmp(str, " died", 5))
		printf("%ld %d %s\n", stamp, god->philos[i]->bobs_id, str);
	else
		printf("%ld %d %s\n", ft_time() - god->start_time, god->philos[i]->bobs_id, str);
	
	// 	return ;
	pthread_mutex_unlock(god->msg);

}


int	eat_sleep_think(t_philo *philo)
{
	if (!ft_stop(philo))
	{
		new_time_die(philo);
		new_time_eat(philo);
		printf_msg(philo->god, "is eating", philo->bobs_id, 0);
		ft_usleep(philo->eat, philo);
	}
	drop_fork_fork(philo->table);
	drop_fork_fork(philo->table->next);
	if (!ft_stop(philo))
	{
		printf_msg(philo->god, "is sleeping", philo->bobs_id, 0);
		ft_usleep(philo->sleep, philo);	
	}
	return (0);
}



int	ft_stop(t_philo *bob)
{
	pthread_mutex_lock(bob->god->death);
	if (bob->stop && !bob->god->bobs_blood)
	{
		printf_msg(bob->god, " died", bob->bobs_id, bob->god->death_stamp);
		bob->god->bobs_blood = true;
		pthread_mutex_unlock(bob->god->death);
		pthread_mutex_unlock(bob->god->msg);
		return (1) ;
	}
	else if (bob->god->bobs_blood)
	{
		pthread_mutex_unlock(bob->god->death);
		return (1);
	}
	pthread_mutex_unlock(bob->god->death);
	return (0);
}

void	*life(void *philo)
{ 
	t_philo *bob;

	bob = (t_philo *) philo;
	if (bob->bobs_id % 2)
		ft_usleep(bob->eat / 2, bob);
	while (!ft_stop(bob))
	{
		grab_fork(&bob);
		eat_sleep_think(bob);
		if (!ft_stop(bob))
			printf_msg(bob->god, "is thinking", bob->bobs_id, 0);
	}
printf("bob %i is fucking done with it!\n", bob->bobs_id);
	// pthread_mutex_unlock(bob->god->msg);
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
		// pthread_mutex_init(data->philos[i]->time_bob, NULL);
		pthread_mutex_init(data->philos[i]->table->l_fork, NULL);
		pthread_create(&data->philos[i]->philo, NULL, &life, data->philos[i]);
		++i;
	}
	pthread_create(&data->check_death, NULL, &death, data);

	pthread_detach(data->check_death);

}
// printf ("%s[%i] bob_%d\n", __func__, __LINE__, bob->bobs_id);
// if (bob->bobs_id == 1)
// printf ("%s[%i] bob_%d\n", __func__, __LINE__, bob->bobs_id);