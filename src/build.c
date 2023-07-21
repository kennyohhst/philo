/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkalika <kkalika@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 15:54:31 by kkalika           #+#    #+#             */
/*   Updated: 2023/07/21 15:34:45 by kkalika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	check_args(int argc, char **argv)
{
	int	x;

	x = 1;
	if (argc != 5 && argc != 6)
		return (0);
	while (x < argc)
	{
		if (!ft_numcheck(argv[x]))
			return (0);
		x++;
	}
	return (1);
}
