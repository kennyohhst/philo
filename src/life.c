/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: code <code@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 16:15:53 by kkalika           #+#    #+#             */
/*   Updated: 2023/07/30 15:24:42 by code             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*life(void *philo)
{
	t_philo	*bob;

	bob = (t_philo *) philo;
	if (bob->god->philo == 1)
		return (bobs_single(bob), NULL);
	pthread_mutex_lock(&bob->god->start);
	pthread_mutex_unlock(&bob->god->start);
	if (bob->bobs_id % 2)
		ft_usleep(bob->eat / 2);
	pthread_mutex_lock(&bob->god->death);
	bob->last_food = ft_time();
	pthread_mutex_unlock(&bob->god->death);
	while (!ft_stop(bob->god))
	{
		grab_fork(&bob);
		eat_sleep_think(bob);
	}
	return (NULL);
}
