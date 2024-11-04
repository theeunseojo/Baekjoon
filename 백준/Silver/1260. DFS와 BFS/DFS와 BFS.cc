#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 10000
using namespace std;

vector<int> graph[MAX + 1];
bool visited[MAX + 1];

void dfs(int vertex){
	visited[vertex] = true;
	cout << vertex << " ";

	for(int i : graph[vertex]){
		if(visited[i] == false) dfs(i);
	}
	
}

void bfs(int vertex){
	queue <int> q;
	visited[vertex] = true;
	q.push(vertex);

	while(!q.empty()){
		int temp = q.front();
		q.pop();
		cout << temp << " ";
		
		for(int i = 0; i < graph[temp].size(); i++){
			int y = graph[temp][i];
			if(!visited[y]){
				q.push(y);
				visited[y] = true;
			}
		}
	}

	
}

int main(){
	int n, m, v;
	cin >> n >> m >> v;
	for(int i = 0; i < m; i++){
		int x, y;
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);

	}
	for(int i = 1; i <= n; i++){
		sort(graph[i].begin(), graph[i].end());
	}
	dfs(v);
	cout << endl;
	fill(visited, visited + n + 1, false);
	bfs(v);
	return 0;
}