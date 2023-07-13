/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkalika <kkalika@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 20:08:44 by kkalika           #+#    #+#             */
/*   Updated: 2023/07/13 21:01:12 by kkalika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	death(t_philo *philo)
{
	if ((ft_time() - philo->start_time)  > philo->die)
		philo->dead = true;
	return (0);
}