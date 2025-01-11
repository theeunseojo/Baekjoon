#include <bits/stdc++.h>
#define MAX 1001
#define X first 
#define Y second

using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

string board[MAX];
int dist1[MAX][MAX];
int dist2[MAX][MAX];
queue<pair<int,int>> q1;
queue<pair<int,int>> q2;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int r, c;
    cin >> r >> c;

    for(int i = 0; i < r; i++){ // 시작점과 방문 안한점 구분위해 -1로 초기화
        fill(dist1[i], dist1[i] + c, -1);
        fill(dist2[i], dist2[i] + c, -1);
    }
    

    for(int i = 0; i < r; i++){
        cin >> board[i];
    }

    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            if(board[i][j] == 'F') {
                dist1[i][j] = 0;
                q1.push({i,j});
            }
            if(board[i][j] == 'J'){
                dist2[i][j] = 0;
                q2.push({i,j});
            }
        }
    }
    
    
    // 불 bfs
    while(!q1.empty()){
        auto cur = q1.front(); q1.pop();
        for(int i = 0; i < 4; i++){
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            if(nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
            if(dist1[nx][ny] >= 0) continue;
            if(board[nx][ny] == '#') continue;
           
            dist1[nx][ny] = dist1[cur.X][cur.Y] + 1;
            q1.push({nx,ny});
        }
    }
    
    // 지훈 bfs
    while(!q2.empty()){
        auto cur = q2.front(); q2.pop();
        for(int i = 0; i < 4; i++){
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];

            if(nx < 0 || nx >= r || ny < 0 || ny >= c) {
                // 탈출
                cout << dist2[cur.X][cur.Y] + 1;
                return 0;
            }
            if(dist2[nx][ny] >= 0 || board[nx][ny] == '#') continue; // 방문했거나, 벽이 있는 곳 
            if(dist1[nx][ny] != -1 && dist1[nx][ny]  <= dist2[cur.X][cur.Y] + 1) continue;   // 불이 먼저 지나간 곳은 가지 않는다 이때 동시에 도착이 아님 -> 불이 도착 이후, 지훈이 도착하는것임 분리시켜서 생각                                             
            dist2[nx][ny] = dist2[cur.X][cur.Y] + 1;
            q2.push({nx,ny});
            
        }
    }  
    cout << "IMPOSSIBLE";



    return 0;
}