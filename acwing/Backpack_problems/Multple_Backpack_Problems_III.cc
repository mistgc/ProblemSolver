/*============================
*	File Name: .\Multple_Backpack_Problems_III.cc
*	Created Date: 1/9/2022 9:11:21 AM
*	Last Modified Date:1/9/2022 11:20:42 AM
*	Author: mistgc
*	Email: georgecai0908@outlook.com
============================*/
#include <algorithm>
#include <iostream>
#define V 20010

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

int f[V], q[V], g[V];
int n, m;

int main(){
	cin >> n >> m;

	for(int i = 0; i < n; i++){
		int v, w, s;
		cin >> v >> w >> s;
		for(int j = 0; j < v; j++){
			for(int k = 0; k <= m; k += v){

			}
		}
	}


	return 0;
}













