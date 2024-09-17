#include <iostream>
#include <string>
#include <stack>
#define MAX 101
using namespace std;

int main(){
   int n;
   cin >> n;
   int cnt = 0;

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
            //ch != top인 경우, push
            if(ch != st.top()) st.push(ch);
            // 같을 경우, pop 시킨다.
            else st.pop();
         }
      }
      // 단어를 검사했는데, 스택이 비어 있는 경우 좋은 단어이므로 카운팅해준다. 
      if(st.empty()) cnt++;
   }
   cout << cnt;
   return 0;
}