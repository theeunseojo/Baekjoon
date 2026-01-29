#include <bits/stdc++.h>

using namespace std;


bool isPel(string str){
    int end = str.length();
    for(int i = 0; i < str.length() / 2; i++){
        if(str[i] != str[end - i - 1]){
            return 0;
        }
    }
    return 1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string str;
    cin >> str;
    
    cout << isPel(str);


    return 0;
}