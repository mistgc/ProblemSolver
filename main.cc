#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;
typedef long long LL;

LL divisor[200]; 

int getDivisor(LL n){
	int count = 0;

	for(LL i = 1; i <= n / i; i++){
		if(n % i == 0){
			divisor[count++] = i;
			if(i * i != n){
				divisor[count++] = n / i;
			}
		}
	}

	return count;
}

int main(){
	LL n = 2021041820210418;
	int count = getDivisor(n);
	cout << count << endl;
	int ans = 0;

	for(int i = 0; i < count; i++){
		for(int j = 0; j < count; j++){
			if(!(n % (divisor[i] * divisor[j]))) ans++;
		}
	}

	cout << ans << endl;
	
	return 0;
}
