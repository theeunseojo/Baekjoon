#include <bits/stdc++.h>
#define MAX 100
using namespace std;

int n;
int mat_h[MAX][MAX];
bool visited[MAX][MAX];
int flood[MAX][MAX];

int min_h = 101;
int max_h = 0;

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

int answer = 0;

void dfs(int y, int x){
    visited[y][x] = 1;

    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];

        if(ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
        if(flood[ny][nx] == 1&& !visited[ny][nx]){
            dfs(ny, nx);
        }
    }

    return;
}

void flooding(int h){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(mat_h[i][j] > h){
                flood[i][j] = 1;
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> mat_h[i][j];
            min_h = min(min_h, mat_h[i][j]);
            max_h = max(max_h, mat_h[i][j]);
        }
    }

    // 최소 <= 높이 <= 최대 범위 안에서 물이 지나가서 잠기지 않은 지역을 표시
    for(int h = 0; h <= max_h; h++){
        int cnt = 0;
        fill(&flood[0][0], &flood[0][0] + 100 * 100, 0);
        fill(&visited[0][0], &visited[0][0] + MAX * MAX , 0);
        flooding(h);
      
        // dfs
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(flood[i][j] == 1 && !visited[i][j]){
                    // cout << "좌표 값 : " << i << "," << j << "\n";
                    dfs(i, j);
                    cnt++;
                }
            }
        }
        // 연결된 컴포넌트 갯수 갱신
        answer = max(answer,cnt);
    }

    cout << answer;


    return 0;
}