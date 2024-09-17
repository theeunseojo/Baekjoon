#include <iostream>
#include <cmath>
#include <stack>
#define MAX 500001
using namespace std;

class Play{
    public:
        int melody;
        int pret;
};

int main(){
    int n, p;
    cin >> n >> p;

    Play play[MAX];
    // 6개의 줄 
    stack<int> st1;
    stack<int> st2;
    stack<int> st3;
    stack<int> st4;
    stack<int> st5;
    stack<int> st6;
    int cnt = 0;    // 손가락 횟수 세는 변수.
    for(int i = 0; i < n; i++){
       cin >> play[i].melody >> play[i].pret; 
    }

    
    for(int i = 0; i < n; i++){

        int mel = play[i].melody;
        int pret = play[i].pret;

        if(mel == 1){

            if(st1.empty() || pret > st1.top()){
                st1.push(pret);
                cnt++;
            }
            else if(pret < st1.top()){
               while(1){
                  if(st1.empty() || pret > st1.top()){
                     st1.push(pret);
                     cnt++;
                     break;
                  }
                  else if(pret == st1.top()){
                     st1.pop();
                     cnt--;
                  }
                  else{
                     st1.pop();
                     cnt++;
                  }
               }
            }
            
        }
        if(mel == 2){
            if(st2.empty() || pret > st2.top()){
                st2.push(pret);
                cnt++;
            } 
            else if(pret < st2.top()){
               while(1){
                  if(st2.empty() || pret > st2.top()){
                     st2.push(pret);
                     cnt++;
                     break;
                  }
                  else if(pret == st2.top()){
                     st2.pop();
                     cnt--;
                  }
                  else{
                     st2.pop();
                     cnt++;
                  }
               }
            }

        }
        if(mel == 3){
            if(st3.empty() || pret > st3.top()){
                st3.push(pret);
                cnt++;
            }
            else if(pret < st3.top()){
               while(1){
                  if(st3.empty() || pret > st3.top()){
                     st3.push(pret);
                     cnt++;
                     break;
                  }
                  else if(pret == st3.top()){
                     st3.pop();
                     cnt--;
                  }
                  else{
                     st3.pop();
                     cnt++;
                  }
               }
            }
        }
        if(mel == 4){
            if(st4.empty() || pret > st4.top()){
                st4.push(pret);
                cnt++;
            }
            else if(pret < st4.top()){
               while(1){
                  if(st4.empty() || pret > st4.top()){
                     st4.push(pret);
                     cnt++;
                     break;
                  }
                  else if(pret == st4.top()){
                     st4.pop();
                     cnt--;
                  }
                  else{
                     st4.pop();
                     cnt++;
                  }
               }
            }
        }
        if(mel == 5){
            if(st5.empty() || pret > st5.top()){
                st5.push(pret);
                cnt++;
            }
            else if(pret < st5.top()){
               while(1){
                  if(st5.empty() || pret > st5.top()){
                     st5.push(pret);
                     cnt++;
                     break;
                  }
                  else if(pret == st5.top()){
                     st5.pop();
                     cnt--;
                  }
                  else{
                     st5.pop();
                     cnt++;
                  }
               }
            }
        }
        if(mel == 6){
            if(st6.empty() || pret > st6.top()){
                st6.push(pret);
                cnt++;
            }
            else if(pret < st6.top()){
               while(1){
                  if(st6.empty() || pret > st6.top()){
                     st6.push(pret);
                     cnt++;
                     break;
                  }
                  else if(pret == st6.top()){
                     st6.pop();
                     cnt--;
                  }
                  else{
                     st6.pop();
                     cnt++;
                  }
               }
            }
        }
    }

    cout << cnt;
    return 0;
}