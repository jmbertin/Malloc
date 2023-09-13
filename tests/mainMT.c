#include <stdio.h>
#include <pthread.h>
#include "includes/malloc.h"
#include <stdint.h>

void *thread_routine(void *arg)
{
	char *str;

	for (int i = 0; i < 10000; i++)
	{
		str = (char *) malloc(30 * sizeof(char));
		if (str)
		{
			snprintf(str, 30, "Thread %ld Iteration %d", (intptr_t)arg, i);
			printf("%s\n", str);
			free(str);
		}
	}
	return NULL;
}

int main()
{
	const int NUM_THREADS = 10;
	pthread_t threads[NUM_THREADS];

	for (int i = 0; i < NUM_THREADS; i++)
	{
		pthread_create(&threads[i], NULL, thread_routine, (void *)(long)i);
	}

	for (int i = 0; i < NUM_THREADS; i++)
	{
		pthread_join(threads[i], NULL);
	}

	return 0;
}
