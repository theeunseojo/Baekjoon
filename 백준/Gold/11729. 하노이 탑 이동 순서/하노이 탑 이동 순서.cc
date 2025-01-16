#include <bits/stdc++.h>

using namespace std;


void func(int a, int b, int n){ // n개를 a에서 b로 옮긴다.
    if(n == 0) return;
    func(a, 6 - a - b, n - 1);
    cout << a << ' ' << b << '\n';
    func(6-a-b, b, n -1 );
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;
    cout << (1 <<  n) - 1 << '\n';
    func(1, 3, n);
    return 0;
}