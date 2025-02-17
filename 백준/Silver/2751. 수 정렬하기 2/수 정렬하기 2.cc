#include <bits/stdc++.h>
#define MAX 2000001
using namespace std;
int arr[MAX];
int num[MAX];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> arr[i];
        num[arr[i] + (MAX/2)]++;
    }

    for(int i = 0; i < MAX; i++){
        if(num[i] > 0){
            cout << i - (MAX/2) << '\n';
        }
    }
    return 0;
}