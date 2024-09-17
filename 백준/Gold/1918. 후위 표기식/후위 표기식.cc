#include <iostream>
#include <string>
#include <stack>
using namespace std;

// 연산자 우선순위를 구하기 위해 사용된 함수
int prec(char ch){
   if(ch == '+' || ch == '-') return 1;
   else if(ch == '*' || ch == '/') return 2;
   return 0;
   
}

int main(){
    
    string str;
    cin >> str;

    stack<char> st;
    for(int i = 0; i < str.length(); i++){
        // 피연산자는 출력 
        if('A' <= str[i] && str[i] <= 'Z') cout << str[i];
        // 스택이 비어있을 경우 , push , '(' 일 경우 , 연산자가 높을 경우push
        else if(st.empty() || str[i] == '(' || prec(str[i]) > prec(st.top())) st.push(str[i]);
        else{   
            // ')' 일때 
            if(str[i] == ')'){
                // ( 나올때까지 pop 과 출력한 후, ( 도 pop 시킴.
                while(1){
                    if(st.top() == '('){
                        st.pop();
                        break;
                    }
                    cout << st.top();
                    st.pop();
                }
            }
            // 같거나 낮은경우 , 조건 만족할때까지 출력 후 , push
            else if(prec(str[i]) <= prec(st.top())){
                while(1){
                    if(st.empty() || st.top() == '(' || prec(str[i]) > prec(st.top())){
                        st.push(str[i]);
                        break;
                    }
                    else{
                        cout << st.top();
                        st.pop();
                    }
                }
                
            }
        }
    }
    // 이후, 스택이 비어있을 경우, 빌때까지 pop 시킨다.
    while(st.empty() == false){
        cout << st.top();
        st.pop();
    }
    return 0;
}