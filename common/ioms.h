#include <vector>

void input_v(std::vector<int> &v);
void input_v_(std::vector<int> &v);
void output_v(std::vector<int> &v);
void conn_matrix(
	std::vector<std::vector<int>> &m,
	std::vector<std::vector<int>> &weights,
	int width, bool weight, bool negative);
void output_conn_matrix(std::vector<std::vector<int>> &m);
void output_conn_matrix_by_name(std::vector<std::vector<int>> &m);
