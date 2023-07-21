/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkalika <kkalika@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 18:43:38 by kkalika           #+#    #+#             */
/*   Updated: 2023/07/21 17:45:48 by kkalika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

t_philo	*build_philos(t_god **temp)
{
	t_philo	*bob;

	bob = malloc(sizeof(t_philo));
	if (!bob)
		return (NULL);
	bob->god = (*temp);
	bob->bobs_id = 0;
	bob->die = (*temp)->die * 1000;
	bob->sleep = (*temp)->sleep * 1000;
	bob->eat = (*temp)->eat * 1000;
	bob->eating_amount = (*temp)->eating_amount;
	bob->table = (*temp)->table;
	// bob->stop = false;
	return (bob);
}
