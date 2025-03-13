#include <bits/stdc++.h>

using namespace std;


int res_1 = 0; int res_2 = 0; int res_3 = 0;
int maps[2200][2200];

bool check(int n, int row, int col){  // n과 시작점이 주어질때, 9등분 했을때 그 특정구역의 원소가 다 같은지
    int start  = maps[row][col];
    for(int i = row; i <  row + n ; i++){
        for(int j = col; j < col + n ; j++){
            if(start != maps[i][j])  return 0;
        }
    }

    return 1;
}


void divide(int n, int row, int col){
    // 모든 구간의 원소가 같다면 9개의 요소를 하나로 압축
    if(check(n, row, col)){
        if(maps[row][col] == -1) res_1 ++;
        else if(maps[row][col] == 0) res_2++;
        else if(maps[row][col] == 1) res_3++;
    }
    else{
        // 9개로 나누기 , 9등분의 시작점 넣기
        int sz = n / 3;
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                divide(sz, row + sz * i  , col +sz * j );
            }
        }
    }

}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n; 
    cin >> n;

    //memset(maps, 0, sizeof(maps));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> maps[i][j];
        }
    }

    divide(n, 0, 0);

    cout << res_1 << "\n";
    cout << res_2 << "\n";
    cout << res_3 ;
    return 0;
}