#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int n;
vector <pair<int,int>> arr;
vector <pair<int,int>> temp;

void merge(int st, int en){
    int mid = (st + en) / 2;

    int lidx = st;
    int ridx = mid; 
    

    for(int i = st; i < en; i++){

        if(ridx == en) temp[i] = arr[lidx++]; // 왼쪽 정렬 

        else if(lidx == mid) temp[i] = arr[ridx++]; // 오른쪽 정렬 

        else if(arr[lidx].X <=  arr[ridx].X){ // x좌표 정렬 
            if(arr[lidx].X == arr[ridx].X){ //   y좌표 정렬 

                if(arr[lidx].Y < arr[ridx].Y) temp[i] = arr[lidx++];
                else temp[i] = arr[ridx++];
            }
            else temp[i] = arr[lidx++];
        }
        else temp[i] = arr[ridx++];
    }

    for(int i = st; i < en; i++) arr[i] = temp[i];
}

void merge_sort(int st, int en){
    if(en == st + 1) return;
    int mid = (st + en) / 2;
    // 좌측 정렬
    merge_sort(st, mid);
    // 우측 정렬 
    merge_sort(mid, en);
    // 통합
    merge(st,en);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;

    arr.resize(n);
    temp.resize(n);

    
    for(int i = 0; i < n; i++){
        cin >> arr[i].X >> arr[i].Y;
    }

    merge_sort(0, n);

    for(int i = 0; i < n; i++){
        cout << arr[i].X << " " << arr[i].Y << "\n";
    }
    return 0;
}