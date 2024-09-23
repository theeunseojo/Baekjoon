#include <iostream>
using namespace std;

int main(){
    
    int n;
    cin >> n;
    int sum = 0;
    
    
    for(int i = 1; i <= n; i++){
            int m = i;
            sum = m;
            // 각 자리수 더하기.
            while(m > 9){  
                sum = sum + m % 10;
                m /= 10;
            }
            sum += m; // 일의 자리 저장 
            if(sum == n){
                cout << i;
                break;
            }
            
        }
    if(sum != n) cout << 0;


    return 0;
}