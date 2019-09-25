#include <iostream>
#include <vector>
using namespace std;

class matrix_adj {
public:
	int v;
	bool **matrix;
	void input_() {
		cin >> v;
		matrix = new bool *[v];
		for (int i = 0; i < v; i++) {
			matrix[i] = new bool[v];
		};
		for (int i = 0; i < v; i++) {
			for (int j = 0; j < v; j++) {
				cin >> matrix[i][j];
			};
		};
	}
	void output_() {
		cout << v << endl;
		cout << "   ";
		for (int i = 0; i < v; i++) {
			cout << (i + 1) << "  ";
		};
		cout << endl;
		for (int i = 0; i < v; i++) {
			for (int j = -1; j < v; j++) {
				if (j < 0) {
					cout << (i + 1) << "  ";
					continue;
				};
				cout << matrix[i][j] << "  ";
			};
			cout << endl;
		};
	}
};

class list_edge {
public:
	int v, edge;
	vector <pair <int, int> > list_;
	void input_() {
		cin >> v >> edge;
		for (int i = 0; i < edge; i++) {
			int a, b;
			cin >> a >> b;
			list_.push_back(make_pair(a, b));
		};
	}
	void output_() {
		cout << v << " ";
		edge = list_.size();
		cout << edge << endl;
		for (int i = 0; i < edge; i++) {
			pair<int, int> t = list_[i];
			cout << t.first << " " << t.second << endl;
		};
	}
};

class list_adj {
public:
	int v;
	vector < vector <int> > list_;
	void input_() {
		cin >> v;
		list_ = vector < vector <int> >(v);
		int a;
		for (int i = 0; i < v; i++) {
			for (int j = 0; j < v; j++) {
				cin >> a;
				if (a == -1) break;
				list_[i].push_back(a);
			};
		};
	}
	void output_() {
		cout << v << endl;
		for (int i = 0; i < v; i++) {
			vector <int> t = list_[i];
			cout << (i + 1) << " : { ";
			for (size_t j = 0; j < t.size(); j++) {
				cout << t[j] << ", ";
			};
			cout << "}" << endl;
		};
	}
};

void l_adj_to_m_adj(list_adj A, matrix_adj &B) {
	B.v = A.v;
	B.matrix = new bool *[A.v];
	for (int i = 0; i < A.v; i++) {
		B.matrix[i] = new bool[A.v];
	};
	for (int i = 0; i < B.v; i++) {
		for (int j = 0; j < B.v; j++) {
			B.matrix[i][j] = 0;
		}
	}
	for (int i = 0; i < A.v; i++) {
		for (size_t j = 0; j < (A.list_[i].size()); j++) {
			B.matrix[i][A.list_[i][j] - 1] = 1;
		};
	};
}

void m_adj_to_l_adj(matrix_adj A, list_adj &B) {
	B.v = A.v;
	B.list_ = vector < vector <int> >(B.v);
	for (int i = 0; i < A.v; i++) {
		for (int j = i; j < A.v; j++) {
			if (A.matrix[i][j]) {
				(B.list_[i]).push_back(j + 1);
				(B.list_[j]).push_back(i + 1);
			};
		};
	};
}

void l_edge_to_m_adj(list_edge A, matrix_adj &B) {
	B.v = A.v;
	B.matrix = new bool *[A.v];
	for (int i = 0; i < A.v; i++) {
		B.matrix[i] = new bool[A.v];
	};
	for (int i = 0; i < B.v; i++) {
		for (int j = 0; j < B.v; j++) {
			B.matrix[i][j] = 0;
		}
	}
	for (size_t i = 0; i < (A.list_).size(); i++) {
		pair <int, int> t = A.list_[i];
		B.matrix[t.first - 1][t.second - 1] = 1;
		B.matrix[t.second - 1][t.first - 1] = 1;
	};
}

void m_adj_to_l_edge(matrix_adj A, list_edge &B) {
	B.v = A.v;
	for (int i = 0; i < A.v; i++) {
		for (int j = i; j < A.v; j++) {
			if (A.matrix[i][j]) {
				(B.list_).push_back(make_pair((i + 1), (j + 1)));
			};
		};
	};
}

void l_adj_to_l_edge(list_adj A, list_edge &B) {
	B.v = A.v;
	for (int i = 0; i < A.v; i++) {
		for (size_t j = 0; j < (A.list_[i]).size(); j++) {
			if (A.list_[i][j] > i) {
				B.list_.push_back(make_pair((i + 1), A.list_[i][j]));
			};
		};
	};
	B.edge = B.list_.size();
}

void l_edge_to_l_adj(list_edge A, list_adj &B) {
	B.v = A.v;
	B.list_ = vector < vector <int> >(B.v);
	for (size_t i = 0; i < A.list_.size(); i++) {
		pair <int, int> t = A.list_[i];
		int k = t.first, l = t.second;
		B.list_[k - 1].push_back(l);
		B.list_[l - 1].push_back(k);
	};
}

int main() {
	system("pause");
	return 0;
}