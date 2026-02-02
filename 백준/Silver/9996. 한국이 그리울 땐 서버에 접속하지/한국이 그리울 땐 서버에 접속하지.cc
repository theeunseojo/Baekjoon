#include <bits/stdc++.h>
using namespace std;

int N;
string reg;
vector<string> v;
vector<string> v2;

vector<string> split (const string& input, string delimiter){
    vector<string> result;
    auto start = 0;
    auto end = input.find(delimiter);
    while(end != string :: npos){
        result.push_back(input.substr(start, end - start));
        start = end + delimiter.size();
        end = input.find(delimiter, start);
    }
    result.push_back(input.substr(start));
    return result;
}

string isMatch(string str){
    //  prefix 길이만큼 prefix 랑 일치
    //  suffix 길이만큼 suffix 랑 일치
    string prefix = v[0];
    string suffix = v[1];
    // 예외처리
    if(prefix.size() + suffix.size() > str.size()){
        return "NE";
    }
    if(prefix == str.substr(0, prefix.length()) && suffix == str.substr(str.length() - suffix.length())){
        return "DA";
    }
    return "NE";
}
int main(){

    cin >> N;
    cin >> reg;
    // split -> prefix , suffix 
    v = split(reg, "*");
    for(int i = 0; i < N; i++){
        string str;
        cin >> str;
        v2.push_back(str);
    }

    // 출력
    for(string str : v2){
        cout << isMatch(str) << "\n";
    }
    return 0;
}

// 예외 발생상황 
// 만약 abcd * ~~ 패턴 주어지고, abc가 주어졌다면?