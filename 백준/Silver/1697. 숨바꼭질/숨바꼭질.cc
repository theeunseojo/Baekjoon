#include <bits/stdc++.h>
using namespace std;
#define MAX 200001

int vis[MAX] = {0,};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, k;
    cin >> n >> k;

    queue <int> q;
    q.push(n);
    
    fill(vis, vis + MAX, -1);
    vis[n] = 0;
    int ans = -1;
    while(!q.empty()){
        int cur = q.front(); q.pop();
        
        
        if(cur == k) {
            cout << vis[cur];
            return 0;
        }
        
        if(cur -1 >= 0 && vis[cur - 1] < 0){
            vis[cur - 1] = vis[cur] + 1;
            q.push(cur -1);
        }
        if(cur + 1 < MAX && vis[cur + 1] < 0){
            vis[cur + 1] = vis[cur] + 1;
            q.push(cur + 1);
        }
        if(2 * cur < MAX && vis[2 * cur] < 0){
            vis[2 * cur] = vis[cur] + 1;
            q.push(2 * cur);
        }
    }
    

    


    return 0;
}