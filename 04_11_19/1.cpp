#include <iostream>
#include<deque>
using namespace std;
deque <int> cycle;
void HamiltonCycle(bool ** A, int n) {
	for (int k = 0; k < n*(n - 1); k++) {
		if (A[cycle.at(0)][cycle.at(1)] == 0) {
			int i = 2;
			while (A[cycle.at(0)][cycle.at(i)] == 0 || A[cycle.at(1)][cycle.at(i + 1)] == 0) {
				i++;
			}
			int t = cycle.at(i);
			cycle.erase(cycle.cbegin() + i);
			cycle.insert(cycle.cbegin() + i, cycle.at(1));
			cycle.erase(++cycle.cbegin());
			cycle.insert(++cycle.cbegin(), t);
		}
		cycle.push_back(cycle.front());
		cycle.pop_front();
	}
	for (int i = 0; i < n; i++) {
		cout << cycle.at(i) + 1 << " ";
	}
}
int main() {
	int n;
	bool** matrix;
	cin >> n;
	matrix = new bool*[n];
	for (int i = 0; i < n; i++) {
		matrix[i] = new bool[n];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> matrix[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		cycle.push_back(i);
	}
	HamiltonCycle(matrix, n);
	return 0;
}
