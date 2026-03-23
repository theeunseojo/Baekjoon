#include <bits/stdc++.h>

using namespace std;

int n, m, cnt;

vector<int> adj[10005];
int visited[10005];

vector<pair<int,int> > v;


// first : 현재노드 , second : 카운팅
bool compare(const pair<int,int> &a, const pair<int,int> &b){
    if(a.second == b.second){
        return a.first < b.first;
    }

    return a.second > b.second;
}

// 몇개를 전파를 시킬 수 있는가
int dfs(int here){
   
    int ret = 1;
    visited[here] = 1;

    if(adj[here].size() == 0) {
        return 1;
    }

    for(int there : adj[here]){
        if(visited[there]) continue;
        visited[there] = 1;
        ret += dfs(there);   
    }

    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;

    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        // if(a == b) continue;

        adj[b].push_back(a);
    }
    
    for(int root = 1; root <= n; root++){
        memset(visited, 0, sizeof(visited));
        v.push_back({root, dfs(root)});
    }

    // 정렬 -> 카운팅이 높은순으로, 카운팅이 같다면 컴퓨터 번호 오름차순 

    sort(v.begin(), v.end(), compare);
    
    int cnt_max = v[0].second;
    for(auto it : v){
       if(cnt_max == it.second) cout << it.first << " ";
    }
    return 0;
}