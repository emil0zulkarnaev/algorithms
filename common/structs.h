#ifndef STRUCTS_H
#define STRUCTS_H

#include "fast.h"
#include "binary.h"

class Set {
	std::vector<int> s;
public:
	Set get_union			(Set &set);
	Set get_intersection	(Set &set);
	Set get_difference		(Set &set);
	void add(int value) { if (find(s, value) == -1) { this->s.push_back(value); sort(this->s, true); } }
	int  get(int index) { return this->s[index];  }
	int size()			{ return this->s.size();  }
	bool empty()		{ return this->s.empty(); }
	void clear()		{ this->s.clear(); }
};

#endif
