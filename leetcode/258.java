class Solution {
	/*
	 *	num = 38
	 *	3 + 8 -> 11
	 *	1 + 1 -> 2
	 *
	 *	When the digit of number greater than one, the number should be handled again.
	 *	When the digit of number is one, the answer can be returned.
	 */
	public int addDigits(int num) {
		int ans = num;
		while(ans >= 10) {
			int temp = 0;
			while(ans > 0) {
				temp += ans % 10;
				ans /= 10;
			}
			ans = temp;
		}
		return ans;
	}
}
