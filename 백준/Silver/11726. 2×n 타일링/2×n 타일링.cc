#include <bits/stdc++.h>

using namespace std;

int v[1001] = {};

void getTileNum(int n){
	
	
	v[0] = 0, v[1] = 1, v[2] = 2;
	if (n > 2){
		for(int i = 3; i <= n; i++){
			v[i] = (v[i - 1] + v[i - 2]) % 10007;
		}
	}
	


}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;

	// chrono::system_clock::time_point start = std::chrono::system_clock::now();
	// memoization
	getTileNum(n);
	// chrono::system_clock::time_point end = std::chrono::system_clock::now();
	// chrono::duration<double, std::milli> msec = end - start; 
	// cout << "실행시간: " << msec.count() << " msec" << std::endl;   
	int answer = v[n];
	cout << answer;

	return 0;
}