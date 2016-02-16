#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <assert.h>

#include "quicksort.h"

static void Swap(void *address1, void *address2, size_t element_size, void *tmp);
static char *Partition(char* start, char *end, size_t elem_size, compare_func fp);

void *QuickSort(void *base, size_t num_elements, size_t elem_size, compare_func fp)
{
	char *end = (char*)base + ((num_elements - 1) * elem_size);
	char *start = (char*)base;
	if(start < end)
	{
		char *q = Partition(start, end, elem_size, fp);
		
		/*if(q != start)
		{*/
			QuickSort(start,
					  (size_t)((q - start) / elem_size),
						elem_size,
						fp);
		/*}*/

		/*if(q != end)
		{*/
			QuickSort((void*)(q + elem_size) ,
					  (size_t)((end  - q)  / elem_size),
					  elem_size,
					  fp);
		/*}*/
	}
	return(base);
}

static char *Partition(char* start, char *end, size_t elem_size, compare_func fp)
{
	char *j = start;
	char *i = start - elem_size;
	void *tmp = malloc(elem_size);
	assert(tmp);

	for( ; j < end; j += elem_size)
	{
		printf("before j: %d\n", *(int*)j);
		printf("before i: %d\n", *(int*)i);
		printf("before end: %d\n", *(int*)(end));

		if(fp(j, end))
		{
			i += elem_size;
			Swap(i, j, elem_size, tmp);
		}
		printf("after j: %d\n", *(int*)j);
		printf("after i: %d\n", *(int*)i);
		printf("after end: %d\n", *(int*)(end));
	}
	Swap(i + elem_size, end, elem_size, tmp);
	printf("new end: %d\n", *(int*)(end));
	printf("after i: %d\n", *(int*)i);
	printf(" return: %d\n", *(int*)(i + elem_size));

	free(tmp);
	return(i + elem_size);
}

static void Swap(void *address1, void *address2, size_t element_size, void *tmp)
{
	memmove(tmp, address1, element_size);
	memmove(address1, address2, element_size);
	memmove(address2, tmp, element_size);
}
