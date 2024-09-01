#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {
    string input, output;
    istringstream ss;

    getline(cin, input);
    
    ss.str(input);
    int cnt = 0;
    while(ss>>output){
        cnt++;
    }
    cout << cnt;
    return 0;
}