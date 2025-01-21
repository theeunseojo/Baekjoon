#include <bits/stdc++.h>

using namespace std;

int n;
int tshirts[6];
int t, p;

int ans_t = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for(int i = 0; i < 6; i++){
        cin >> tshirts[i];
    }
    cin >> t >> p;

    
    for(int i = 0; i < 6; i++){
        if(tshirts[i] == 0) continue;
        else if(tshirts[i] % t == 0) ans_t += tshirts[i] / t; 
        else if(tshirts[i] > 0 && tshirts[i] < t) ans_t++;
        else if(tshirts[i] > 0 && tshirts[i] > t){
            ans_t += (tshirts[i] / t) + 1;
        }
    }

    cout << ans_t << '\n';
    cout << n / p << ' '<< n % p;
    return 0;
}