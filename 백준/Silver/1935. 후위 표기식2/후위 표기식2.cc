#include <iostream>
#include <cmath>
#include <stack>
#include <string>
using namespace std;

int main(){

   // input
   int n;
   cin >> n;
   stack <double> st;
   double sum = 0.0;   // 연산 결과 저장 변수
   double arr[27] = {};

   string s;
   cin >> s;

   for(int i = 0; i < n; i++){
      cin >> arr[i];
   }
   
   for(int i = 0; i < s.length(); i++){
      // 피연산자일 경우, stack push.
      if('A' <= s[i] && s[i] <= 'Z'){
         int idx = (int)s[i] - 'A'; 
         st.push(arr[idx]);
      }
      // 연산자일 경우, 스택에 있는 값들을 계산하여 다시 push.
      else{
         double b = st.top();
         st.pop();
         double a = st.top();
         st.pop();
         if(s[i] == '+') sum = a + b;
         else if(s[i] == '-') sum = a - b;
         else if(s[i] == '*') sum = a * b;
         else sum = a / b;
         st.push(sum);
         
      }
   }

   // 출력 
   cout<<fixed;
   cout.precision(2);
   cout << st.top();
   return 0;
}