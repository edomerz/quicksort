/*
	quicksort
*/
	
#ifndef __QUICKSORT_H__
#define __QUICKSORT_H__

#include <stdio.h>

/* return 1 if data1 < data2; 0 if data1 == data2; -1 data1 > data2; */
typedef int (*compare_func)(const void *data1, const void *data2);

void *QuickSort(void *base,
				size_t num_elements,
				size_t elem_size,
				compare_func);
	
#endif /* ifndef __QUICKSORT_H__*/
