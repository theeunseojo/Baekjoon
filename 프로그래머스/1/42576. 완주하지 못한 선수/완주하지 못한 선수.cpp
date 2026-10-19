#include<bits/stdc++.h>

using namespace std;

// 동명이인이 결국 이 문제의 핵심이라고 직관이 들음
// 12:23분 시작 

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    // 참여자들 string and count
    map<string,int> list;
    
    for(string st : participant){
        list[st]++;
    }
    
    // 완주자 목록에서 제거 
    for(string st : completion){
        list[st]--;
    }
    
    // list 에서 아직도 1인 사람이 완주 못한 사람 
    // map 에서 자료구조를 어떻게 꺼낼것인가 -> cpp 공식문서 참고해보자 일단 순간 생각난 auto로 그리고 어디선간 생각난 first / second 생각 해냄 .. (index -> first/second 공식문서 안봄)
    for(auto li : list){
        string name = li.first;
        int cnt = li.second;
        
        if(cnt == 1) answer = name;
    }
    return answer;
}