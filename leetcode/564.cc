#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
/*
 *	Because the given data in the question ranges from 1 to 10^18,
 *	we need to store the data by using the Long type.
 *
 *	The problem solving idea comes from [zhihu](https://zhuanlan.zhihu.com/p/474514508).
 *
 *	When length of the string n is equal to 1:
 *		ans = stol(n) - 1;
 *	When length of the string n is greater than 1:
 *		e.g. n = "1234"		ans = "1221"
 *			 n = "120"		ans = "121"
 *		1. The length of the string n is even.
 *			ans = n[0] + n[1] + ... + n[length/2] + n[length/2] + ... + n[1] + n[0]
 *		2. The length of the string n is odd.
 *			ans = n[0] + n[1] + ... + n[length/2+1] + ... + n[1] + n[0]
 */
class Solution {
public:
	string nearestPalindromic(string n) {
		int len = n.length();
		if(len < 2)
			return to_string(stoi(n) - 1);
		long set[5];
		set[0] = (long)pow(10l, len - 1) - 1;		// 10^(n-1) - 1 = 99...99
		set[1] = (long)pow(10l, len) + 1;			// 10^n + 1 = 10...01
		long t = stol(n.substr(0, (len + 1) / 2));
		int index = 2;
		for(int i = t - 1; i <= t + 1; i++) {
			long temp;
			if(len % 2 == 0)
				temp = getNum(i, true);
			else
				temp = getNum(i, false);
			if(temp != stol(n)) set[index++] = temp;
		}
		long ans = -1, tmp = 0xffffffff;
		for(auto i : set) {
			if(tmp > abs(i - stol(n))) {
				tmp = abs(i - stol(n));
				ans = i;
			}
		}
		return to_string(ans);
    }
	long getNum(long n, bool isEven) {
		string sn = to_string(n);
		int idx = isEven ? sn.length() - 1 : sn.length() - 2;
		while(idx >= 0)
			sn += sn[idx--];
		return stol(sn);
	}
};
