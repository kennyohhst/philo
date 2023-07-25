/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkalika <kkalika@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 16:15:53 by kkalika           #+#    #+#             */
/*   Updated: 2023/07/25 14:54:08 by kkalika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*life(void *philo)
{
	t_philo	*bob;

	bob = (t_philo *) philo;
	if (bob->god->philo == 1)
		return (bobs_single(bob));
	if (bob->bobs_id % 2)
		ft_usleep(bob->eat);
	pthread_mutex_lock(&bob->god->death);
	bob->last_food = ft_time();
	pthread_mutex_unlock(&bob->god->death);
	while (!ft_stop(bob->god))
	{
		grab_fork(&bob);
		eat_sleep_think(bob);
		if (!ft_stop(bob->god))
			printf_msg(bob->god, "is thinking", bob->bobs_id, ft_time());
	}
	return (NULL);
}
