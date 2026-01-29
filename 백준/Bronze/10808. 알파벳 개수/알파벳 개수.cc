#include <bits/stdc++.h>

using namespace std;

int a[26];

void print(){
    for(int i = 0; i < 26; i++){
        cout << a[i] << " ";
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string str;
    cin >> str;

    for(int i = 0; i < str.length(); i++){
        a[str[i] - 'a']++;
    }

    print();
    return 0;
}