#include<bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for(int i = 0; i < commands.size(); i++){
        int st = commands[i][0] - 1;
        int ed = commands[i][1] - 1;
        int k = commands[i][2] - 1;
        vector<int> temp;
        
        // 원소 st ~ ed까지 삽입
        for(int j = st; j <= ed; j++){
            temp.push_back(array[j]);
        }
        
        // 정렬
        sort(temp.begin(), temp.end());
        
        // k 번째 수 삽입
        answer.push_back(temp[k]);
    }
    return answer;
}