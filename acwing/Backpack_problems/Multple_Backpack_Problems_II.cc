#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

const int V = 20200;
int f[V];
int v[V], w[V];

int main(){
	int n, m, count = 0, vi, wi, si;
	cin >> n >> m;
	// Initialize.
	for(int i = 0; i < n; i++){
		int j = 1;
		cin >> vi >> wi >> si;
		while(j <= si){
			si -= j;
			v[count] = j * vi;
			w[count++] = j * wi;
			j <<= 1;
		}

		if(si > 0){
			v[count] = si * vi;
			w[count++] = si * wi;
		}
	}


	n = count;

	for(int i = 0; i < n; i++){
		for(int j = m; j >= v[i]; j--)
			f[j] = max(f[j], f[j - v[i]] + w[i]);
	}

	cout << f[m] << endl;
	return 0;
}
