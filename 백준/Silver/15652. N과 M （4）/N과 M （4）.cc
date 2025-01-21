#include <bits/stdc++.h>

using namespace std;

int n, m;
int arr[10];
bool visited[10];

void func(int s, int k){
    if(k == m){
        for(int i = 0; i < m; i++){
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return ;
    }

    for(int i = s; i <= n; i++){
        arr[k] = i;
        visited[i] = 1;
        func(i, k + 1);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;

    func(1, 0);


    return 0;
}