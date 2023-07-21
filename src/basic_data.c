/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkalika <kkalika@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 18:41:05 by kkalika           #+#    #+#             */
/*   Updated: 2023/07/21 19:22:52 by kkalika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	basic_data(t_god **temp, int argc, char **argv)
{
	if (add_philos(temp, argv[1]))
		return (add_philos(temp, argv[1]));
	if (add_death(temp, argv[2]))
		return (add_death(temp, argv[2]));
	if (add_eat(temp, argv[3]))
		return (add_eat(temp, argv[3]));
	if (add_sleep(temp, argv[4]))
		return (add_sleep(temp, argv[4]));
	(*temp)->fifth_arg = false;
	if (argc == 6)
	{
		(*temp)->fifth_arg = true;
		if (add_eating_amount(temp, argv[5]))
			return (add_eating_amount(temp, argv[5]));
	}
	return (0);
}
