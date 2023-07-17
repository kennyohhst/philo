/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkalika <kkalika@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 20:28:18 by kkalika           #+#    #+#             */
/*   Updated: 2023/07/17 19:41:02 by kkalika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

// void	set_time(t_philo *bob)
// {
// 	pthread_mutex_lock(bob->god->death);
// 		bob->god->start_time = ft_time();
// 	pthread_mutex_unlock(bob->god->death);
// }

long	ft_time(void)
{
	struct timeval	start;

	gettimeofday(&start, NULL);
	return ((start.tv_sec * 1000) + (start.tv_usec / 1000));
}

