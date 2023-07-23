/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkalika <kkalika@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 20:08:44 by kkalika           #+#    #+#             */
/*   Updated: 2023/07/23 16:46:19 by kkalika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	new_time_eat(t_philo *bob)
{
	pthread_mutex_lock(&bob->god->death);
	bob->last_food = ft_time();
	pthread_mutex_unlock(&bob->god->death);
}

bool	nomnom(t_god *data)
{
	int	i;

	i = 0;
	while (i != data->philo)
	{
		pthread_mutex_lock(&data->philos[i]->nomnom);
		if (data->philos[i]->eating_amount > 0)
		{
			pthread_mutex_unlock(&data->philos[i]->nomnom);
			return (false);
		}
		pthread_mutex_unlock(&data->philos[i]->nomnom);
		i++;
	}
	pthread_mutex_lock(&data->blood_check);
	data->bobs_blood = true;
	pthread_mutex_unlock(&data->blood_check);
	return (true);
}

int	check_death(t_philo *bob, t_god *data)
{
	pthread_mutex_lock(&data->death);
	if (bob->last_food && (ft_time() - bob->last_food) > (unsigned long) (bob->die / 1000))
	{
		pthread_mutex_lock(&data->blood_check);
		data->bobs_blood = true;
		pthread_mutex_unlock(&data->blood_check);
		pthread_mutex_unlock(&data->death);
// printf("ft_time()		 - 		last_food_time = \n%ld	-	%ld = %ld\n", ft_time(), bob->last_food, (ft_time() - bob->last_food));
		printf_msg(data, "died", bob->bobs_id, ft_time());
		return (1);
	}
	bob->last_food = ft_time();
	pthread_mutex_unlock(&data->death);
	return (0);
}

void	*death(void *god)
{
	t_god	*data;
	int		i;

	data = (t_god *) god;
	if (data->philo == 1)
		return (NULL);
	while (1)
	{
		i = 0;
		while (i != data->philo)
		{
			if (check_death(data->philos[i], data))
				return (NULL);
			i++;
		}
		if (data->fifth_arg && nomnom(data))
			return (NULL);
	}
	return (NULL);
}
