int max(int a, int b) {
	return a > b ? a : b;
}
int lengthOfLongestSubstring(char* s) {
	int length = 0;
	int left = 0, right = 0;
	int p = left;

	while(right < strlen(s)) {
		for(p = left; p < right; p++) {
			if(s[p] == s[right])
				p = ++left - 1;
		}
		length = max(right - left + 1, length);
		// printf("l = %d r = %d length = %d\n", left, right, length);
		right++;
	}

	return length;
}
