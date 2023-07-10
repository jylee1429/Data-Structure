#include "InsertionSort.h"
#include <stdio.h>

void InsertionSort(int arr[], int n) {
	int i, j;
	int insertdata;

	for (i = 1; i < n; i++) {
		insertdata = arr[i];
		for (j = i-1; j >= 0; j--) {
			if (arr[j] > insertdata)
				arr[j + 1] = arr[j];
			else
				break;
		}
		arr[j + 1] = insertdata;
	}
}