#include <iostream>
#include <cmath>
#include <algorithm>
#define MAX 50
using namespace std;

int n;
char arr[MAX][MAX];

int GetMax(int r, int c){
    int row_cnt = 1;
    int col_cnt = 1;
    int result;
    int row_result = 0;
    int col_result = 0;
    //행기준 의 사탕갯수 겹치지 않게 카운팅
    for(int i = 1; i < n; i++){
        if(arr[r][i - 1] != arr[r][i]){
            // 이전까지의 값중 연속된 최대 길이 저장.
            row_result = max(row_result, row_cnt);
            row_cnt = 1;

        }
        else row_cnt++;
    }
    // 행기준 최댓값 업데이트
    row_result = max(row_result,row_cnt);
    //열기준 의 사탕갯수 겹치지 않게 카운팅
    for(int i = 1; i < n; i++){
        if(arr[i - 1][c] != arr[i][c]){
            // 이전까지의 값중 연속된 최대 길이 저장.
            col_result = max(col_result, col_cnt);
            col_cnt = 1;

        }
        else col_cnt++;
    }
    // 열기준 최댓값 업데이트
    col_result = max(col_result,col_cnt);
    // 행의 최댓값과 열의 최댓값 비교
    result = max(row_result, col_result);
    return result;
}
int main(){
    int ans = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
        }
    }
    // ans 값 0행 0열의 움직이지 않은 초기 상태의 초깃값 설정.
    ans = 0;
    // 가장 좌측 블럭을 가지고 탐색.
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n - 1; j++){
            ans = max(ans, GetMax(i, j));
            // 우측값 비교.
            if(arr[i][j] != arr[i][j + 1]){
                swap(arr[i][j], arr[i][j + 1]);
                ans = max(ans, GetMax(i, j));
                // 바뀐쪽도 check.
                ans = max(ans, GetMax(i, j + 1));
                // 되돌리기
                swap(arr[i][j], arr[i][j + 1]);
            }
            // 위쪽 값 비교.
            if(arr[j][i] != arr[j+ 1][i]){
                swap(arr[j][i], arr[j + 1][i]);
                ans = max(ans, GetMax(j, i));
                // 바뀐쪽도 check.
                ans = max(ans, GetMax(j + 1, i));
                // 되돌리기
                swap(arr[j][i], arr[j + 1][i]);
                
            }
            
       
        }
    }

    cout << ans;
    return 0;
}

