#include <iostream>
#include <queue>
#include <vector>
#define MAX 1002
using namespace std;


int arr[MAX][MAX];
int dist[MAX][MAX];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};


int main(){
    int n, m;
    cin >> m >> n;
    queue <pair<int, int>> q;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> arr[i][j];
            if(arr[i][j] == 1) q.push(pair <int, int>(i, j));
            if(arr[i][j] == 0) dist[i][j] = -1;
        }
    }

  
    while(!q.empty()){
        pair<int, int> cur = q.front(); q.pop();
        
        for(int i = 0; i < 4; i++){
            int x = cur.first + dx[i] ;
            int y = cur.second + dy[i];
            if(x < 0 || x >= n || y < 0 || y >=  m) continue;
            if(dist[x][y] >= 0) continue;
            q.push(pair<int,int>(x, y));
            dist[x][y] = dist[cur.first][cur.second] + 1;
        }

    }

    int ans = -1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(dist[i][j] == -1){
                cout << -1;
                return 0;
            }
            ans = max(ans, dist[i][j]);
        }
        
    } 


   
    cout << ans;
    return 0;
}