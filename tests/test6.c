#include <stdio.h>
#include <string.h>
#include "includes/malloc.h"

void test_malloc_sizes()
{
	void *tiny, *small, *large;

	printf("=== Testing malloc with different sizes ===\n");

	// Test TINY allocation
	tiny = malloc(TINY_MAX - sizeof(t_block));
	if (!tiny)
	{
		printf("Failed to allocate TINY size!\n");
		return;
	}
	printf("TINY allocation successful!\n");

	// Test SMALL allocation
	small = malloc(SMALL_MAX - sizeof(t_block));
	if (!small)
	{
		printf("Failed to allocate SMALL size!\n");
		return;
	}
	printf("SMALL allocation successful!\n");

	// Test LARGE allocation
	large = malloc(SMALL_MAX + 10);
	if (!large)
	{
		printf("Failed to allocate LARGE size!\n");
		return;
	}
	printf("LARGE allocation successful!\n");

	free(tiny);
	free(small);
	free(large);
}

// void test_malloc_errors()
// {
// 	void *mem;

// 	printf("=== Testing malloc with error cases ===\n");

// 	mem = malloc(0);
// 	if (mem)
// 	{
// 		printf("Allocated memory with size 0, unexpected behavior!\n");
// 		free(mem);
// 	}
// 	else
// 		printf("Correctly did not allocate memory with size 0.\n");

// 	// Test with extremely large size (likely to fail)
// 	mem = malloc((size_t)-1);
// 	if (mem)
// 	{
// 		printf("Unexpectedly allocated extremely large memory!\n");
// 		free(mem);
// 	}
// 	else
// 	{
// 		printf("Correctly did not allocate extremely large memory.\n");
// 	}
// }

void test_malloc()
{
	char *str;

	printf("=== Testing malloc ===\n");
	str = (char *)malloc(12 * sizeof(char));
	if (!str)
	{
		printf("Malloc failed!\n");
		return;
	}
	strcpy(str, "Hello World");
	printf("String after malloc and strcpy: %s\n", str);
	free(str);
}

void test_realloc_increase_size()
{
	char *str;

	printf("=== Testing realloc with increased size ===\n");
	str = (char *)malloc(12 * sizeof(char));
	if (!str)
	{
		printf("Initial malloc failed!\n");
		return;
	}
	strcpy(str, "Hello");
	printf("Before realloc: %s\n", str);

	str = (char *)realloc(str, 50 * sizeof(char));
	if (!str)
	{
		printf("Realloc failed!\n");
		return;
	}
	strcat(str, " World, expanded string!");
	printf("After realloc and strcat: %s\n", str);
	free(str);
}

void test_realloc_decrease_size()
{
	char *str;

	printf("=== Testing realloc with decreased size ===\n");
	str = (char *)malloc(50 * sizeof(char));
	if (!str)
	{
		printf("Initial malloc failed!\n");
		return;
	}
	strncpy(str, "Hello World, with some additional unnecessary characters.", 50);
	printf("Before realloc: %s\n", str);

	str = (char *)realloc(str, 12);
	if (!str)
	{
		printf("Realloc failed!\n");
		return;
	}
	printf("After realloc: %s\n", str);
	free(str);
}

void test_free()
{
	char *str;

	printf("=== Testing free ===\n");
	str = (char *)malloc(12 * sizeof(char));
	if (!str)
	{
		printf("Malloc failed!\n");
		return;
	}
	strcpy(str, "Hello World");
	printf("Before free: %s\n", str);
	free(str);
	printf("After free (expected garbage or a crash): %s\n", str);
}

void test_show_alloc_mem()
{
	char *str1, *str2, *str3;

	printf("=== Testing show_alloc_mem ===\n");

	str1 = (char *)malloc(10 * sizeof(char));
	str2 = (char *)malloc(20 * sizeof(char));
	str3 = (char *)malloc(30 * sizeof(char));

	if (!str1 || !str2 || !str3)
	{
		printf("Malloc failed for one of the strings!\n");
		return;
	}

	strcpy(str1, "Test1");
	strcpy(str2, "This is Test2");
	strcpy(str3, "This is the longest Test3");

	show_alloc_mem();

	free(str1);
	free(str2);
	free(str3);
}

int main()
{
	char *test = malloc(50);
	test_malloc();
	test_realloc_increase_size();
	test_realloc_decrease_size();
	test_free();
	test_show_alloc_mem();
	test_malloc_sizes();
	// test_malloc_errors();

	return 0;
}
