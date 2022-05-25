#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <iterator>
#include "ioms.h"

void get_neighbours(
		std::vector<std::vector<int>> &m,
		std::vector<int> &viewed,
		std::queue<int> &queue,
		int point,
		std::vector<int> &d,
		std::vector<std::vector<int>> &ways) {
	int size = m.size();
	for (int j=0; j<size; j++) {
		if (m[point][j] != 0 && (
			viewed.size() == 0 ||
			std::find(viewed.begin(), viewed.end(), j) == viewed.end())) {
			viewed.push_back(j);
			queue.push(j);
			d[j] = d[point] + 1;
			
			// сделал по приколу
			ways[j].assign(ways[point].begin(), ways[point].end());
			ways[j].push_back(j);
		}
	}
}

int find(
		std::vector<std::vector<int>> &m,
		char start_char,
		char stop_char)
{
	std::vector<int> viewed;
	std::queue<int> queue;
	std::vector<int> d(m.size(), 0);

	std::vector<std::vector<int>> ways;
	for (int i=0; i<m.size(); i++)
		ways.emplace_back(std::vector<int>());

	int start = (int)start_char-65,
		stop  = (int)stop_char-65,
		current = 0;

	viewed.push_back(start);
	ways[start].push_back(start);
	get_neighbours(m, viewed, queue, start, d, ways);

	while (!queue.empty()) {
		current = queue.front();
		queue.pop();

		if (current == stop) {
			break;
		}
		else 
			get_neighbours(m, viewed, queue, current, d, ways);
	}

	std::cout << std::endl;
	if (d[stop]) {
		int size = ways[stop].size() - 1;
		std::cout << "Путь: ";
		for (int i=0; i <= size; i++)
			std::cout << (char)(ways[stop][i]+65) << (i == size ? "" : " -> ");
		std::cout << std::endl;
	}
	
	return d[stop];
}

int main()
{
	std::vector<std::vector<int>> matrix, weights;

	int points_count = 0;
	std::cout << "Введите количество пунктов: ";
	std::cin  >> points_count;

	conn_matrix(matrix, weights, points_count, false, false);
	output_conn_matrix(matrix);
	std::cout << "--------------------\n";
	output_conn_matrix_by_name(matrix);

	char start, stop;
	std::cout << "\nВведите начальный пункт: ";
	std::cin  >> start;
	std::cout << "Введите конечный пункт: ";
	std::cin  >> stop;

	int result = find(matrix, start, stop);
	std::cout << "Путь из " << start << " в " << stop << (result ? " ЕСТЬ" : " НЕ СУЩЕСТВУЕТ");
	if (result)
		std::cout << " (" << result << ")\n";
	else
		std::cout << std::endl;

	return 0;
}
