#include <bits/stdc++.h>

using namespace std;

int n, m, j;
int loc[21];
int cnt;
int curr;
bool isApple(int curr, int loc){
    int end = curr + m - 1;
    if(curr <= loc && loc <= end) return true;
    return false;
}

int dir(int curr, int loc){
    if(curr < loc) return 1;
    else if(curr > loc) return -1;
    else return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);


    cin >> n >> m;
    cin >> j;

    for(int i = 0; i < j; i++){
        cin >> loc[i];
    }


    curr = 1;

    // 이동 방향 결정
    // 획득할때까지 이동 
    for(int i = 0; i < j; i++){
        
        if(isApple(curr, loc[i])) continue;
        
        int d = dir(curr, loc[i]);
        while(!isApple(curr, loc[i])){
            curr += d;
            cnt++;
            //cout << "현재 위치는  : " << curr << ", 거리는 : " << cnt << endl;
        }
        
        
        
    }

    cout << cnt;
    return 0;
}