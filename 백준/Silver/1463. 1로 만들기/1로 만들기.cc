#include <bits/stdc++.h>
#define MAX 1000000
using namespace std;

int arr[MAX + 1];
int dist[MAX + 1];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);


    int n;
    cin >> n;

    fill(dist, dist + MAX + 1, 0);
    queue <int> Q;
    Q.push(1);

    while(!Q.empty()){
        int cur = Q.front(); Q.pop();
        for(int nxt : {cur * 2, cur * 3 , cur + 1}){
            if(nxt > MAX) continue;
            if(dist[nxt] > 0) continue;
            dist[nxt] = dist[cur] + 1;
            Q.push(nxt);
        }
    }

    cout << dist[n];

    return 0;
}