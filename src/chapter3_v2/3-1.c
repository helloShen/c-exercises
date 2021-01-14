/* binary search */

#include <stdio.h>

// declaration
int binarySearch(int x, int v[], int size);
void find(int x, int v[], int size);
void printArray(int v[], int size);

int main() {
	int v[] = {4, 11, 14, 20, 22, 44, 48, 55, 100, 230};
	int size = sizeof(v) / sizeof(v[0]);
	//printf("size = %d\n", size);
	printArray(v, size);

	int target1 = 22;
	find(target1, v, size);	

	int target2 = 33;
	find(target2, v, size);	
}

// call binarySearch() and print the result
void find(int x, int v[], int size) {
	int find = binarySearch(x, v, size);
	if (find == -1) {
		printf("%d NOT found!\n", x);
	} else {
		printf("find %d at @%d\n", x, find);
	}
}

// print array
void printArray(int v[], int size) {
	for (int i = 0; i < size; i++) {
		printf("%d",v[i]);
		if (i < size - 1) {
			printf(", ");
		} else {
			printf("\n");
		}
	}
}

// search x in array v[], size is the length of array v[]
int binarySearch(int x, int v[], int size) {
	int lo = 0, hi = size - 1;
	while (lo <= hi) {
		//printf("lo = %d, hi = %d\n", lo, hi);
		int mid = (hi - lo + 1) / 2 + lo;
		//printf("check position %d = %d\n", mid, v[mid]);
		if (v[mid] == x) {
			return mid;
		} else {
			if (v[mid] < x) {
				lo = mid + 1;
			} else {
				hi = mid - 1;
			}
		}
	}
	return -1;
}
