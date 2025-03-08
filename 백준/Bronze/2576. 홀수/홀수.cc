#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int x, odd = 0; 
    int sum = 0; 
    int min = 100;

    for(int i = 0 ; i < 7; i++){
        cin >> x;

        if(x & 1){
            odd = 1;
            sum += x;
            
            if(min > x){
                min = x;
            }
        }

        
    }

    if(odd) {
        cout << sum << "\n";
        cout << min;
    }
    else cout << "-1";

    return 0;
}