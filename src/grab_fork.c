/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grab_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: code <code@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 19:55:46 by kkalika           #+#    #+#             */
/*   Updated: 2023/07/30 15:27:59 by code             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	grab_fork(t_philo **philo)
{
	pthread_mutex_lock(&(*philo)->table->l_fork);
	printf_msg((*philo)->god, "has taken a fork", (*philo)->bobs_id, ft_time());
	pthread_mutex_lock(&(*philo)->table->next->l_fork);
	printf_msg((*philo)->god, "has taken a fork", (*philo)->bobs_id, ft_time());
}
