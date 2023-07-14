/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkalika <kkalika@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 20:28:18 by kkalika           #+#    #+#             */
/*   Updated: 2023/07/14 22:35:35 by kkalika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	set_time(t_philo *bob)
{
	if (!pthread_mutex_lock(bob->god->time))
		bob->start_time = ft_time();
	pthread_mutex_unlock(bob->god->time);
}

long	ft_time(void)
{
	struct timeval	start;

	gettimeofday(&start, NULL);
	return ((start.tv_sec * 1000000 + start.tv_usec));
}

