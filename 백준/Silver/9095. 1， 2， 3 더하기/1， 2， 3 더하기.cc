#include <bits/stdc++.h>

using namespace std;
int d[12];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    d[1] = 1; d[2] = 2; d[3] = 4;

    for(int i = 4; i <= 11; i++){
        d[i] = d[i - 3] + d[i - 2] + d[i - 1]; 
    }
    
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        cout << d[n] << "\n";
    }

    return 0;
}