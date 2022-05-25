#include <iostream>
#include <math.h>
#include <algorithm>
#include "ioms.h"

#define name(c) (char)(c+65)

int inf = (int)INFINITY;

int lowest_cost(
	std::vector<int> &costs,
	std::vector<int> &viewed) {

	int result = -1,
		min    = (int)INFINITY;
	//std::cout << "not viewed: ";
	for (int i=0; i<costs.size(); i++) {
		if (std::find(viewed.begin(), viewed.end(), i) == viewed.end()) {
			if (min > costs[i]) {
				min = costs[i];
				result = i;
			}
		}
	}
	return result;
}

int find(
	std::vector<std::vector<int>> &m,
	std::vector<std::vector<int>> &w,
	char start_char,
	char stop_char) {
	
	std::vector<int> costs(m.size(), inf);
	std::vector<int> viewed;
	std::vector<int> way;
	std::vector<int> parents(m.size(), inf);
	
	int start = (int)start_char - 65,
		stop  = (int)stop_char  - 65,
		parent = start,
		current = start,
		sm = 0;

	for (int i=0; i<m.size(); i++)
		if (m[start][i] == 1) {
			costs[i] = w[start][i];
			parents[i] = start;
		}

	viewed.push_back(current);

	while (current != stop && viewed.size() < m.size()) {
		parent = current;
		current = lowest_cost(costs, viewed);

		if (current == -1)
			break;
		
		for (int i=0; i<m.size(); i++) {
			if (m[current][i] == 1) {
				sm = costs[current] + w[current][i];
				if (sm < costs[i]) {
					costs[i] = costs[current] + w[current][i];
					parents[i] = current;
				}
			}
		}
		
		viewed.push_back(current);
	}

	// сборка пути
	if (costs[stop] != inf) {
		current = stop;
		way.push_back(current);
		while (current != start) {
			current = parents[current];
			way.push_back(current);
		}

		std::cout << "Путь: ";
		for (int i=way.size()-1; i >= 0; i--)
			std::cout << name(way[i]) << (i == 0 ? "" : " -> ");
		std::cout << std::endl;
	}	

	return costs[stop];
}

int main()
{
	std::vector<std::vector<int>> matrix, weights;

	int points_count = 0;
	std::cout << "Введите количество пунктов: ";
	std::cin  >> points_count;

	conn_matrix(matrix, weights, points_count, true, false);
	output_conn_matrix(matrix);
	std::cout << "--------------------\n";
	output_conn_matrix(weights);
	std::cout << "--------------------\n";
	output_conn_matrix_by_name(matrix);

	char start, stop;
	std::cout << "\nВведите начальный пункт: ";
	std::cin  >> start;
	std::cout << "Введите конечный пункт: ";
	std::cin  >> stop;

	int result = find(matrix, weights, start, stop);
	if (result != inf)
		std::cout << "Стоимость проезда: " << result << std::endl;
	else
		std::cout << "Никак не проехать, звиняй\n";

	return 0;
}
