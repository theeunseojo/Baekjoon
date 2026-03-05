#include <bits/stdc++.h>

using namespace std;

int n,t;

vector<int> v;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> t;

    for(int i = 0; i < t; i++){
        int n;
        cin >> n;
        v.push_back(n);
    }

    for(int num : v){
        int cnt = 0;
        while(num >= 5){
            cnt += num / 5;
            num /= 5;
        }
        cout << cnt << "\n";
    }
    return 0;
}