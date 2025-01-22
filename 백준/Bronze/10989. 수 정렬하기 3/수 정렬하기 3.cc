#include <bits/stdc++.h>
#define MAX 10001
using namespace std;

int arr[MAX];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        int num;
        cin >> num;

        arr[num]++;
    }

    for(int i = 1; i <= 10000; i++){
        if(arr[i] > 0){
            while(arr[i] > 0){
                arr[i]--;
                cout << i << '\n';
            }
        }
    }

    return 0;
}