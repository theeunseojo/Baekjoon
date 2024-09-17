#include <iostream>
#include <string>
#include <stack>
#define MAX 101
using namespace std;

int main(){
   int n;
   cin >> n;

   string str[MAX];
   
   for(int i = 0 ; i < n; i++){
      cin >> str[i];
   }

   for(int i = 0 ; i < n; i++){
      stack<char> st;
      for(int j = 0; j < str[i].length(); j++){
         char ch = str[i][j];
         // 스택이 비어있는 초기상황이거나 유사한 경우(스택이 앞에서 짝 지어졌을때), push.
         if(st.empty()) st.push(ch);
         // 초기상황이 아닌 경우.
         else{
            //ch == top인 경우 이거나  열린괄호인 경우 push.
            if(ch == st.top() || ch == '(') st.push(ch);
            // 다를 경우, pop 시킨다.
            else st.pop();
         }
      }
      // 문자를 다 검사후, 스택이 비어있으면 괄호문자열 아니면 단순 문자열 
      if(st.empty()) cout << "YES\n";
      else cout << "NO\n";
   }
   return 0;
}