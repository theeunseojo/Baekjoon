#include <iostream>
#include <queue>
using namespace std;

int main(){
   int n;
   cin >> n;

   queue<int> q;
   // 카드 순서대로 배열하기.
   for(int i = 1; i <= n; i++){
      // 초기상황이므로
      q.push(i);
   }

   while(q.size() != 1){
      if(q.empty()) break;
      else{
         // 위에 있는 카드를 버린다. 
         q.pop();
         // 위에 있는 카드를 넣는다.
         q.push(q.front());
         q.pop();
      }
   }
   
   cout << q.front();
   return 0;
}
