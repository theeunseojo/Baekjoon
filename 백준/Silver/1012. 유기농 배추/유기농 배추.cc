#include <bits/stdc++.h>

using namespace std;

int t;
int n, m, k;
int y, x;
int a[51][51];
bool visited[51][51];
vector<int> ans;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

void dfs(int y, int x){

    visited[y][x] = 1;

    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];

        if(ny < 0 || ny >= n || nx < 0 || nx >= m || !a[ny][nx]) continue;
        if(visited[ny][nx]) continue;

        visited[ny][nx] = 1;
        dfs(ny, nx);

    }
    return ;
}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    
    cin >> t;
    for(int i = 0; i < t; i++){
        int cnt = 0;
        memset(a, 0, sizeof(a));
        memset(visited, 0, sizeof(visited));
        cin >> m >> n >> k;
        for(int i = 0; i < k; i++){
            cin >> x >> y;
            a[y][x] = 1;
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(a[i][j] && !visited[i][j]){ 
                    dfs(i, j);
                    cnt++;
                }
            }
        }

        ans.push_back(cnt);
    }


    for(int num : ans){
        cout << num << "\n";
    }


    return 0;
}