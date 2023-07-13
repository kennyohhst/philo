/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkalika <kkalika@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 17:48:01 by kkalika           #+#    #+#             */
/*   Updated: 2023/07/13 21:03:59 by kkalika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	test(t_god **temp, int argc)
{
	// TEST GOD_STRUCT:
	// printf("philos\t\t\t:	%d\n", (*temp)->philo);
	// printf("death time\t\t:	%d\n", (*temp)->die);
	// printf("sleep time\t\t:	%d\n", (*temp)->sleep);
	// printf("eating time\t\t:	%d\n", (*temp)->eat);
	// if (argc == 6)
	// 	printf("eating amount\t\t:	%d\n", (*temp)->eating_amount);

	// TEST TABLE STRUCT:

	// TEST BOB:
	int	i = 0;
	while (i != (*temp)->philo)
	{
		printf("bob_%i:	 eat:%d\t", i, (*temp)->philos[i]->eat);
		printf("sleep:%d\t", (*temp)->philos[i]->sleep);
		printf("die:%d", (*temp)->philos[i]->die);
		if (argc == 6)
			printf("\teating_amount:%d\n", (*temp)->philos[i]->eating_amount);
		else
			printf("\n");
		i++;
	}
}

void	checkleaks()
{
	system("leaks philo");
}
long	ft_time(void)
{
	struct timeval	start;

	gettimeofday(&start, NULL);
	return ((start.tv_sec * 1000000 + start.tv_usec));
}

int	main(int argc, char **argv)
{
	// int	result;
	t_god	*data;
	int i;

	i = 0;
	// atexit(checkleaks);
	data = parse(argc, argv);
	if (!data)
		return (EXIT_FAILURE);
	// while (ft_time() <= data->philos[0]->sleep)	
	// 	printf("time: %ld\nsleep:	%d\neat:	%d\n", ft_time(), data->philos[0]->sleep, data->philos[0]->eat);	
	start_sim(data);
	while (1)
	{
		if (data->philos[i]->dead)
		{
			printf("%d has died\n", data->philos[i]->bobs_id);
			break ;
		}
		i++;
		if (data->philo == i)
			i = 0;
	}
	free(data);
	return (0);
}
