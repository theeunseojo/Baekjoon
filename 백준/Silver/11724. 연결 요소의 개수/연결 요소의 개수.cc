#include <iostream>
#include <queue>
#include <vector>
#define MAX 1000
using namespace std;


vector <int> adj[MAX];
vector <bool> visited;
int n, m;


void dfs(int vertex){
	visited[vertex] = true;
	for(int next:adj[vertex]){
		if(!visited[next]){
			dfs(next);
		}
	}
}

int getComponent(){
	int cnt = 0;
	fill(visited.begin(), visited.end(), false);
	for(int i = 1; i <= n; i++){
		if(!visited[i]){
			dfs(i);
			cnt++;
		}
	}
	return cnt;
}

int main(){

	cin >> n >> m;
	visited.resize(n);
	for(int i = 0; i < m; i++){
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	cout << getComponent();

	return 0;
}