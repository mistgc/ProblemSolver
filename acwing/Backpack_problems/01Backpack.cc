#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
const int N = 1010;
int f[N][N];
int n, m;
int v[N], w[N];

int main(){
	cin >> n >> m;

	for(int i = 1; i <= n; i++){
		cin >> v[i] >> w[i];
	}

	for(int i = 1; i <= n; i++){
		for(int j = 0; j <= m; j++){
			f[i][j] = f[i - 1][j];
			if(j >= v[i])
				f[i][j] = max(f[i][j], f[i - 1][j - v[i]] + w[i]);
		}
	}

	int result;

	result = f[n][m];

	cout << result;
	return 0;
}
