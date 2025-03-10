#include <bits/stdc++.h>
#define X first 
#define Y second
#define MAX 101
using namespace std;

/*
1. 어떤 점으로부터 끊기지 않을때까지 방문하면서 숫자를 기록한다.
2. 그 기록한 값이 결국에 구역의 수가 된다.
3. 이걸 R,G,B 세개에 대해서 bfs 돌린다.
4. 적록색약의 경우 max(R,G) + B 해서 구역의 수를 계산한다.-> r하고 g가 번갈아서 나온다면 총 
*/

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    char arr[MAX][MAX];
    int visited[MAX][MAX];
    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            visited[i][j] = 0;
        }
    }

    
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
        }
    }
    

    int r = 0 ,g  = 0 ,b = 0; // 적록색약이 아닌 사람의 r,g,b영역의 개수 

    

    


    // R
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(arr[i][j] != 'R' || visited[i][j]) continue;
            r++;
            queue <pair<int,int>> pos;
            visited[i][j] = 1;
            pos.push({i,j});

            while(!pos.empty()){
                pair <int,int> cur = pos.front(); pos.pop();
        
                for(int dir = 0; dir < 4; dir++){
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
        
                    if(nx < 0 || nx >= n || ny < 0 || ny >= n || visited[nx][ny] == 1) continue;
                    if(arr[nx][ny] == 'R' && visited[nx][ny] != 1){
                        visited[nx][ny] = 1;
                        pos.push({nx,ny});
                    }
        
                }
            }
        }
    }

    // G
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(arr[i][j] != 'G' || visited[i][j]) continue;
            g++;
            queue <pair<int,int>> pos;
            visited[i][j] = 1;
            pos.push({i,j});

            while(!pos.empty()){
                pair <int,int> cur = pos.front(); pos.pop();
        
                for(int dir = 0; dir < 4; dir++){
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
        
                    if(nx < 0 || nx >= n || ny < 0 || ny >= n || visited[nx][ny] == 1) continue;
                    if(arr[nx][ny] == 'G' && visited[nx][ny] != 1){
                        visited[nx][ny] = 1;
                        pos.push({nx,ny});
                    }
        
                }
            }
        }
    }

     // B
     for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(arr[i][j] != 'B' || visited[i][j]) continue;
            b++;
            queue <pair<int,int>> pos;
            visited[i][j] = 1;
            pos.push({i,j});

            while(!pos.empty()){
                pair <int,int> cur = pos.front(); pos.pop();
        
                for(int dir = 0; dir < 4; dir++){
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
        
                    if(nx < 0 || nx >= n || ny < 0 || ny >= n || visited[nx][ny] == 1) continue;
                    if(arr[nx][ny] == 'B' && visited[nx][ny] != 1){
                        visited[nx][ny] = 1;
                        pos.push({nx, ny});
                    }
                   
        
                }
            }
        }
    }

    // 적록색약 
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            visited[i][j] = 0;
        }
    }
    int rg = 0; // 적록색약의 red and gree 영역의 갯수 

    // r and g
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(arr[i][j] == 'B' || visited[i][j]) continue; // 빨강, 초록이 아닌 경우 파랑밖에 없음.
            rg++;
            queue <pair<int,int>> pos;
            visited[i][j] = 1;
            pos.push({i,j});

            while(!pos.empty()){
                pair <int,int> cur = pos.front(); pos.pop();
        
                for(int dir = 0; dir < 4; dir++){
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
        
                    if(nx < 0 || nx >= n || ny < 0 || ny >= n || visited[nx][ny] == 1) continue;
                    if((arr[nx][ny] == 'R' || arr[nx][ny] == 'G') && visited[nx][ny] != 1){
                        visited[nx][ny] = 1;
                        pos.push({nx, ny});
                    }
                   
        
                }
            }
        }
    }

    int rgb = r + g + b; // 총 영역의 갯수
    int not_rgb = rg + b; // 적록색약의 총 영역의 갯수
    cout << rgb << " " << not_rgb;    


    return 0;
}