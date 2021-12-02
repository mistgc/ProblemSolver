/*
 *	To solve this question. We can think of it as a 01-Backpack problem.
 *
 *	It's like having s[i] items for same price.
 *
 *	Transfer equation:
 *		f[i][v] = max{f[j - i][v - k * c[i]] + k * w[i] | 0 <= k <= n[i]}
 *
 *	Time complexity:
 *		O(V * SUM{n[i]})
 */
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 101;

int f[N];

int v[N], w[N], s[N];

int n, m;

int main(){
	cin >> n >> m;

	for(int i = 0; i < n; i++){
		cin >> v[i] >> w[i] >> s[i];
	}

	for(int i = 0; i < n; i++){
		for(int j = m; j >= v[i]; j--){
			for(int k = 0; k <= s[i] && k * v[i] <= j; k++){
				f[j] = max(f[j], f[j - k * v[i]] + k * w[i]);
			}
		}
	}

	cout << f[m] << endl;

	return 0;
}
