#include <iostream>
#include <string>
#define MAX 10001
using namespace std;

int arr[MAX] = {0, };
int cur = -1;
int len = -1;
void push(int x, int arr[]){
   cur++;
   arr[cur] = x;
   len++;
   
}
void pop(int arr[]){
   if(len == -1) cout << len << "\n";
   else{
      cout << arr[cur] << "\n";
      arr[cur] = 0;
      cur--;
      len--;
   }
}
void size(int arr[]){
   cout << len + 1 << "\n";
}
void empty(int arr[]){
   if(len == -1) cout << 1 << "\n";
   else cout << 0 << "\n";
}
void top(int arr[]){
   if(len == -1) cout << len << "\n";
   else cout << arr[cur] << "\n";
}
int main(){
   int cnt;
   cin >> cnt;

   for(int i = 0; i < cnt; i++){
      string cmd;
      cin >> cmd;
      if(cmd == "push"){
         int x;
         cin >> x;
         push(x,arr);
      }
      else if(cmd == "pop") pop(arr);
      else if(cmd == "size") size(arr);
      else if(cmd == "empty") empty(arr);
      else if(cmd == "top") top(arr);
   }
   return 0;
}

