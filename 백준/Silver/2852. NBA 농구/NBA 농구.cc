#include <bits/stdc++.h>

using namespace std;

int n;

vector<string> split(const string& input , string delimiter){
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

int sc1, sc2;
int last;
int sc[2] = {0, 0};
int team;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;

    for(int i = 0; i < n; i++){
        int curr;
        string time;
        cin >> team;
        cin >> time;

        vector<string> tm = split(time,":");
        // 시간 총합 계산 
        curr = stoi(tm[0]) * 60 + stoi(tm[1]);

        if(sc1 > sc2){
            sc[0] += (curr - last);
        }
        else if(sc1 < sc2){
            sc[1] += (curr - last);
        }

        if(team == 1) sc1++;
        else sc2++;

        last = curr;
        
    }

    if(sc1 > sc2){
        sc[0] += (48 * 60) - last;
    }
    else if(sc1 < sc2){
        sc[1] += (48 * 60) - last;
    }


    for(int i = 0; i < 2; i++){
        int min = sc[i] % 60;
        int hour = sc[i] / 60;
        printf("%02d:%02d\n",hour,min);
    }

    return 0;
}