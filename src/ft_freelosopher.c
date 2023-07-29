/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freelosopher.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: code <code@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 21:40:28 by kkalika           #+#    #+#             */
/*   Updated: 2023/07/30 15:27:18 by code             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void	end_universe(t_god *god)
{
	pthread_mutex_destroy(&god->blood_check);
	pthread_mutex_destroy(&god->death);
	pthread_mutex_destroy(&god->msg);
	pthread_mutex_destroy(&god->start);
	free(god);
}

static void	free_bob(t_god *god)
{
	int	i;

	i = 0;
	while (god->philo)
	{
		pthread_mutex_destroy(&god->philos[i]->nomnom);
		free(god->philos[i]);
		i++;
		god->philo--;
	}
}

static void	free_list(t_god *god)
{
	t_table	*temp;
	int		i;

	i = 0;
	if (god->philo == 1)
	{
		free(god->table);
		return ;
	}
	while (i < god->philo)
	{
		pthread_mutex_destroy(&god->table->l_fork);
		temp = god->table;
		god->table = god->table->next;
		free(temp);
		i++;
	}
}

void	freelosopher(t_god *data)
{
	free_list(data);
	free_bob(data);
	end_universe(data);
}
