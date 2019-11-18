#include <iostream>
#include <algorithm>
#include <vector>
#include <time.h>
using namespace std;
void dfs(int v, int p, vector<vector<int>> g, int N, bool* used, int* tin, int* fup, int timer, bool* sharnir) {
	used[v] = true;
	tin[v] = fup[v] = timer++;
	int children = 0;
	for (size_t i = 0; i < g[v].size(); ++i) {
		int to = g[v][i];
		if (to == p) continue;
		if (used[to]) {
			fup[v] = min(fup[v], tin[to]);
		}
		else {
			dfs(to, v, g, N, used, tin, fup, timer, sharnir);
			fup[v] = min(fup[v], fup[to]);
			if ((fup[to] >= tin[v]) && p != -1) {
				sharnir[v] = true;
			}
			++children;
		}
	}
	if (p == -1 && children > 1) {
		sharnir[v] = true;
	}
}
int main() {
	int X, N, V;
	cin >> N;
	bool* last_element = new bool[N];
	vector<vector<int>> spisok(N);
	for (int i = 0; i < N; i++) {
		cin >> V;
		if (V == 1) {
			last_element[i] = 1;
		}
		else {
			last_element[i] = 0;
		}
		for (int j = 0; j < V; j++) {
			cin >> X;
			spisok[i].push_back(X);
		}
	}
	int timer = 0;
	bool* used = new bool[N];
	for (int i = 0; i < N; ++i) {
		used[i] = false;
	}
	int* tin = new int[N];
	int* fup = new int[N];
	bool* sharnir = new bool[N];
	for (int i = 0; i < N; i++) {
		sharnir[i] = false;
	}
	dfs(0, -1, spisok, N, used, tin, fup, timer, sharnir);
	int a = 0;
	for (int i = 0; i < N; i++) {
		a = 0;
		if (sharnir[i] == true || last_element[i] == true) {
			for (int j = 0; j < spisok[i].size(); j++) {
				if (sharnir[spisok[i][j]] == true || last_element[spisok[i][j]] == true) {
					a++;
				}
				if (a >= 3) {
					cout << i << endl;
				}
			}
		}
	}
	return 0;
}
