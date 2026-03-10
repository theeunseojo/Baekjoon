#include <bits/stdc++.h>

using namespace std;

int r, c, t;
int arr[55][55];
int ret[55][55];

vector<pair<int,int>> dust;
vector<pair<int,int>> air;

int dy[4] = {0, -1, 0, 1};
int dx[4] = {1, 0, -1, 0};

int dir_cnt;

void spread(int y , int x){
    dir_cnt = 0;
    int amount = arr[y][x] / 5;
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(nx < 0 || nx >= c || ny < 0 || ny >= r ) continue;
        if(arr[ny][nx] == -1) continue;
        dir_cnt++;

        ret[ny][nx] += amount; 
    }

    ret[y][x] += arr[y][x] - (amount * dir_cnt);
}


void clean(){
    int up = air[0].first;
    int down = air[1].first;

    int pv, cur;
    
    // 위쪽 
    pv = 0;
    // 오
    for(int x = 1; x < c; x++){
        cur = ret[up][x];
        ret[up][x] = pv;
        pv = cur;
    }
    // 위
    for(int y = up - 1; y >= 0; y--){
        cur = ret[y][c-1];
        ret[y][c-1] = pv;
        pv = cur;
    }
    // 왼
    for(int x = c - 2; x >= 0; x--){
        cur = ret[0][x];
        ret[0][x] = pv;
        pv = cur;
    }
    // 아래
    for(int y = 1; y < up; y++){
        cur = ret[y][0];
        ret[y][0] = pv;
        pv = cur;
    }
    // 아래쪽
    pv = 0;
    // 오
    for(int x = 1; x < c; x++){
        cur = ret[down][x];
        ret[down][x] = pv;
        pv = cur;
    }
    // 아
    for(int y = down + 1; y < r; y++){
        cur = ret[y][c - 1];
        ret[y][c-1] = pv;
        pv = cur;

    }
    // 왼
    for(int x = c - 2; x >= 0; x-- ){
        cur = ret[r - 1][x];
        ret[r-1][x] = pv;
        pv = cur;
    }
    // 위
    for(int y = r - 2; y > down; y--){
        cur = ret[y][0];
        ret[y][0] = pv;
        pv = cur;
    }
    
    ret[up][0] = -1;
    ret[down][0] = -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> r >> c >> t;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cin >> arr[i][j];
            if(arr[i][j] >= 1) dust.push_back({i, j});
            if(arr[i][j] == -1) air.push_back({i, j});

        }
    }

    
    for(int i = 0; i < t; i++){
        fill(&ret[0][0], &ret[0][0] + 55 * 55, 0);
    
        for(auto v : air){
            ret[v.first][v.second] = -1;
        }
        // 미세먼지 확산시킨다.
        for(int j = 0; j < dust.size(); j++){
            pair<int,int> d = dust[j];
            spread(d.first, d.second);
           
        }
        // 공기청정기를 돌린다. 
        clean();

        dust.clear();
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                arr[i][j] = ret[i][j];
                if(arr[i][j] > 0) dust.push_back({i, j});
            }
        }
  
    }

    int sum = 2;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            sum += arr[i][j];
        }
    }

    cout << sum;
  

//    cout << "미세먼지 확산후 출력\n";
//    // 출력
//    for(int i = 0; i < r; i++){
//         for(int j = 0; j < c; j++){
//             cout << arr[i][j] << " ";
//         }
//         cout << "\n";
//    }



    return 0;
}