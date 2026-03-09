#include <bits/stdc++.h>

using namespace std;

bool isBalance(string str){
    stack<char> st;
    for(int i = 0; i < str.size(); i++){
        if(str[i] != '(' && str[i] != ')' && str[i] != '[' && str[i] != ']') continue;
        else{
            if(st.size() == 0) st.push(str[i]);
            else{
                if(st.top() == '(' && str[i] == ')') st.pop();
                else if(st.top() == '[' && str[i] == ']') st.pop();
                else st.push(str[i]);
            }
        }
        
    }

    if(st.size() == 0) return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    while(true){
        string s;
        getline(cin, s);
        if(s == ".") break;

        if(isBalance(s)) cout << "yes\n";
        else cout << "no\n";
    }

    return 0;
}