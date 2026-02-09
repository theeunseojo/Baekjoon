#include <bits/stdc++.h>

using namespace std;

string s;
int alp[26];
int odd;

bool isPeli(){
    int cnt = 0;
    for(int t : alp){
        if(t % 2 != 0) cnt++;
    }

    if(cnt == 0 || cnt == 1) return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> s;

    for(char ch : s){
        alp[ch - 'A']++;
    }


    if(isPeli()){
        string s = "";
        string mid = "";
        // prefix
        // mid
        // suffix
        for(int i = 0; i < 26; i++){
            if(alp[i] % 2 == 1){
                mid = 'A' + i;
            }
            
            for(int j = 0; j < alp[i] / 2; j++){
                s += ('A' + i);
            }
            
        }

        cout << s << mid;
        reverse(s.begin(), s.end());
        cout << s;
    }
    else{
        cout << "I'm Sorry Hansoo";
    }

    return 0;
}