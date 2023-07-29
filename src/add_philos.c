/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_philos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: code <code@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 17:10:59 by kkalika           #+#    #+#             */
/*   Updated: 2023/07/29 04:11:16 by code             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

/**
 * This function adds two integers and returns the result.
 *
 * @param a GOD STRUCT
 * @param b INPUT AS STRING
 * @return 0 IF GOOD, 7 IF BAD
 */
int	add_eating_amount(t_god **temp, char *num)
{
	if (ft_atoi(num) != ft_atoi_l(num) || ft_atoi(num) <= 0)
		return (7);
	(*temp)->eating_amount = ft_atoi(num);
	return (0);
}

/**
 * This function adds two integers and returns the result.
 *
 * @param a GOD STRUCT
 * @param b INPUT AS STRING
 * @return 0 IF GOOD, 4 IF BAD
 */
int	add_death(t_god **temp, char *num)
{
	if (ft_atoi(num) != ft_atoi_l(num) || ft_atoi(num) <= 0)
		return (4);
	(*temp)->die = ft_atoi(num);
	return (0);
}

/**
 * This function adds two integers and returns the result.
 *
 * @param a GOD STRUCT
 * @param b INPUT AS STRING
 * @return 0 IF GOOD, 6 IF BAD
 */
int	add_sleep(t_god **temp, char *num)
{
	if (ft_atoi(num) != ft_atoi_l(num) || ft_atoi(num) <= 0)
		return (6);
	(*temp)->sleep = ft_atoi(num);
	return (0);
}

/**
 * This function adds two integers and returns the result.
 *
 * @param **temp GOD STRUCT
 * @param *num INPUT AS STRING
 * @return int 0 IF GOOD, 5 IF BAD
 */
int	add_eat(t_god **temp, char *num)
{
	if (ft_atoi(num) != ft_atoi_l(num) || ft_atoi(num) <= 0)
		return (5);
	(*temp)->eat = ft_atoi(num);
	return (0);
}

/**
 * This function adds two integers and returns the result.
 *
 * @param a GOD STRUCT
 * @param b INPUT AS STRING
 * @return 0 IF GOOD, 4 OR 3 IF BAD
 */
int	add_philos(t_god **temp, char *num)
{
	if (ft_atoi(num) != ft_atoi_l(num) || ft_atoi(num) <= 0)
		return (4);
	(*temp)->philo = ft_atoi(num);
	if ((*temp)->philo <= 0)
		return (3);
	return (0);
}
