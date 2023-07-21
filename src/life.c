/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkalika <kkalika@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 16:15:53 by kkalika           #+#    #+#             */
/*   Updated: 2023/07/21 17:58:43 by kkalika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*life(void *philo)
{
	t_philo	*bob;

	bob = (t_philo *) philo;
	if (bob->god->philo == 1)
		return (bobs_single(bob));
	if (bob->bobs_id % 2)
		ft_usleep(bob->eat / 2);
	while (!ft_stop(bob))
	{
		grab_fork(&bob);
		eat_sleep_think(bob);
		if (!ft_stop(bob))
			printf_msg(bob->god, "is thinking", bob->bobs_id, 0);
	}
	return (NULL);
}
