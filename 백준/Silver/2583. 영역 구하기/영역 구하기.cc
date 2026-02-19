#include <bits/stdc++.h>
#define MAX 100
using namespace std;

int n, m, k;

int arr[MAX][MAX];
bool visited[MAX][MAX];

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
vector<int> answer;
int ccnt;

void color(int sx, int sy, int ex, int ey){
    
    for(int i = sy; i < ey; i++){
        for(int j = sx; j < ex; j++){
            arr[i][j] = 1;
        }
    }
}

void dfs(int y, int x ){
    visited[y][x] = 1;
    ccnt++;
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];

        if(ny < 0 || ny >= m || nx < 0 || nx >= n || arr[ny][nx] == 1) continue;
        if(visited[ny][nx]) continue;
        dfs(ny, nx);
    }


    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> m >> n >> k;
    int cnt = 0;

    for(int i = 0; i < k; i++){
        int sy, sx, ey, ex;
        cin >> sx >> sy >> ex >> ey;
        color(sx, sy, ex, ey);
    }


    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(arr[i][j] == 0 && !visited[i][j]){
                //cout << i << ", " << j << " -> ";
                ccnt = 0;
                cnt++;
                dfs(i, j);
                //cout << "ccnt : "<< ccnt << "\n";
                answer.push_back(ccnt);
            }
        }
    }

    cout << cnt << "\n";

    sort(answer.begin(), answer.end());
    for(int c : answer){
        cout << c << " ";
    }

    return 0;
}