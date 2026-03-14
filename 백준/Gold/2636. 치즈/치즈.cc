#include <bits/stdc++.h>

using namespace std;

int y, x;
bool visited[105][105];
int a[105][105];
int last_cnt;
vector<pair<int,int>> cheese;

int dy[4] = {0, -1, 0, 1};
int dx[4] = {1, 0, -1, 0};

queue<pair<int,int> > q;

vector<int> cnt;

int t = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);


    cin >> y >> x;

    
    for(int i = 0; i < y; i++){
        for(int j = 0; j < x; j++){
            cin >> a[i][j];
            if(a[i][j] == 1) last_cnt++;
        }
    }

    
   cnt.push_back(last_cnt);

    while(1){
        
        // cout << "stime : " << stime << "\n";
        // 초기화
        cheese.clear();
        fill(&visited[0][0] , &visited[0][0] + 105 * 105, 0);
        q.push({0,0});
        visited[0][0] = 1;
       

        while(!q.empty()){   
            pair<int,int> curr = q.front();
            q.pop();
            
            for(int i = 0; i < 4; i++){
                int ny = curr.first + dy[i];
                int nx = curr.second + dx[i];

                if(ny < 0 || ny >= y || nx <  0 || nx >= x) continue;
                if(visited[ny][nx]) continue;
                if(a[ny][nx]){
                    // cout << "치즈의 겉 표면 ny : " << ny << ", nx : " << nx << "\n";
                    cheese.push_back({ny, nx});
                    visited[ny][nx] = 1;
                }
                else{
                    visited[ny][nx] = 1;
                    q.push({ny, nx});
                }
            }
        }

       
       
        // 지우기
        while(!cheese.empty()){
            auto curr = cheese.back();
            cheese.pop_back();
            a[curr.first][curr.second] = 0;
        }

        t++;
        // cheese check 
        last_cnt = 0;
        for(int i = 0; i < y; i++){
            for(int j = 0; j < x; j++){
                if(a[i][j] == 1) last_cnt++;
            }
        }
        
        cnt.push_back(last_cnt);
        if(last_cnt == 0) break;

    }
   

    cout << t << "\n";
    if(t == 1) cout << cnt[0];
    else cout << cnt[t - 1];
    
    
   
    
    return 0;
}