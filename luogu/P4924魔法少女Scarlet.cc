#include <iostream>

using namespace std;

void rotate(int x, int y, int r, int z, int a[510][510]) {
	int b[510][510];
	for(int i = x-r; i <= x+r; i++) {
		for(int j = y-r; j <= y+r; j++) {
			if(z == 0)
				b[i][j] = a[x+y-j][y-x+i];
			else
				b[i][j] = a[x-y+j][x+y-i];
		}
	}

	for(int i = x-r; i <= x+r; i++) {
		for(int j = y-r; j <= y+r; j++){
			a[i][j] = b[i][j];
		}
	}
}

int a[510][510];
int n, m, x, y, r, z;

int main() {
	int mark = 1;
	cin >> n >> m;

	//Initailize matrix a.
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			a[i][j] = mark++;
		}
	}

	for(int i = 0; i < m; i++) {
		cin >> x >> y >> r >> z;
		rotate(x, y, r, z, a);
	}

	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}
