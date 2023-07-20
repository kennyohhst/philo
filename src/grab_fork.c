/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grab_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkalika <kkalika@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 19:55:46 by kkalika           #+#    #+#             */
/*   Updated: 2023/07/20 21:11:35 by kkalika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

bool	grab_fork_fork(t_table *chair)
{
// if (chair->id == 1)
// printf ("%s[%i] bob_%d\n", __func__, __LINE__, chair->id);
	pthread_mutex_lock(chair->l_fork);
	if (chair->grab)
	{
// if (chair->id == 1)
// printf ("%s[%i] bob_%d\n", __func__, __LINE__, chair->id);
		pthread_mutex_unlock(chair->l_fork);
		return (false);
	}
	// else
	// {
		
// if (chair->id == 1)
// printf ("%s[%i] bob_%d\n", __func__, __LINE__, chair->id);
		chair->grab = true;
		pthread_mutex_unlock(chair->l_fork);
		return (true);
	// }
}
void	drop_fork_fork(t_table *chair)
{
	pthread_mutex_lock(chair->l_fork);
	chair->grab = false;
	pthread_mutex_unlock(chair->l_fork);
}

int	grab_fork(t_philo **philo)
{
	
// if ((*philo)->bobs_id == 1)
// printf ("%s[%i] bob_%d\n", __func__, __LINE__, (*philo)->bobs_id);
	if (ft_stop((*philo)))
		return (0);
	while (!grab_fork_fork((*philo)->table))
		ft_usleep(100, (*philo));
	if (!ft_stop((*philo)))
		printf_msg((*philo)->god, "has taken a fork", (*philo)->bobs_id);

	while (!grab_fork_fork((*philo)->table->next))
		ft_usleep(100, (*philo));

	if (!ft_stop((*philo)))
		printf_msg((*philo)->god, "has taken b fork", (*philo)->bobs_id);
	return (1);
}
