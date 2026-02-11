#include <bits/stdc++.h>
using namespace std;

map<long long, long long> mp;
long long N,M;
long long arr[15001];
int cnt;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;

    for(int i = 0; i < N; i++){
        cin >> arr[i];
        mp.insert({arr[i], arr[i]});
    }

    for(int i = 0; i < N; i++){
        long long match = M - arr[i];
        if(mp[match]) cnt++;
    }

    cout << cnt / 2;


    return 0;
}