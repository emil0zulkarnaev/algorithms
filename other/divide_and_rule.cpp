#include <stdio.h>
#include <vector>
#include "ioms.h"

// количество элементов в списке 
int count(std::vector<int> &v) {
	std::vector<int> v_new;
	if (v.empty())
		return 0;
	else {
		v_new.assign(v.begin()+1, v.end());
		return 1+count(v_new);
	}

	return 0;
}

// сумма
// (я знаю про существование метода size,
//  но почему бы не использовать метод, реализованный на месте? =D)
int sum(std::vector<int> &v) {
	int size = count(v);
	std::vector<int> v_new;

	if (size == 0)
		return 0;
	else
	if (size == 1)
		return v[0];
	else {
		v_new.assign(v.begin()+1, v.end());
		return v[0] + sum(v_new);
	}
}

// наибольщее число в списке
int max(std::vector<int> &v) {
	int size = count(v);
	std::vector<int> v_new;

	if (size == 0)
		return 0;
	else
	if (size == 1)
		return v[0];
	else {
		v_new.assign(v.begin()+1, v.end());
		int mx = max(v_new);
		return v[0] > mx ? v[0] : mx;
	}
}

int main()
{
	std::vector<int> v;
	input_v_(v);
	printf("Количество: %d\n", count(v));
	printf("Сумма: %d\n", sum(v));
	printf("Наибольшее число: %d\n", max(v));
	return 0;
}
