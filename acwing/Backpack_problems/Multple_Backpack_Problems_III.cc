#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;

/*
 * The equation of the most normal multple backpack:
 *		f[i][j] = max(f[i - 1][j], f[i - 1][j - k * c[i]] + k * w[i])
 * To observe the status transition equation, we will discover something
 * in it.
 * The status f[i][j] come from max{f[i - 1][j - k * c[i]] + k * w[i]}
 * The current status have relations with those status that they have same
 * remainder.
 *
 * (Rolling Array)
 * We could make 2D array to be a 1D array, if we change the range order.
 *
 * f[i][j]		(j: 0 -> n)
 * f[j]			(j: n -> 0)
 * */
const int N = 20010;

int f[N], q[N], g[N];
int n, m;

int main(){
	cin >> n >> m;

	//遍历物品
	for(int i = 0; i < n; i++){
		int v, w, s;
		cin >> v >> w >> s;
		memcpy(g, f, sizeof(f));
		//遍历余数
		for(int j = 0; j < v; j++){
			int head = 0, tail = -1;
			//遍历同余系
			for(int k = j; k <= m; k += v){
				f[k] = g[k];
				//将滑动窗口范围以外的值出队
				if(head <= tail && q[head] < k - v * s) head++;
				//如果单调队列中有值，则更新dp结果
				if(head <= tail) f[k] = max(f[k], g[q[head]] + (k - q[head]) / v * w);
				//当队尾小于要入队值时，将队尾出队
				while(head <= tail && g[q[tail]] - (q[tail] - j) / v * w <= g[k] - (k - j) / v * w) tail--;
				q[++tail] = k;
			}
		}
	}

	cout << f[m] << endl;

	return 0;
}
