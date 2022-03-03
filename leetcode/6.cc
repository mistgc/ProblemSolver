#include <vector>
#include <string>
using namespace std;
/*
 * numRows = 4
 * P     I
 * A   L S
 * Y A   H
 * P     I
 */
//class Solution {
//public:
//	string convert(string s, int numRows) {
//		int n = s.length(), r = numRows;
//		if(r == 1 || r >= n)
//			return s;
//		int t = 2 * r - 2, c = 2 * (n / t);
//		// Create a r * c array.
//		vector<string> mat(r, string(c, 0));
//		for(int i = 0, x = 0, y = -1; i < n; i++) {
//			if(i % t == 0 || i % t == r-1)
//				y++;
//			if(i % t < r-1) {
//				mat[x++][y] = s[i];
//			}else
//				mat[x--][y] = s[i];
//		}
//
//		string ans;
//		for(auto &row : mat) {
//			for(char ch : row) {
//				if(ch)
//					ans += ch;
//			}
//		}
//		return ans;
//	}
//};
//
class Solution {
public:
	string convert(string s, int numRows) {
		if (numRows < 2 || numRows > s.length())
			return s;
		int i = 0, flag = -1;
		vector<string> str(numRows);
		for(auto ch : s) {
			str[i] += ch;
			if(i == 0 || i == numRows - 1)
				flag = -flag;
			i += flag;
		}
		string ans;
		for(int j = 0; j < numRows; j++) {
			ans += str[j];
		}
		return ans;
	}
};
