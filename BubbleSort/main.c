#include <stdio.h>
#include "BubbleSort.h"

int main(void) {
	int arr[10] = { 70,15,26,87,21,31,44,48,96,102 };
	int i;

	BubbleSort(arr, sizeof(arr)/sizeof(int));
	for (i = 0; i < 10; i++) {
		printf("%d ", arr[i]);
	}
	return 0;

}