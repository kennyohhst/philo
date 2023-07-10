/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkalika <kkalika@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 17:48:01 by kkalika           #+#    #+#             */
/*   Updated: 2023/07/10 23:13:22 by kkalika          ###   ########.fr       */
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




int	main(int argc, char **argv)
{
	// int	result;
	t_god	*data;
	int i;

	i = 0;

	data = parse(argc, argv);
	start_sim(data);

	// pthread_create(&data->philos[0]->philo, NULL, &func, data->philos[0]);
	// pthread_create(&data->philos[1]->philo, NULL, &func, data->philos[1]);
	// pthread_create(&data->philos[2]->philo, NULL, &func, data->philos[2]);

	// pthread_join(data->philos[0]->philo, NULL);
	// test(&data, argc);
	



	// pthread_t	thread_a;
	// pthread_t	thread_b;
	// pthread_t	thread_c;
	// pthread_t	thread_d;
	// printf("before create\n");
	
	// result = pthread_create(&thread_a, NULL, pthread_function, (void*)&"banaan");
	// result = pthread_create(&thread_b, NULL, pthread_function, (void*)&"hi");
	// result = pthread_create(&thread_c, NULL, pthread_function, (void*)&"here");
	// result = pthread_create(&thread_d, NULL, pthread_function, (void*)&"yes");
	// printf("after create\n");
	
	// if (!result)
	// {
	// 	printf("during result check 1\n");
	// 	// return (0);
	// }
	// printf("after result check 1\n");
	// // usleep(100);
	// printf("before join\n");
	
	// result = pthread_join(thread_a, NULL);
	// printf("after thread_join\n");
	// if (!result)
	// {
	// 	printf("during result check 2\n");
	// 	return (0);
	// }
	// 	printf("this should not happen\n");
	return (0);
}

// void	*pthread_function(void	*args)
// {
// 	pthread_mutex_t	mutex;

// 	pthread_mutex_init(&mutex, NULL);
// 	static int i = 0;

// 	pthread_mutex_lock(&mutex);
// 	printf("eating\n%s	%d\n", (char *)args, i++);
// 	pthread_exit(NULL);	
// 	pthread_mutex_unlock(&mutex);
// 	pthread_mutex_destroy(&mutex);
// }