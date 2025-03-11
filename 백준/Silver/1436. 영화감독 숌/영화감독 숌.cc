#include <bits/stdc++.h>

using namespace std;

int ans(int n){
    for(int i = 666; ; i++){
        // 666부터 시작해서 6이 3개인걸 찾는다

        if(to_string(i).find("666") != -1) n--; // 찾을 경우, n 하나씩 감소
        if(!n) return i; // n = 0일 경우, 원하는 값 리턴

    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;

    cout << ans(n);


    return 0;
}