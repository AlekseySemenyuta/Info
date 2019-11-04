#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
unordered_set < string > seen;
vector < int >edges;
void dfs(string node, int &k, string & A) {
	for (int i = 0; i < k; ++i)	{
		string str = node + A[i];
		if (seen.find(str) == seen.end()) {
			seen.insert(str);
			dfs(str.substr(1), k, A);
			edges.push_back(i);
		}
	}
}
string deBruijn(int n, int k, string A) {
	seen.clear();
	edges.clear();
	string startingNode = string(n - 1, A[0]);
	dfs(startingNode, k, A);
	string s;
	int l = pow(k, n);
	for (int i = 0; i < l; ++i) {
		s += A[edges[i]];
	}
	s += startingNode;
	return s;
}
int main() {
	int N, k;
	cin >> N;
	cin >> k;
	string A = "qwerty";
	cout << deBruijn(N, k, A);
	return 0;
}
