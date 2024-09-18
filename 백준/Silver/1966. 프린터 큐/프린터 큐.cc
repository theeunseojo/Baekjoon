#include <iostream>
#include <cmath>
#include <queue>
#define MAX 101
using namespace std;

int GetPrority(int arr[]){
   int num = 0;
   for(int i = 1; i < 10; i++){
      if(arr[i] != 0) num = max(num, i);
   }
   return num;
}
int main(){
   int n;
   cin >> n;

   queue<int> q[MAX];
   int prority[MAX][10] = {0,};  // 중요도별로 문서 갯수 저장하는 배열.
   int pos[MAX] = {0,};  // 프린트 될때, pos도 같이 증가, 프린트 안될때는 감소. 
   int m;
   // 입력 
   for(int i = 0; i < n; i++){
      cin >> m >> pos[i];  

      for(int j = 0; j < m; j++){
         int pro;
         cin >> pro;
         prority[i][pro]++;
         q[i].push(pro);
      }
   }
   
   for(int i = 0; i < n; i++){
      int cnt = 0; // 몇번째로 프린트되는지 세는 변수.
      
      while(q[i].empty() == false){
         // 중요도가 높은게 없을 때
         int first = GetPrority(prority[i]);
         if(q[i].front() >= first){
            // 위치 + 1 ==  size일때, 원하는 위치 값이 출력 대기상태.
            if(pos[i] == 0) {
               cnt++;
               cout << cnt << "\n";
               break;
            }
            else{
               // 중요도가 제일 높은 문서이므로, 원하는 문서의 위치 옮겨주기, 프린트 카운팅해주기.
               q[i].pop();
               pos[i]--;
               prority[i][first]--;
               cnt++;
            }
         }
         // 중요도가 높은게 있을 때
         else if(q[i].front() < first){
            //문서를 큐에 다시 넣은 후, 원하는 문서 위치 변경.
            q[i].push(q[i].front());
            q[i].pop();
            if(pos[i] >= 0) pos[i]--;
            if(pos[i] < 0) pos[i] = q[i].size() - 1;
            
         }
         
      }
      
   }
   

   
   return 0;
}
