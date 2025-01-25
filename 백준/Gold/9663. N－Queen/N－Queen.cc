#include <bits/stdc++.h>
#define MAX 16
using namespace std;



bool visited1[MAX];
bool visited2[2 * MAX]; // x + y
bool visited3[2 * MAX]; // x - y + ( n - 1) 음수 Indexing을 피하기 위해서

int n;
int cnt = 0;
void func(int row){
    // row은 n행까지의 경우의 수를 방문한 함수 , 즉 n개까지의 퀸을 배치한 함수 
    // 행이 같은지, 열이 같은지 대각선이 겹치는지를 제외하고 방문해야함.
    // 0 indexing 

    if(row == n){
        cnt++;
        return;
    }
    for(int i = 0; i < n; i++){ // 열 
        if(visited1[i] || visited2[row + i] || visited3[row - i + n - 1]) continue;
        visited1[i] = 1;
        visited2[row + i] = 1;
        visited3[row - i + n - 1] = 1;
        func(row + 1);
        visited1[i] = 0;
        visited2[row + i] = 0;
        visited3[row - i + n - 1] = 0;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    func(0);
    cout << cnt;

    return 0;
}