#include <iostream>
#include <string>
using namespace std;


int pow(int n){
    int val = 1;
    while(n--) val *= 3;
    return val;
}
void drawing(int n){
    if(n == 0) {
        cout << "-";
        return;
    }
    drawing(n - 1);
    for(int i = 0; i < pow(n-1); i++)
        cout << " ";
    drawing(n - 1);
}

int main()
{
   

    int n;
    
    while (cin >> n) {
		drawing(n);
        cout << "\n";
    }
    return 0;
}

