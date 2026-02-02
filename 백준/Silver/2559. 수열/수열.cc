#include <bits/stdc++.h>

using namespace std;

int N, K;

int a[100001];
int p[100001];

int answer = INT_MIN;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> K;
    for(int i = 1; i <= N; i++){
        cin >> a[i];
        p[i] = p[i - 1] + a[i];
    }

    
    
    // for(int i = 1; i <= N - K + 1; i++){
    //     int st = i;
    //     int ed = st + K;
    //     //cout << "end : " << ed << endl;
    //     answer = max(answer, p[ed] - p[st]);
    //     //cout << "answer : " << answer << endl;
    // }

    // 끝을 기준으로 
    for(int i = N; i >= K; i--){
        int end = i;
        int st = end - K;
        answer = max(answer, p[end] - p[st]);
    }

    cout << answer;

    return 0;
}
// 예외 발생 N = 2, K = 2일때 예외 발생 