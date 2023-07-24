/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkalika <kkalika@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 18:43:38 by kkalika           #+#    #+#             */
/*   Updated: 2023/07/24 20:25:16 by kkalika          ###   ########.fr       */
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
	bob->die = (*temp)->die;
	bob->sleep = (*temp)->sleep;
	bob->eat = (*temp)->eat;
	bob->eating_amount = (*temp)->eating_amount;
	bob->table = (*temp)->table;
	return (bob);
}
