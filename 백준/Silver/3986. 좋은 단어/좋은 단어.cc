#include <bits/stdc++.h>

using namespace std;

int N;
stack<char> st;
int cnt;
bool isGood(string temp){
    
    for(int i = 0; i < temp.length(); i++){
        

        if(st.empty() || st.top() != temp[i]){
            //cout << "push : " << temp[i] << endl;
            st.push(temp[i]);
        }
        else if(!st.empty() && st.top() == temp[i]){
            // cout << "pop : " << st.top() << endl;
            st.pop();
        }
    }
    
    if(st.empty()) return true;
    else return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;

    for(int i = 0; i < N; i++){
        string temp;
        cin >> temp;

        while(!st.empty()){
            st.pop();
        }

        if(isGood(temp)){
            cnt++;
        }
    }

    cout << cnt;

    return 0;
}