#include <bits/stdc++.h>

using namespace std;

string str;

string rot13(string str){
    string answer = "";
    for(int i = 0; i < str.length(); i++){
        if(str[i] >= 'A' && str[i] <= 'Z'){
            answer += (str[i] - 'A' + 13) % 26 + 'A';
        }
        else if(str[i] >= 'a' && str[i] <= 'z'){
            answer += (str[i] - 'a' + 13) % 26 + 'a';
        }
        else{
            answer += str[i];
        }
        
    }
    return answer;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    getline(cin, str);
    
    

    cout << rot13(str);

    return 0;
}