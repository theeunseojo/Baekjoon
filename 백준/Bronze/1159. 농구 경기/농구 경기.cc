#include <bits/stdc++.h>

using namespace std;

int a[26];
vector<char> v;
int N;
string temp;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> temp;
        a[temp[0] - 'a']++;
    }


    for(int i = 0; i < 26; i++){
        if(a[i] >= 5){
            v.push_back('a' + i);
        }
    }

    if(v.size() == 0){
        cout << "PREDAJA";
        return 0;
    }
    for(char ch : v){
        cout << ch;
    }

    return 0;
}