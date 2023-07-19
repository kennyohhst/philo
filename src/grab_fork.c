/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grab_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkalika <kkalika@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 19:55:46 by kkalika           #+#    #+#             */
/*   Updated: 2023/07/19 16:55:24 by kkalika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

bool	grab_fork_fork(t_table *chair)
{
	pthread_mutex_lock(chair->l_fork);
	if (chair->grab)
	{
		pthread_mutex_unlock(chair->l_fork);
		return (false);
	}
	else
	{
		chair->grab = true;
		pthread_mutex_unlock(chair->l_fork);
		return (true);
	}
}
void	drop_fork_fork(t_table *chair)
{
	pthread_mutex_lock(chair->l_fork);
	chair->grab = false;
	pthread_mutex_unlock(chair->l_fork);
}

int	grab_fork(t_philo **philo)
{
	if (ft_stop((*philo)))
		return (0);
	while (!grab_fork_fork((*philo)->table))
		ft_usleep(100);
	while (!grab_fork_fork((*philo)->table->next))
		ft_usleep(100);
	printf_msg((*philo)->god, "has taken a fork", (*philo)->bobs_id);
	printf_msg((*philo)->god, "has taken a fork", (*philo)->bobs_id);
	if (ft_stop((*philo)))
		return (0);
	if (eat_sleep_think((*philo)))
		return (0);
	// pthread_mutex_unlock((*philo)->table->next->l_fork);
	// pthread_mutex_unlock((*philo)->table->l_fork);
	return (1);
}