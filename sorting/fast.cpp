#include <stdio.h>
#include <vector>
#include "ioms.h"

// "Быстрая сортировка"
void sort(std::vector<int> &v, bool flag) {
	int size = v.size();

	if (size < 2);
	else
	if (size == 2) {
		if (flag && v[0] > v[1] || !flag && v[0] < v[1]) {
			int x = v[0];
			v[0] = v[1];
			v[1] = x;
		}
	}
	else {
		// тут советуют выбирать опорный элемент случайно,
		// но я просто выбираю центральный (или около того)
		int middle = size / 2,
			el     = v[middle];
		std::vector<int> left, right;
		for (int i=0; i<size; i++) {
			if (flag && v[i] < el || !flag && v[i] > el)
				left.push_back(v[i]);
			else
			if (flag && v[i] > el || !flag && v[i] < el)
				right.push_back(v[i]);
		}

		/*
		printf("middle: %d[%d]\n", v[middle], middle);
		printf("left s: %d, right s: %d\n", left.size(), right.size());
		output_v(v);
		output_v(left);
		output_v(right);
		printf("---------\n");
		*/
		sort(left, flag); sort(right, flag);
		
		v.assign(left.begin(), left.end());
		v.insert(v.end(), el);
		v.insert(v.end(), right.begin(), right.end());
	}
}

int main()
{
	std::vector<int> v;
	input_v_(v);

	int sorting_direction = 0;
	printf("Выберите направление сортировки:\n1-по возрастанию\n2-по убыванию\n-> ");
	while (sorting_direction != 1 && sorting_direction != 2)
		scanf("%d", &sorting_direction);

	sort(v, sorting_direction == 1 ? true : false);

	output_v(v);

	return 0;
}
