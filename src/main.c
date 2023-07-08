/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkalika <kkalika@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 17:48:01 by kkalika           #+#    #+#             */
/*   Updated: 2023/07/08 17:48:05 by kkalika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	test(t_god **temp, int argc)
{
	printf("philos\t\t\t:	%d\n", (*temp)->philo);
	printf("death time\t\t:	%d\n", (*temp)->die);
	printf("sleep time\t\t:	%d\n", (*temp)->sleep);
	printf("eating time\t\t:	%d\n", (*temp)->eat);
	if (argc == 6)
		printf("eating amount\t\t:	%d\n", (*temp)->eating_amount);
}




int	main(int argc, char **argv)
{
	// int	result;
	t_god	*data;


	data = parse(argc, argv);
	test(&data, argc);
	



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