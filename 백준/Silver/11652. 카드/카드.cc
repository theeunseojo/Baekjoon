#include <bits/stdc++.h>
#define MAX 100000
using namespace std;

long long cards[MAX + 1];

/*
궁극적으로 음수이고 숫자가 너무 크기 때문에 배열 인덱스나 벡터로 관리해주기 보다는 여러가지 변수로 값을 관리하는 것이 더 좋음
1. 정렬 진행
2. 현재 가리키는 숫자의 카운팅 값을 이전값이랑 비교했을때 같으면 , cnt += 1
3. 아닐 경우 cnt = 1 로 초기화 , 현재 cnt 값이 mx_cnt보다 크면 그때 max_card_num이랑 mx_cnt 갱신 

딱히 중요한 내용 X
- max_card_num 은 가장 작은 값 - 1 으로 세팅 : -2^62 -1 = -(1ll << 62) 그냥 int로 하면 오버플로우가 나기 때문에 형변환를 해야한다.

논리적 오류 상황
이전과 달라지는 순간이 끝까지 안나오는 경우에는 처리를 못함
업데이트를 달라지는 순간에 하고 있는 것떄문에

그리고 최빈값을 작은순서대로 정렬해서 저장하는 것이기때문에 , 

*/

bool compare(long long a, long long b){
    return a > b;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;


    for(int i = 0; i < n; i++){ // 1부터 n까지 -> 0부터 n - 1까지
        cin >> cards[i];
    }

    sort (cards, cards + n, compare);

    int cnt = 1; // 현재 가리키는 숫자의 카운팅 값
    long long max_card_num = cards[0]; // 가장 많은 정수의 card_num
    int mx_cnt = 0; // 가장 많은 정수의 카운팅 값


    for(int i = 1; i < n; i++){  
        if(cards[i - 1] == cards[i]) cnt += 1; //같은 수의 카드가 나올때

        else{ // 다른 수의 카드가 등장했을때 (이전값과 달라지는 순간)
            if(cnt >= mx_cnt){ //이전의 최빈값 저장
                mx_cnt = cnt;
                max_card_num = cards[i - 1];
            }
            /*
            else if(cnt == mx_cnt){ // 또 변경되었을때, 이전의 최빈값과 이전의 값을 비교해야한다.
                max_card_num = min(max_card_num,cards[i - 1]);
            }
            */
            cnt = 1;
        }
        
    }

    // 이전과 달라지는 상황이 오지 않으면 끝까지 업데이트 안되는걸 해결해야함.
    if(cnt > mx_cnt) {
        mx_cnt = cnt;
        max_card_num = cards[n - 1];
    } else if(cnt == mx_cnt) {
        max_card_num = min(max_card_num, cards[n - 1]);
    }
    cout << max_card_num;

    return 0;
}