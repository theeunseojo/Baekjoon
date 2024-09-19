#include <iostream>
#include <algorithm>
using namespace std;

int main(){
   int arr[9] = {0, };
   int arr2[2] = {0, };
   int sum = 0;
   for(int i = 0; i < 9; i++){
      cin >> arr[i];
      sum += arr[i];
   }

   sort(arr, arr + 9);
   for(int i = 0; i < 9; i++){
      for(int j = i + 1; j < 9; j++){
         if(sum - (arr[i] + arr[j]) == 100){
            arr2[0] = i;
            arr2[1] = j;
            break;
         }
         
      }
   }
   
   for(int i = 0; i < 9; i++){
      if(i == arr2[0] ||  i == arr2[1]) continue;
      else cout << arr[i] << endl;
   }
   return 0;
}