#include <iostream>
#include <queue>
#include <algorithm>

#define X first 
#define Y second
#define MAX 101
using namespace std;


int n, m;
int board[MAX][MAX] = {0,};
int visited[MAX][MAX] = {0,};
int dist[MAX][MAX] = {0,};
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};


int main(){
    
    queue<pair <int, int>> Q;
    cin >> n >> m;

   //이차원 배열 붙어서 입력일 경우 

    for(int i = 0; i < n; i++){
        string a;
        cin >> a;
        for(int j = 0; j < m; j++){
            board[i][j] = a[j] - '0';
        }
    }

    
    
    
    
    // start point 
    dist[0][0] = 1; // 1, 1
    Q.push({0,0});
    

    while(!Q.empty()){
        pair <int, int> cur = Q.front(); Q.pop();
        for(int dir = 0; dir < 4; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];

            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if( dist[nx][ny] > 0|| board[nx][ny] == 0) continue;

            dist[nx][ny] = dist[cur.X][cur.Y]  + 1;
            Q.push({nx, ny});
            
        }
    }
    cout << dist[n - 1][m - 1];
    
    return 0;
}