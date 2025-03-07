#include <bits/stdc++.h>
#define MAX 100000
using namespace std;

/*
문제 해결 사고 과정
나이브하게 생각했을때 , 브루트 방식으로 하면 시간 복잡도는 O(NM) -> 10^9승인데 1초에 해결되지 않음 
정렬 후 , 완전탐색 -> 얘도 시간초과 
정렬 후,  이분탐색-> O(NlogN + MlogN)으로 해결해야지 해결 

알게 된 사실 
-  1초에 10^8승 계산할 수 있다고 생각.

이분탐색 구현 - 처음 아이디어  
1. 정렬
2. 시작인데스, 기준인덱스, 끝인덱스 
3. 찾을때까지 반복수행 st <= en mid = (st + en)/2
3.1 arr[기준 index] < 찾는 값 -> 시작점 조정 st = mid + 1
3.2 arr[기준 index] == 찾는 값 
3.3 arr[기준 index] > 찾는 값 -> 끝점 조정 en = mid - 1
*/

int arr[MAX + 1];
int n;
bool binarySearch(int target){

    int st = 0;
    int en = n - 1;

    while(st <= en){
        int mid = (st+en)/2;
        if(arr[mid] < target){
            st = mid + 1;
        }
        else if(arr[mid] > target){
            en = mid - 1;
        }
        else return 1;

       
    }

    return 0;
    

}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int m;

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    sort(arr, arr + n);

    cin >> m;
    for(int i = 0; i < m; i++){
        int tar;
        cin >> tar;
        cout << binarySearch(tar) << "\n";
    }




    


    return 0;
}