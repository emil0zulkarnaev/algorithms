#include <stdio.h>
#include <vector>

bool stupid_verification(std::vector<int> &v) {
	bool result = true;
	for (int i=1; i<v.size(); i++) {
		if (v[i] < v[i-1]) {
			result = false;
			break;
		}
	}

	return result;
}

int find(std::vector<int> &v, int value) {
	int start = 0,
		stop  = v.size() - 1,
		middle = 0,
		result = -1;
	
	while (start <= stop) {
		middle = start+(stop-start)/2;

		if (v[middle] == value) {
			result = middle;
			break;
		}
		else if (v[middle] < value)
			start = middle + 1;
		else
			stop  = middle - 1;
	}

	return result;
}

int main()
{
	int N = 0, number = 0;
	std::vector<int> v;

	printf("Введите длину массива: ");
	scanf("%d", &N);
	printf("Введите массив чисел в отсортированном порядке:\n");

	for (int i=0; i<N; i++) {
		printf("-> ");
		scanf("%d", &number);
		v.push_back(number);
	}

	if (!stupid_verification(v)) { printf("Массив не отсортирован!\n"); return 1; }

	printf("Введите искомое значение: ");
	scanf("%d", &number);

	int result = find(v, number);

	if (result == -1) 
		printf("Элемент не найден\n");
	else
		printf("Элемент находится по индексу: %d\n", result);

	return 0;
}
