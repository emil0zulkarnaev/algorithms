#include <iostream>
#include "ioms.h"

void input_v(std::vector<int> &v) {
	int N = 0, number = 0;
	std::cout << "Введите длину (списка): ";
	std::cin >> N;

	for (int i=0; i<N; i++) {
		printf("-> ");
		std::cin >> number;
		v.push_back(number);
	}
}

void input_v_(std::vector<int> &v) {
	std::cout << "Введите список целых чисел: ";
	int value = 0;
	while(std::cin.peek() != 10 && std::cin.peek() != 13) {
		std::cin >> value;
		v.push_back(value);
	}
}

void output_v(std::vector<int> &v) {
	for (int i=0; i<v.size(); i++) {
		std::cout << v[i] << " ";;
	}
	std::cout << std::endl;
}
