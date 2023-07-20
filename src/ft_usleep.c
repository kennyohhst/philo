/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkalika <kkalika@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 20:17:00 by kkalika           #+#    #+#             */
/*   Updated: 2023/07/20 19:32:58 by kkalika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	ft_usleep(long time, t_philo *bob)
{
	long begin;
	(void) bob;

	begin = ft_time();
	time = time / 1000;
	while ((ft_time() - begin) < time)
	{
		// printf("som: %ld\ntime:	%ld\n", (ft_time() - begin), time);
		usleep(50);
	}
}