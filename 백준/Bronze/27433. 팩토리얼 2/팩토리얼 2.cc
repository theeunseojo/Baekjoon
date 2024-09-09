#include <iostream>
using namespace std;


__int64_t fibo(int n){
	if(n == 0) return 1;
	return (__int64_t)n * fibo(n - 1);
}
int main(){
	int n;
	cin >> n;
	cout << fibo(n);
	return 0;
}