#include <iostream>
#include <string>
using namespace std;

int main(){
   // input alpabet.
   int alp[26] = {0,};
   for(int i = 0; i < 26; i++){
      alp[i] = -1;
   }

   // input 
   string s;
   cin >> s;
   for(int i = 0; i < s.length(); i++){
      int num = (int)s[i] - (int)'a';
      if(alp[num] != -1) continue;
      else alp[num] = i;
   }

   // print
   for(int i = 0; i < 26; i++){
      cout << alp[i] << " ";
   }
   return 0;
}