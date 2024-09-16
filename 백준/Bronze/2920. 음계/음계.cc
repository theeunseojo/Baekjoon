/* run code 가 코드러너로 돌리는 것임.*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
   int a[8] = {};
   for(int i = 0; i < 8; i++){
      cin >> a[i];
   }


   int ans = -1;
   for(int i = 1; i < 7; i++){
      if(a[i - 1] < a[i] && a[i] < a[i + 1]) ans = 0;
      else if(a[i - 1] > a[i] && a[i] > a[i + 1]) ans = 1;
      else {
         ans = 2;
         break;
      }
   }
   if(ans == 0) cout << "ascending";
   else if(ans == 1) cout << "descending";
   else cout << "mixed";
   return 0;
}
