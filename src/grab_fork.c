/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grab_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkalika <kkalika@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 19:55:46 by kkalika           #+#    #+#             */
/*   Updated: 2023/07/21 19:24:58 by kkalika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

bool	grab_fork_fork(t_table *chair)
{
	pthread_mutex_lock(&chair->l_fork);
	if (chair->grab)
	{
		pthread_mutex_unlock(&chair->l_fork);
		return (false);
	}
	chair->grab = true;
	pthread_mutex_unlock(&chair->l_fork);
	return (true);
}

void	drop_fork_fork(t_table *chair)
{
	pthread_mutex_lock(&chair->l_fork);
	chair->grab = false;
	pthread_mutex_unlock(&chair->l_fork);
}

int	grab_fork(t_philo **philo)
{
	if (ft_stop((*philo)->god))
		return (0);
	while (!grab_fork_fork((*philo)->table))
		ft_usleep(100);
	if (!ft_stop((*philo)->god))
		printf_msg((*philo)->god, "has taken a fork", (*philo)->bobs_id);
	while (!grab_fork_fork((*philo)->table->next) && (*philo)->god->philo > 1)
		ft_usleep(100);
	if (!ft_stop((*philo)->god))
		printf_msg((*philo)->god, "has taken a fork", (*philo)->bobs_id);
	return (1);
}
