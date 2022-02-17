/*
 *	Disjoint Set
 */
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>

using namespace std;

const int N = 5010;

const string _y = "Yes";
const string _n = "No";

int fa[N];
int _rank[N];

inline void init() {
	for(int i = 0; i < N; i++) {
		fa[i] = i;
		_rank[i] = 1;
	}
}

inline int find(int x) {
	if(fa[x] == x)
		return x;
	else
		return find(fa[x]);
}

inline void merge(int i, int j) {
	int x = find(i), y = find(j);
	if(_rank[x] <= _rank[y])
		fa[x] = y;
	else
		fa[y] = x;
	if(_rank[x] == _rank[y] && x != y)
		_rank[y]++;
}

int main() {
	int n, m, p, x, y;
	cin >> n >> m >> p;

	//Initalize the disjoint set
	init();

	for(int i = 0; i < m; i++) {
		cin >> x >> y;
		merge(x, y);
	}

	for(int i = 0; i < p; i++) {
		cin >> x >> y;
		if(find(x) != find(y))
			cout << _n << endl;
		else
			cout << _y << endl;
	}

	return 0;
}
