/*
 *	3	7	8
 *	9	11	13
 *	15	16	17
 * */

int min(int a, int b) {
	return a > b ? b : a;
}

int max(int a, int b) {
	return a > b ? a : b;
}

int* luckyNumbers(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
	int* ans = (int*)malloc(sizeof(int) * min(matrixSize, matrixColSize[0]));
	int* minRow = (int*)malloc(sizeof(int) * matrixSize);
	int* maxCol = (int*)malloc(sizeof(int) * matrixColSize[0]);
	memset(minRow, 0x3f, sizeof(int) * matrixSize);
	memset(maxCol, 0, sizeof(int) * matrixColSize[0]);
	for(int i = 0; i < matrixSize; i++) {
		for(int j = 0; j < matrixColSize[0]; j++) {
			minRow[i] = min(minRow[i], matrix[i][j]);
			maxCol[j] = max(maxCol[j], matrix[i][j]);
		}
	}
	int index = 0;
	for(int i = 0; i < matrixSize; i++) {
		for(int j = 0; j < matrixColSize[0]; j++) {
			if(matrix[i][j] == minRow[i] && matrix[i][j] == maxCol[j])
				ans[index++] = matrix[i][j];
		}
	}

	free(minRow);
	free(maxCol);
	*returnSize = index;
	return ans;
}
