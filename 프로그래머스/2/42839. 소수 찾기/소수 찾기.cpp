#include<bits/stdc++.h>

using namespace std;
bool check(int n){
    if(n <= 1) return 0;
    if(n == 2) return 1;
    if(n % 2 == 0) return 0;
    for(int i = 3; i * i <= n; i++){
        if(n % i == 0) return 0;
    }
    return 1;
}
set<int> u;
void getNum(vector<int> & v){
    string ret;
    for(int i : v){
        ret += to_string(i);
        u.insert(stoi(ret));
    }
    return;
}


int solution(string numbers) {
    int answer = 0;
    // 수의 벡터로 변환
    vector<int> v;
    for(char num : numbers){
        v.push_back(num - '0');
    }
    sort(v.begin(), v.end());
    // 경우의수(순열)..
    do{
        getNum(v);
    }while(next_permutation(v.begin(), v.end()));
    
    for(int num : u){
        if(check(num)){
            answer++;
        }
    }
    return answer;
}