/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: code <code@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 18:51:55 by kkalika           #+#    #+#             */
/*   Updated: 2023/07/30 15:24:47 by code             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

t_god	*parse(int argc, char **argv)
{
	t_god	*temp;
	int		i;

	i = 0;
	temp = malloc(sizeof(t_god));
	if (!temp)
		return (err_exit(0, NULL), NULL);
	temp->table = NULL;
	if (!check_args(argc, argv))
		return (err_exit(1, temp), NULL);
	if (basic_data(&temp, argc, argv))
		return (err_exit(basic_data(&temp, argc, argv), temp), NULL);
	while (i != temp->philo)
	{
		temp->philos[i] = build_philos(&temp);
		if (!temp->philos[i])
			return (err_exit(8, temp), NULL);
		temp->philos[i]->bobs_id = i;
		if (!build_table(&temp, i))
			return (err_exit(9, temp), NULL);
		i++;
	}
	if (!make_round(temp))
		return (err_exit(10, temp), NULL);
	return (temp);
}
