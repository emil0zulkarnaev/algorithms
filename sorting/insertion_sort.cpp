#include <stdio.h>

#define LEN 5

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

void sort() {
	for (int j=1; j<LEN; j++) {
		int key = ms[j];
		int i = j-1;
		while (i >= 0 && ms[i] > key) {
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
	sort();
	output();
	return 0;
}
