#include <bits/stdc++.h>
#define MAX 1000000
using namespace std;

int arr[2 * MAX + 1];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);


    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        arr[num + MAX]++;
    }

    for(int i = 0; i <=2 * MAX ; i++){
        while(arr[i]--){
            cout << i - MAX << "\n";
        }
    }
    return 0;
}