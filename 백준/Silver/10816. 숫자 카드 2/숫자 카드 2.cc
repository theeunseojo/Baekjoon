#include <bits/stdc++.h>
#define MAX 5000000
using namespace std;

/*
1. 완전탐색 -> 숫자가 너무 크므로 불가
2. count 정렬 -> 음수 index가 너무 커서 커버 부라
3. 정렬 후 이분탐색 진행 단순 이분탐색으로 구할 수 없다.
4. 이분 탐색 후 index를 반환한다면?
-> 문제는 이것도 O(NM)이라는 시간이 걸림 


해설
1. 특정 인덱스에 target을 삽입
->오름차순이 될 경우 가장 왼쪽이 시작, 가장 오른쪽 직전이 끝나는 지점
2. 오른쪽 - 왼쪽 인덱스 차이 = 등장횟수
왼쪽 index 오른쪽 index 다르게 찾아야지 갱신이 안된 초기의 값을 찾을 수 있다.


*/

int arr[MAX + 2];
int n;


int left_binarySearch(int target){

    int st = 0;
    int en = n;
    

    while(st < en){
        int mid = (st + en) / 2;
        if(arr[mid] >= target) en = mid;
        else st = mid + 1;
    }

    return st;

    
}

int right_binarySearch(int target){
    int st = 0;
    int en = n;
    
    while(st < en){
        int mid = (st + en) / 2;
        if(arr[mid] <= target) st = mid + 1;
        else en = mid;
    }
    return st;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    

    sort(arr, arr + n);
   

    int m;
    cin >> m;


    while(m--){
        int num;
        cin >> num;
        cout << right_binarySearch(num) - left_binarySearch(num) << " ";
    }
    return 0;
}