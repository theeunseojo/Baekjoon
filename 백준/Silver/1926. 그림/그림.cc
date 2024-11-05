#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 502
using namespace std;

bool visited[MAX][MAX];
int board[MAX][MAX];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

queue <pair<int,int>> q;
int n, m;

int area = 0 , cnt = 0;
int bfs(int u , int v){ // 컴포넌트 (그림) 의 크기를 방문하면서 크기 return
    visited[u][v] = true;
    q.push({u, v});
    while(!q.empty()){ // cur를 기준으로 인접노드 탐색 
        pair <int, int> cur = q.front();
        q.pop();
        area++;
        for(int dir = 0; dir < 4; dir++){
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(visited[nx][ny] || board[nx][ny] == 0) continue;
            visited[nx][ny] = true;
            q.push({nx, ny});
        }
    }
    
   return area;
}
int main(){
    cin >> n >> m;
    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> board[i][j];
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(!visited[i][j] && board[i][j] == 1) { // 방문을 한적이 없고, 1인 구간에서 bfs 실행
                area = 0;
                cnt++;
                area = bfs(i, j);
                ans = max(area, ans);
            }
        }
    }

    cout << cnt << endl;
    cout << ans;
    return 0;
}