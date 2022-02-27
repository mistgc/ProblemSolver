/*
 * (Kn, Km) 代表骑士的当前位置
 * 棋盘大小为 n * n 
 * 有 8 种方向
 */
class Solution {
public:
	double knightProbability(int n, int k, int row, int column) {
		if(k <= 0 || row < 0 || row >= n || column < 0 || column >= n)
			return 0;
		int able = 0;
		double probability = 1;
		double probability_1, probability_2, probability_3, probability_4, probability_5, probability_6, probability_7, probability_8;
		probability_1 = probability_2 = probability_3 = probability_4 = probability_5 = probability_6 = probability_7 = probability_8 = 0;
		if(row + 1 >= 0 && row + 1 < n && column + 2 >= 0 && column + 2 < n) {
			able++;
			probability_1 = 1.0;
			probability_1 *= knightProbability(n, --k, row + 1, column + 2);
		}

		if(row + 2 >= 0 && row + 2 < n && column + 1 >= 0 && column + 1 < n) {
			able++;
			probability_2 = 1.0;
			probability_2 *= knightProbability(n, --k, row + 2, column + 1);
		}

		if(row - 1 >= 0 && row - 1 < n && column - 2 >= 0 && column - 2 < n) {
			able++;
			probability_3 = 1.0;
			probability_3 *= knightProbability(n, --k, row - 1, column - 2);
		}

		if(row - 2 >= 0 && row - 2 < n && column - 1 >= 0 && column - 1 < n) {
			able++;
			probability_4 = 1.0;
			probability_4 *= knightProbability(n, --k, row - 2, column - 1);
		}

		if(row - 1 >= 0 && row - 1 < n && column + 2 >= 0 && column + 2 < n) {
			able++;
			probability_5 = 1.0;
			probability_5 *= knightProbability(n, --k, row - 1, column + 2);
		}

		if(row + 2 >= 0 && row + 2 < n && column - 1 >= 0 && column - 1 < n) {
			able++;
			probability_6 = 1.0;
			probability_6 *= knightProbability(n, --k, row + 2, column - 1);
		}

		if(row - 2 >= 0 && row - 2 < n && column + 1 >= 0 && column + 1 < n) {
			able++;
			probability_7 = 1.0;
			probability_7 *= knightProbability(n, --k, row - 2, column + 1);
		}

		if(row + 1 >= 0 && row + 1 < n && column - 2 >= 0 && column - 2 < n) {
			able++;
			probability_8 = 1.0;
			probability_8 *= knightProbability(n, --k, row + 1, column - 2);
		}

		probability = able / 8.0;
		probability *= probability_1 + probability_2 + probability_3 + probability_4 + probability_5 + probability_6 + probability_7 + probability_8;
		return probability;
	}
};
