#include <iostream>
#include <stdio.h>
#include <ctime>
#include <cstdlib>
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

void conn_matrix(std::vector<std::vector<int>> &m, int width, bool weight, bool negative) {
	std::srand(std::time(nullptr));

	int min = 0,
		max = 0;

	if (weight) {
		min = negative ? -100 : 0;
		max = 100;
	}
	else
		max = 2;
	
	for (int i=0; i<width; i++) {
		std::vector<int> v;
		for (int j=0; j<width; j++) {
			v.push_back(0);
		}
		m.push_back(v);
	}

	for (int i=0; i<width; i++) {
		for (int j=i; j<width; j++) {
			m[i][j] = std::rand() % (max*(min < 0 ? 2 : 1)) + min;
			if (i != j)
				m[j][i] = std::rand() % (max*(min < 0 ? 2 : 1)) + min;
		}
	}
}

void output_conn_matrix(std::vector<std::vector<int>> &m) {
	int size = m.size();

	std::cout << "  ";
	for (int i=0; i<size; i++)
		printf("%3c ", (char)(i+65));
		//std::cout << (char)(i+65) << " ";

	std::cout << std::endl;

	for (int i=0; i<size; i++) {
		std::cout << (char)(i+65) << " ";
		for (int j=0; j<size; j++) {
			printf("%3d ", m[i][j]);
			//std::cout << m[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

void output_conn_matrix_by_name(std::vector<std::vector<int>> &m) {
	int size = m.size();
	for (int i=0; i<size; i++) {
		std::cout << (char)(i+65) << " -> ";
		for (int j=0; j<size; j++) {
			if (m[i][j] != 0)
				std::cout << (char)(j+65) << " ";
		}
		std::cout << std::endl;
	}
}
