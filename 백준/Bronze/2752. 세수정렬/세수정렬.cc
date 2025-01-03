#include <iostream>
using namespace std;

int main(){
    int arr[3];
    for(int i = 0; i < 3; i++){
        cin >> arr[i];
    }

    for(int i = 0; i < 3; i++){
        for(int j = 1; j < 3; j++){
            if(arr[j - 1] > arr[j]) swap(arr[j - 1], arr[j]);
        }
    }
    
    for(int i = 0; i < 3; i++){
        cout << arr[i] << " ";
    }
    
    
    return 0;
}