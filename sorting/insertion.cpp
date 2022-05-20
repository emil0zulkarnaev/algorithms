#include <stdio.h>

#define LEN 6

int ms[LEN] = {0};

void input() {
	printf("Enter an array\n");
	for (int i = 0; i < LEN; i++) {
		printf("%d: ", i+1);
		scanf("%d", &ms[i]);
	}
}

void output() {
	for (int i = 0; i < LEN; i++) {
		printf("%d ", ms[i]);
	}
	printf("\n");
}

void insertion_sort(bool direction) {
	for (int j=1; j<LEN; j++) {
		int key = ms[j];
		int i = j-1;
		while (i >= 0 && (ms[i] > key && direction || ms[i] < key && !direction) ) {
			ms[i+1] = ms[i];
			i--;
		}
		ms[i+1] = key;
	}
}

int main()
{
	input();
	output();
	insertion_sort(false);
	output();
	return 0;
}
