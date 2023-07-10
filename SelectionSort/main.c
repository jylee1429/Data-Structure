#include <stdio.h>
#include "SelectionSort.h"

int main(void) {
	int arr[5] = { 100,45,80,99,12 };
	int i;

	SelectionSort(arr, sizeof(arr) / sizeof(int));
	for (i = 0; i < 5; i++)
		printf("%d ", arr[i]);
	return 0;
}