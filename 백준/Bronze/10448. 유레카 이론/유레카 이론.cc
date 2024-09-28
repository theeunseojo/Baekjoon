#include <iostream>
using namespace std;

int main(){
	int n;
	cin >> n;
	int sum = 0;
	int sum1, sum2, sum3;
	for(int i = 0; i < n; i++){
		int a;
		cin >> a;
		bool isTri = false;
		for(int t1 = 1; t1 < a; t1++){
			for(int t2 = 1; t2 < a; t2++){
				for(int t3 = 1; t3 < a; t3++){
					sum1 = (t1 + 1) * t1 / 2;
					sum2 = (t2 + 1) * t2 / 2;
					sum3 = (t3 + 1) * t3 / 2;
					sum = sum1 + sum2 + sum3;
					if(a == sum){
						isTri = true;
						break;
					}
				}
				if(isTri) break;
			}
			if(isTri) break;
		}
		cout << isTri << "\n";
	}
	
	return 0;
}