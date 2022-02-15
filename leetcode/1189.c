#define MIN(a, b) ((a < b) ? (a) : (b))

#define B 0
#define A 1
#define L 2
#define O 3
#define N 4

int maxNumberOfBalloons(char *text) {
	int word[5];
	int res = INT_MAX;
	int len = strlen(text);
	memset(word, 0, sizeof(int) * 5);
	for (int i = 0; i < len; i++) {
		switch (text[i]) {
			case 'b':
				word[B]++;
				break;
			case 'a':
				word[A]++;
				break;
			case 'l':
				word[L]++;
				break;
			case 'o':
				word[O]++;
				break;
			case 'n':
				word[N]++;
				break;
			default:
				break;
		}
	}
	word[L] /= 2;
	word[O] /= 2;

	for (int i = 0; i < 5; i++) {
		res = MIN(res, word[i]);
	}
	return res;
}
