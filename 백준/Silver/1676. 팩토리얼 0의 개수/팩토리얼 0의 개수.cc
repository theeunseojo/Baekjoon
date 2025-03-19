#include <bits/stdc++.h>

using namespace std;

/*
1. 500! 너무 큰 숫자로 인해 시간초과 뜨기에 좀 더 효율적으로 풀어야함.
2. 아이디어 124000 = 124 * 10^3로 풀이되고, 소인수분해하게 되면 2 ^3 * 5 ^ 3승임. 
2.1 2 와 5의 계승중 최솟값을 구하면 그게 바로 0의 갯수가 되는 것임.

추가적으로 더 깔쌈한 풀이는 
5의배수 개수 + 25의 배수 개수
*/
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;

	int two_cnt = 0;
	int five_cnt = 0;

	// nlogn
	for(int i = 1; i <= n; i++){
		int temp = i;
		while(temp % 2 == 0){
			two_cnt++;
			temp /= 2;
		}
		temp = i;
		while(temp % 5 == 0){
			five_cnt++;
			temp /= 5;
		}
	}

	int res = min(two_cnt, five_cnt);
	cout << res;
	return 0;
}