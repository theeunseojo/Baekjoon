#include<bits/stdc++.h>
using namespace std;

int n,c;

struct p{
    int num;
    int st;
    int cnt;
};

bool cmp(const p & a, const p &b){
    if(a.cnt == b.cnt) return a.st < b.st;
    return a.cnt > b.cnt;
}

map<int,int> cnt_mp;
map<int,int> loc_mp;
vector<p> v;
int arr[1001];

int main(){
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> c;

    for(int i = 0; i < n; i++){

        cin >> arr[i];
        if(cnt_mp.find(arr[i]) == cnt_mp.end() && loc_mp.find(arr[i]) == loc_mp.end()){
            cnt_mp[arr[i]] = 1;
            loc_mp[arr[i]] = i;
            continue;
        }
        cnt_mp[arr[i]]++; 
    }

    for(int i = 0; i < n; i++){
        int num = arr[i];
        v.push_back({num, loc_mp[num], cnt_mp[num]});
    }

    sort(v.begin(), v.end(), cmp);
    
    for(int i = 0; i < n; i++){
        cout << v[i].num << " ";
    }
    return 0;
}

