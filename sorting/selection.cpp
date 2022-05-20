#include <stdio.h>
#include <vector>
#include "ioms.h"

int mxmn(std::vector<int> &v, bool flag) {
	int mxmn_ = flag ? 0 : 100000000,
		mxmn_ind = 0;

	for (int i=0; i<v.size(); i++) {
		if ((flag && mxmn_ < v[i]) || (!flag && mxmn_ > v[i])) {
			mxmn_ = v[i];
			mxmn_ind = i;
		}
	}

	return mxmn_ind;
}

void selection_sort(std::vector<int> &v, std::vector<int> &result, bool flag) {
	int ln = v.size(),
		ind = 0;
	for (int i=0; i<ln; i++) {
		ind = mxmn(v, !flag);
		result.push_back(v[ind]);
		v.erase(v.begin()+ind);
	}
}

int main()
{
	std::vector<int> v, result;
	input_v(v);
	selection_sort(v, result, false);
	output_v(result);
	return 0;
}
