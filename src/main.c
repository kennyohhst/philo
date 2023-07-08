#include "../include/philo.h"
#include <pthread.h>

void	*pthread_function(void	*args)
{
	printf("result is here: \n%s\n", (char *)args);
	pthread_exit(NULL);	
}


int	main(void)
{
	int	result;
	pthread_t	thread;
	printf("before create\n");
	
	result = pthread_create(&thread, NULL, pthread_function, (void*)&"banaan");
	printf("after create\n");
	
	if (!result)
	{
		printf("during result check 1\n");
		// return (0);
	}
	printf("after result check 1\n");
	// usleep(100);
	printf("before join\n");
	
	result = pthread_join(thread, NULL);
	printf("after thread_join\n");
	if (!result)
	{
		printf("during result check 2\n");
		return (0);
	}
		printf("this should not happen\n");
	return (0);
}
