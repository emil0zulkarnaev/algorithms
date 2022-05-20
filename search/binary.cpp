#include <stdio.h>
#include <vector> 
#include "ioms.h"

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

// простое решение
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

// "элегантное решение" при помощи "разделяй и властвуй"
int pretty_find(std::vector<int> &v, int value) {
	int size   = v.size(),
		middle = size/2;

	if (v[middle] == value)
		return middle;
	else {
		int multiplier = 1;
		std::vector<int> v_new;

		if (v[middle] < value) {
			v_new.assign(v.begin()+middle+1, v.end());
		}
		else {
			v_new.assign(v.begin(), v.end()-middle);
			multiplier = -1;
		}

		return (multiplier > 0 ? middle + 1 : 0) + pretty_find(v_new, value);
	}
}

int main()
{
	int number = 0;
	std::vector<int> v;

	input_v_(v);

	if (!stupid_verification(v)) { printf("Массив не отсортирован!\n"); return 1; }

	printf("Введите искомое значение: ");
	scanf("%d", &number);

	int result = find(v, number);

	if (result == -1) 
		printf("Элемент не найден\n");
	else
		printf("Элемент находится по индексу: %d\n", result);

	result = pretty_find(v, number);
	if (result == -1) 
		printf("Элемент не найден (pretty_find)\n");
	else
		printf("Элемент находится по индексу (pretty_find): %d\n", result);
	printf("Это конечно было очевидно, но я же должен был выполнить эту функцию\n");

	return 0;
}
