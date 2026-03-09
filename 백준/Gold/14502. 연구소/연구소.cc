#include<bits/stdc++.h>
using namespace std;


int n, m,ret;

int a[10][10];

vector<pair<int,int>> wall;
vector<pair<int,int>> vir;

int dy[4] = {0, -1, 0, 1};
int dx[4] = {1, 0, -1, 0};
bool visited[10][10];

void dfs(int y, int x){
    visited[y][x] = 1;
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
    
        if(nx < 0 || nx >= m || ny < 0 || ny >= n || a[ny][nx]) continue;
        if(a[ny][nx] == 0 && !visited[ny][nx]){
            dfs(ny, nx);
        }
    }

    return;
    
}

int main(){
    cin.tie(NULL); cout.tie(NULL);


    cin >> n >> m;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];

            if(a[i][j] == 0) wall.push_back({i,j});
            if(a[i][j] == 2) vir.push_back({i,j});
        }
    }


    // 벽을 세운다
    int l = wall.size();
    for(int i = 0; i < l; i++){
        for(int j = 0; j < i; j++){
            for(int k = 0; k < j; k++){

                fill(&visited[0][0], &visited[0][0] + 10 * 10, 0);

                pair<int,int> w1 = wall[i];
                pair<int,int> w2 = wall[j];
                pair<int,int> w3 = wall[k];

                a[w1.first][w1.second] = 1;
                a[w2.first][w2.second] = 1;
                a[w3.first][w3.second] = 1;
                
                
                // 바이러스 퍼뜨린다
                for(auto v : vir) dfs(v.first, v.second);

                // 영역의 갯수 구한다
                int cnt = 0;
                for(int i = 0; i < n; i++){
                    for(int j = 0; j < m; j++){
                        if(a[i][j] == 0 && !visited[i][j]) cnt++;
                    }
                }
                ret = max(cnt, ret);

                a[w1.first][w1.second] = 0;
                a[w2.first][w2.second] = 0;
                a[w3.first][w3.second] = 0;

            }
        }
    }

   

    cout << ret;
  
   
    return 0;
}