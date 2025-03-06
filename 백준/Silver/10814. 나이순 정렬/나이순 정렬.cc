#include <bits/stdc++.h>
using namespace std;

vector <pair<int, string>> customers;

// pair는 stable sort 보장이 아니라 사전순 정렬을 보장
// stable sort 사용시, compare 함수 사용해야함.
bool compare(pair <int, string> person1, pair <int, string> person2){
    return person1.first < person2.first;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;



    for(int iter = 0; iter < n; iter++){
        int age;
        cin >> age;
        string name;
        cin >> name;
        customers.push_back({age, name});
    }

    stable_sort(customers.begin(), customers.end(), compare);
    for(int iter = 0; iter < n; iter++){
        cout << customers[iter].first << " ";
        cout << customers[iter].second << "\n";
    }
    return 0;
}