#include <stdio.h>
#include <stdlib.h>
#include "InsertionSort.h"

int main(void) {
	int i;
	int arr[7];

	printf("arr : ");
	for (i = 0; i < 7; i++) {
		arr[i] = rand() % 100;
		printf("%d ", arr[i]);
	}
	printf("\n");

	InsertionSort(arr, sizeof(arr) / sizeof(int));
	
	printf("sort arr : ");
	for (i = 0; i < 7; i++) {
		printf("%d ", arr[i]);
	}

	return 0;
}