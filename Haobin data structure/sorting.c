#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

#define bool char
#define true 1
#define false 0

/*sorting*/

void Print(int *, int);
void BubbleSorting(int *, int);
void SelectSorting(int *, int);
void QuickSorting(int *, int,int);
int Find(int *, int, int);

int main() {
	

	int arr[7] = { 1, 2, 4, 0, 5, 10, 3 };
	BubbleSorting(arr,7);
	Print(arr, 7);
	printf("\n");

	int arr_1[8] = { 1, 2, 4, 0, 5, 10, 3,11 };
	SelectSorting(arr_1, 8);
	Print(arr_1,8);
	printf("\n");

	int arr_2[9] = { 23,5,2,6,-8,4,3,7,22};
	QuickSorting(arr_2, 0,8);
	Print(arr_2, 9);
	
	return 0;
}

void BubbleSorting(int *arr, int n ) {
	int temp;
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n-i-1; j++) {
			if (arr[j] > arr[j + 1]) {
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}


}

void SelectSorting(int * arr, int n) {
	int min_index;
	int temp;
	for (int i = 0; i < n-1; i++) {
		min_index = i;
		for (int j = i + 1; j < n; j++) {
			if (arr[min_index] > arr[j]) {
				min_index = j;
			}
		}
		temp = arr[i];
		arr[i] = arr[min_index];
		arr[min_index] = temp;
	}

}

void QuickSorting(int * arr, int l , int r ) {

	int pivot;

	if (l < r) {
		pivot = Find(arr, l, r);
		QuickSorting(arr, l, pivot - 1);
		QuickSorting(arr, pivot + 1, r);
	}

}


int Find(int *arr, int l, int r) {

	int val = arr[l];
	while (l < r) {
		while (l<r && arr[r]>=val) {
			r--;
		}
		arr[l] = arr[r];

		while (l < r && arr[l] <= val) {
			l++;
		} 
		arr[r] = arr[l];
	}// the termination condition is l =r;
	arr[l] = val;

	return l; 
}


void Print(int * arr, int n ) {
	for (int i = 0; i < n; i++) {
		printf("%d\t", arr[i]);
	}
	
}
