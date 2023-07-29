/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_table.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: code <code@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 18:42:12 by kkalika           #+#    #+#             */
/*   Updated: 2023/07/29 02:00:19 by code             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	build_table(t_god **data, int i)
{
	t_table	*new;
	t_table	*temp;

	new = malloc(sizeof(t_table));
	if (!new)
		return (0);
	new->id = i;
	temp = (*data)->table;
	if (temp)
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
		new->next = NULL;
	}
	else
	{
		new->next = NULL;
		(*data)->table = new;
	}
	return (1);
}
