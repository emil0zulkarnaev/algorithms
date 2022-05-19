#include <stdio.h>
#include <vector>

/* Задача
 Даны два n-значных двоичных числа, записанных в виде n-элементных
 массивов A и B. Требуется поместить их сумму (в двоичной записи) 
 в (n+1)-элементный массив C.
 */

int from_binary(std::vector<int> &v) {
	int result = 0,
		degree = 1;
	for (int i = 0; i <= v.size(); i++) {
		degree *= i > 0 ? 2 : 1;
		result += v[i]*degree;
	}

	return result;
}

bool input(std::vector<int> &v, int N, char name) {
	printf("Введите число %c в двоичном виде по разрядам: \n", name);
	int number = 0;
	bool flag = true;
	for (int i = 0; i<N; i++) {
		printf("%d: ", i);
		scanf("%d", &number);
		if (number > 1) { flag = false; break; }
		v.push_back(number);
	}

	return flag;
}

void output(std::vector<int> &v, char name) {
	printf("Двоичное представление %c: ", name);
	for (int i = v.size()-1; i >=0 ; i--) {
		printf("%d", v[i]);
	}
	printf("\nДесятичное представление %c: %d\n\n", name, from_binary(v));
}

void sum(std::vector<int> &A, std::vector<int> &B, std::vector<int> &C) {
	int memory = 0, sm = 0;
	for (int i=0; i<A.size(); i++) {
		sm = A[i] + B[i];
		if (sm > 1) {
			C.push_back(memory);
			memory = 1;
		} else {
			sm += memory;
			if (sm > 1) {
				memory = 1;
				C.push_back(0);
			} else {
				C.push_back(sm);
				memory = 0;
			}
		}
	}
	C.push_back(memory);
}

int main() {
	int N = 0;
	printf("Введите N (количество разрядов): ");
	scanf("%d", &N);

	std::vector<int> A, B, C;

	if (!input(A, N, 'A')) { printf("Не верное значение разряда\n"); return 0; }
	output(A, 'A');
	if (!input(B, N, 'B')) { printf("Не верное значение разряда\n"); return 0; }
	output(B, 'B');

	sum(A, B, C);

	printf("Сумма:\n");
	output(C, 'C');

	return 0;
}
