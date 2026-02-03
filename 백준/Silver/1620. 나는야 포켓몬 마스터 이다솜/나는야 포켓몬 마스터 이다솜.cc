#include <bits/stdc++.h>

using namespace std;

map<string, int> mp;

int N, M;
string a[100002];
vector<string> v;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;
    
    for(int i = 0; i < N; i++){
        cin >> a[i + 1];
        mp.insert({a[i + 1], i + 1});
    }

    for(int i = 0; i < M; i++){
        string str;
        cin >> str;
        v.push_back(str);
    }

    for(string str : v){
        int num = atoi(str.c_str());

        // 문자열인경우
        if(num == 0){
            cout << mp[str] << "\n";
        }
        // 숫자인경우
        else{
            cout << a[num] << "\n";
        }
    }

    return 0;
}