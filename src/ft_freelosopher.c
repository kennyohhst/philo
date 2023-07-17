/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freelosopher.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkalika <kkalika@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 21:40:28 by kkalika           #+#    #+#             */
/*   Updated: 2023/07/17 18:39:14 by kkalika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	end_universe(t_god *god)
{

	pthread_mutex_destroy(god->time);
	pthread_mutex_destroy(god->death);
	pthread_mutex_destroy(god->msg);
	free(god->death);
	free(god->time);
	free(god->msg);
	free(god);
}

void	free_bob(t_god *god)
{
	int	i;

	i = 0;
	printf("im here\n");
	while (god->philos[i])
	{
		pthread_mutex_destroy(god->philos[i]->time_bob);
		free(god->philos[i]->time_bob);
		free(god->philos[i]);
		i++;		
	}
}

void		free_list(t_god *god)
{
	t_table	*temp;
	int		i;

	temp = god->table->next;
	i = 0;
	while (i++ < god->philo)
	{
		// pthread_mutex_destroy(god->table->l_fork);
		free(god->table->l_fork);
		free(god->table);
		god->table = temp;
		temp = god->table->next;
	}
	// free(god->table);
}

void	freelosopher(t_god *data)
{
	free_list(data);
	free_bob(data);
	free(data);
	// end_universe(data);
}