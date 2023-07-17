/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_round.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkalika <kkalika@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 18:44:46 by kkalika           #+#    #+#             */
/*   Updated: 2023/07/17 18:45:03 by kkalika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	make_round(t_god *data)
{
	t_table	*temp;
	int		i;

	i = 0;
	temp = data->table;
	while (temp->next && data->philos[i])
	{
		data->philos[i]->table = temp;
		temp = temp->next;
		i++;
	}
	data->philos[i]->table = temp;
	temp->next = data->table;
	data->table->prev = temp;
	return (1);
}

