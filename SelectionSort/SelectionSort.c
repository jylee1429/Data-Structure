#include "SelectionSort.h"
#include <stdio.h>

void SelectionSort(int arr[], int n) {
	int i, j;
	int minindex;
	int temp;

	for (i = 0; i < n - 1; i++) {
		minindex = i;
		for (j = i; j < n; j++) {
			if (arr[j] < arr[minindex]) {
				minindex = j;
			}
		}
		temp = arr[i];
		arr[i] = arr[minindex];
		arr[minindex] = temp;
	}
}