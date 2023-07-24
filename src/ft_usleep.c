/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkalika <kkalika@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 20:17:00 by kkalika           #+#    #+#             */
/*   Updated: 2023/07/24 19:25:06 by kkalika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	ft_usleep(unsigned long time)
{
	unsigned long	begin;

	begin = ft_time();
	time = time + begin;
	while (ft_time() < time)
		usleep(100);
}
