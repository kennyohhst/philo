/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_philos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkalika <kkalika@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 17:10:59 by kkalika           #+#    #+#             */
/*   Updated: 2023/07/08 17:56:47 by kkalika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	add_eating_amount(t_god **temp, char *num)
{
	if (ft_atoi(num) != ft_atoi_l(num))
		exit(write(2, "Errof\n", 6));
	(*temp)->eating_amount = ft_atoi(num);
}

void	add_death(t_god **temp, char *num)
{
	if (ft_atoi(num) != ft_atoi_l(num))
		exit(write(2, "Errof\n", 6));
	(*temp)->die = ft_atoi(num);
}

void	add_sleep(t_god **temp, char *num)
{
	if (ft_atoi(num) != ft_atoi_l(num))
		exit(write(2, "Errof\n", 6));
	(*temp)->sleep = ft_atoi(num);
}

void	add_eat(t_god **temp, char *num)
{
	if (ft_atoi(num) != ft_atoi_l(num))
		exit(write(2, "Errof\n", 6));
	(*temp)->eat = ft_atoi(num);
}

void	add_philos(t_god **temp, char *num)
{
	if (ft_atoi(num) != ft_atoi_l(num))
		exit(write(2, "Errof\n", 6));
	(*temp)->philo = ft_atoi(num);
}
