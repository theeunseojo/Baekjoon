#include <iostream>
using namespace std;

int main(){

    for(int i = 0; ; i++){
        int l, p ,v , day;
        for(int i = 0; ; i++){
            cin >> l >> p >> v;
            if(l == 0 && p == 0 && v == 0) return 0;
            if(v % p > l) day = l * (v / p) + l;
            else day = l * (v / p) + (v % p);
            cout << "Case " << (i + 1) << ": " << day << "\n";
        }
    }

    
    return 0;
}