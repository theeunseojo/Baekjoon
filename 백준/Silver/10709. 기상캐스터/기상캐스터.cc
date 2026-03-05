#include <bits/stdc++.h>

using namespace std;

int h,w, idx;
int a[101][101];


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> h >> w;
    fill(&a[0][0], &a[h][w] , -1);

    for(int i = 0; i < h; i++){
        idx = -1;
        for(int j = 0; j < w; j++){
            char ch;
            cin >> ch;

            if(ch == 'c'){
                a[i][j] = 0;
                idx = j;
            }
            else{
                a[i][j] = idx == -1 ? -1 : j - idx;
            }
        }
    }


    // print
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }

    
    

    return 0;
}