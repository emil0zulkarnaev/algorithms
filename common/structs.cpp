#include <stdio.h>
#include "structs.h"

Set Set::get_union(Set &set) {
	Set result;

	for (int i=0; i<this->s.size(); i++)
		result.add(this->s[i]);
	for (int i=0; i<set.s.size(); i++)
		result.add(set.s[i]);

	return result;
}

Set Set::get_intersection(Set &set) {
	Set result;

	for (int i=0; i<this->s.size(); i++)
		if (find(set.s, this->s[i]) != -1)
			result.s.push_back(this->s[i]);
	
	return result;
}

Set Set::get_difference(Set &set) {
	Set result;

	for (int i=0; i<this->s.size(); i++)
		if (find(set.s, this->s[i]) == -1)
			result.s.push_back(this->s[i]);
	
	return result;
}
