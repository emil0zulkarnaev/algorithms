#include <stdio.h>
#include "ioms.h"

void input_v(std::vector<int> &v) {
	int N = 0, number = 0;
	printf("Введите длину (списка): ");
	scanf("%d", &N);

	for (int i=0; i<N; i++) {
		printf("-> ");
		scanf("%d", &number);
		v.push_back(number);
	}
}

void output_v(std::vector<int> &v) {
	for (int i=0; i<v.size(); i++) {
		printf("%d ", v[i]);
	}
	printf("\n");
}
