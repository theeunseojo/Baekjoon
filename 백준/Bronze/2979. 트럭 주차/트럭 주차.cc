#include <bits/stdc++.h>

using namespace std;

int a[100];
int A, B, C;
int start, ed;
int total[3];

void count(int start, int ed){
    for(int i = start; i < ed; i++){
        a[i]++;
    }
}
int calc(){
    int sum = 0;
    for(int i = 0; i < 100; i++){
        for(int j = 0; j < 3; j++){
            if(a[i] == j + 1){
                sum += a[i]  * total[j];
            }
        }
    }
    return sum;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);


    cin >> total[0] >> total[1] >> total[2];

    for(int i = 0; i < 3; i++){
        cin >> start >> ed;
        count(start, ed);
    }

    cout << calc();



    return 0;
}