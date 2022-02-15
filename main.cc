/*============================
*	File Name: main.cc
*	Created Date: 12/18/2021 10:47:42 AM
*	Last Modified Date:1/28/2022 12:26:07 AM
*	Author: mistgc
*	Email: georgecai0908@outlook.com
============================*/
#include <iostream>
#include <algorithm>
#include <cstring>
/* 
 * > or < :	表示人
 *		>		<
 *	   ===============
 *		1	2	3	4
 *
 *		>	>	<	>	<
 *	   ===================
 *		1	2	3	4	5
 */

using namespace std;


int main(){
	int l, n, coord, maxt, mint;
	cin >> l;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> coord;
		maxt = max(maxt, max(l-coord+1, coord));
		mint = max(maxt, min(l-coord+1, coord));
	}
	
	cout << mint << ' ' << maxt << endl;

	return 0;
}
