#include<bits/stdc++.h>
using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    multiset<int> ms;
    
    for(string s : operations){
        int data = stoi(s.substr(2));
        
        if(s[0] == 'I'){
            ms.insert(data);
        }
        else{
            if(ms.empty()) continue;
            
            if(data == 1){
                ms.erase(--ms.end());
            }
            else{
                ms.erase(ms.begin());
            }
        }
    }
    
    if(ms.empty()){
        answer.push_back(0);
        answer.push_back(0);
    }else{
        answer.push_back(*(--ms.end()));
        answer.push_back(*ms.begin());
    }
    return answer;
}