#include <bits/stdc++.h>
#define MAX  1000000
using namespace std;


int a[MAX + 1];
int b[MAX + 1];
int n, m;
int arr[2 * MAX + 1];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);


    
    cin >> n >> m;

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int j = 0; j < m; j++){
        cin >> b[j];
    }

    int aidx = 0;
    int bidx = 0;

    for(int i = 0; i < n + m; i++){
      if(aidx == n) arr[i] = b[bidx++];
      else if(bidx == m) arr[i] = a[aidx++];
      else if(a[aidx] <= b[bidx]) arr[i] = a[aidx++];
      else arr[i] = b[bidx++];
    }


    for(int i = 0; i < n + m; i++) cout << arr[i] << ' ';




    return 0;
}