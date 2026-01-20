#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> adj[20001]; 
int V, E;
int K;
const int INF =  1e9;
int d[20001];

void dijkstra(int start){
    // 방문 전 초기화
    fill(d, d + 20001, INF);

    priority_queue<pair<int,int>, vector <pair<int,int>>, greater<pair<int,int>>> pq;
    // 출발
    d[start] = 0;
    pq.push({0, start}); // 비용, 노드번호
    
    // 반복
    while(!pq.empty()){
        // 큐에서 최단거리 정보 꺼내기 
        int dist = pq.top().first;
        int now = pq.top().second;
        pq.pop();

        // 큐에서 꺼낸 최단거리 > 기록된 최단거리 : 무시
        if(dist > d[now]) continue;

        // 현재 노드와 연결된 다른 인접한 노드 확인
        for(int i = 0; i < adj[now].size(); i++){
            int next_node = adj[now][i].first;
            int next_dist = adj[now][i].second;

            int new_dist = dist + next_dist;
            
            // 최소값 갱신
            if(new_dist < d[next_node]){
                d[next_node] = new_dist;
                pq.push({new_dist, next_node});
            }
        }

    }
}
int main(){
    
    cin >> V >> E >> K;

    for(int i = 0; i < E; i++){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
    }

    dijkstra(K);

    for(int i = 1; i <= V; i++){
        if(d[i] == INF) cout << "INF\n";
        else cout << d[i] << "\n";
    }
    
    return 0;
}