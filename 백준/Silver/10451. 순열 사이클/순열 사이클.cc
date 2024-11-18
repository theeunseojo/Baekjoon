#include <iostream>
#include <vector>
#define MAX 1001
using namespace std;

int T, N;
bool visited[MAX];
vector <int> graph[MAX];

void dfs(int vertex){
    if(visited[vertex] == true) return;
    else{   // 방문했을 경우 
        // 1. 방문처리 
        visited[vertex] = true;
        // 2. 다음 노드 방문
        int next = graph[vertex][0];
        if(!visited[next]) dfs(next);

    }
}

int main(){
    int T, N, vertex, cnt;
    cin >> T;
    for(int i = 0; i < T; i++){     // test case만큼 순열 입력
        cin >> N;
        // 초기화
        cnt = 0;
        for(int i = 1; i <= N; i++){
            graph[i].clear();
            visited[i] = false;
        }
        // 입력
        for(int j = 1; j <= N; j++){
            cin >> vertex;
            graph[j].push_back(vertex);
        }
        // 탐색 시작
        for(int j = 1; j <= N; j++){
            if(visited[j] == false){
                dfs(j);
                cnt++;
            }
        }
        cout << cnt << endl;
    }

   
    
    return 0;
}