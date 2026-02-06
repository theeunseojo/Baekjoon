#include <bits/stdc++.h>

using namespace std;

// headgear 2종류, eyeware 1종류 -> 2종류중 하나 + 1종류 + 2종류중하나선택 * 1종류
// 종류별 하나식이니깐 hashmap으로 해서 {종류 : 옷의갯수} 으로 계산
// 각 종류마다 탐색 -> size 구하기 

int N, M;
string name, cloth;

vector<int> ans;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> M;
        map<string,int> mp;
        // map 
        for(int i = 0; i < M; i++){
            cin >> name >> cloth;
                if(mp[cloth] == 0){
                    mp[cloth] = 1;
                }
                else{
                    mp[cloth]++;
                }
        } 
        
        int mul = 1;
        for(auto it : mp){
            mul *= (it.second + 1);
        }

        ans.push_back(mul - 1);
    }

    for(int v : ans){
        cout << v << "\n";
    }
   
    return 0;
}