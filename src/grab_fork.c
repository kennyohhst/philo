/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grab_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkalika <kkalika@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 19:55:46 by kkalika           #+#    #+#             */
/*   Updated: 2023/07/23 16:46:40 by kkalika          ###   ########.fr       */
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

// int	grab_fork(t_philo **philo)
// {
// 	if (ft_stop((*philo)->god))
// 		return (0);
// 	pthread_mutex_lock(&(*philo)->table->l_fork);
// 	printf_msg((*philo)->god, "has taken a fork", (*philo)->bobs_id);
// 	if (!ft_stop((*philo)->god))
// 	{
// 		pthread_mutex_unlock(&(*philo)->table->l_fork);
// 		return (0);
// 	}
// 	pthread_mutex_lock(&(*philo)->table->next->l_fork);
// 	printf_msg((*philo)->god, "has taken a fork", (*philo)->bobs_id);
// 	if (!ft_stop((*philo)->god))
// 	{
// 		pthread_mutex_unlock(&(*philo)->table->l_fork);
// 		return (0);
// 	}
	
// 	// while (!grab_fork_fork((*philo)->table))
// 	// 	ft_usleep(100);
	
	
	
	
// 	// while (!grab_fork_fork((*philo)->table->next) && (*philo)->god->philo > 1)
// 		// ft_usleep(100);
// 	// if (!ft_stop((*philo)->god))


// 	return (1);

// }
int	grab_fork(t_philo **philo)
{
	if (ft_stop((*philo)->god))
		return (0);
	while (!grab_fork_fork((*philo)->table))
		;
	if (!ft_stop((*philo)->god))
		printf_msg((*philo)->god, "has taken a fork", (*philo)->bobs_id, ft_time());
	while (!grab_fork_fork((*philo)->table->next) && (*philo)->god->philo > 1)
		;
	if (!ft_stop((*philo)->god))
		printf_msg((*philo)->god, "has taken a fork", (*philo)->bobs_id, ft_time());
	return (1);
}
