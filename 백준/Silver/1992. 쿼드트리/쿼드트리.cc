#include<bits/stdc++.h>
#define MX 65
using namespace std;

int n;
int a[MX][MX];

// 정사각형을 사등분한다.
// 괄호를 시작한다.
// 전체가 하나의 숫자로 이루어질 경우 하나의 숫자를 출력한다.
// 아닐 경우 , 왼쪽상단, 오른쪽상단, 왼쪽하단, 오른쪽하단을 확인한다.
// 괄호를 닫는다.

bool isOne(int y, int x, int len){
    int st = a[y][x];
    for(int i = y; i < y + len; i++){
        for(int j = x; j < x + len; j++){
            if(st != a[i][j]) return false;
        }
    }
    return true;
}

void quad(int y, int x, int len){
    
    if(isOne(y, x, len)){
        cout << a[y][x];
    }
    else{
        cout << "(";
        // 왼쪽 상단
        quad(y, x, len/2);
        // 오른쪽 상단
        quad(y, x + len/2, len/2);
        // 왼쪽 하단
        quad(y + len/2, x, len/2);
        // 오른쪽 하단
        quad(y + len/2, x + len/2, len/2);
        cout << ")";
    }
   
}
int main(){
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%1d", &a[i][j]);
        }
    }

    quad(0 ,0, n);
    
    return 0;
}