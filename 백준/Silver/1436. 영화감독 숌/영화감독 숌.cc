#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;
    int ans;
    for(int i = 666; ; i++){
        if(to_string(i).find("666") != -1) n--;
        ans = i;
        if(n == 0) break;
    }

    cout << ans;
    return 0;
}
