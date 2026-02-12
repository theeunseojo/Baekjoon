#include <bits/stdc++.h>

using namespace std;
long long A, B , C;

long long f(long long a, long long b, long long c) {
    if (b == 0) return 1;

    long long res = f(a, b / 2, c);

    res = (res * res) % c;
    
    // 홀수일경우
    if(b & 1) return (res * a) % c;
    return res;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> A >> B >> C;

    cout << f(A,B,C);

    return 0;
}