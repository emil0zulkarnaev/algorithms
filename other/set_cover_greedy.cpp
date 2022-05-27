#include <stdio.h>
#include <vector>
#include "structs.h"

// Реализация ЖАДНОГО алгоритма в задаче
//			ПОКРЫТИЯ МНОЖЕСТВА

#define sA(s) (char)(s+65)
#define sa(s) (char)(s+97)

void find_objects_set(
	Set not_cover,
	std::vector<Set> &objects,
	Set &result
		) {
	while (!not_cover.empty()) {
		int len = 0, i = 0;
		Set remainder, for_optimum_search;
		int best = -1;
		for (i=0; i<objects.size(); i++) {
			remainder = not_cover.get_intersection(objects[i]);
			//printf("remainder size: %d\n", remainder.size());
			if (remainder.size() > for_optimum_search.size()) {
				best = i;
				for_optimum_search = remainder;
			}
		}
		result.add(best);
		not_cover = not_cover.get_difference(for_optimum_search);
		//printf("not_cover: %d\n", not_cover.size());
		//printf("result size: %d\n", result.size());
	}
}

int main()
{
	// общее множество
	Set common; // элементы представляют собой латинские символы от a до z
	common.add((int)'m');
	common.add((int)'w');
	common.add((int)'o');
	common.add((int)'i');
	common.add((int)'n');
	common.add((int)'u');
	common.add((int)'c');
	common.add((int)'a');

	// объекты, покрывающие некоторые элементы общего множества (подмножества)
	//		представляют собой латинские символы от A до Z
	std::vector<Set> objects;
	Set object;
	object.add((int)'i');
	object.add((int)'n');
	object.add((int)'u');
	objects.emplace_back(object); // n
	object.clear();
	object.add((int)'w');
	object.add((int)'i');
	object.add((int)'m');
	objects.emplace_back(object); // w
	object.clear();
	object.add((int)'o');
	object.add((int)'n');
	object.add((int)'c');
	objects.emplace_back(object); // h
	object.clear();
	object.add((int)'n');
	object.add((int)'u');
	objects.emplace_back(object); // o
	object.clear();
	object.add((int)'c');
	object.add((int)'a');
	objects.emplace_back(object); // i

	char stations[] = {'n', 'w', 'h', 'o', 'i'};

	// множество объектов, объединение подмножество которых как set равняется общему множеству
	//		(покрывает всё общее множестов)
	Set result;
	find_objects_set(common, objects, result);

	for (int i=0; i<result.size(); i++) {
		printf("%c ", stations[result.get(i)]);
	}
	printf("\n");

	return 0;
}
