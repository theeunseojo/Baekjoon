#include <bits/stdc++.h>

using namespace std;

int square(int n){
    return n * n;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);


    int arr[3];

    while(cin >> arr[0] >> arr[1] >> arr[2]){
        sort(arr, arr + 3);
        if(arr[0] == 0 && arr[1] == 0 && arr[2] == 0) break;
        if(square(arr[2]) == square(arr[0]) + square(arr[1])) cout << "right" << "\n";
        else cout << "wrong" << "\n";
    }
    return 0;
}