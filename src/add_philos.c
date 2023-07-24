/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_philos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkalika <kkalika@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 17:10:59 by kkalika           #+#    #+#             */
/*   Updated: 2023/07/24 19:40:15 by kkalika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	add_eating_amount(t_god **temp, char *num)
{
	if (ft_atoi(num) != ft_atoi_l(num) || ft_atoi(num) <= 0)
		return (7);
	(*temp)->eating_amount = ft_atoi(num);
	return (0);
}

int	add_death(t_god **temp, char *num)
{
	if (ft_atoi(num) != ft_atoi_l(num) || ft_atoi(num) <= 0)
		return (4);
	(*temp)->die = ft_atoi(num);
	return (0);
}

int	add_sleep(t_god **temp, char *num)
{
	if (ft_atoi(num) != ft_atoi_l(num) || ft_atoi(num) <= 0)
		return (6);
	(*temp)->sleep = ft_atoi(num);
	return (0);
}

int	add_eat(t_god **temp, char *num)
{
	if (ft_atoi(num) != ft_atoi_l(num) || ft_atoi(num) <= 0)
		return (5);
	(*temp)->eat = ft_atoi(num);
	return (0);
}

int	add_philos(t_god **temp, char *num)
{
	if (ft_atoi(num) != ft_atoi_l(num) || ft_atoi(num) <= 0)
		return (4);
	(*temp)->philo = ft_atoi(num);
	if ((*temp)->philo > 200 || (*temp)->philo <= 0)
		return (3);
	return (0);
}
