#include <iostream>
#define MAX 100001
using namespace std;

int arr[MAX];
int head = 0, rear = 0;
int len = 0;

bool empty(){
    return head == rear;
}

int size(){
    return len;
}
void push(int num){
    arr[rear++] = num;
    len++;
}

int pop(){
    if(empty()) return -1;
    int num = arr[head];
    head++;
    len--;
    return num;
}




int front(){
    if(empty()) return -1;
    return arr[head];
}

int back(){
    if(empty()) return -1;
    return arr[rear - 1];
}

int main(){
    int n;
    cin >> n;

    while(n--){
        string str;
        cin >> str;



        if(str == "push"){
            int x;
            cin >> x;
            push(x);
        }
        else if(str == "pop"){
            cout <<  pop() << endl;
        }
        else if(str == "front"){
            cout << front() << endl;
        }
        else if(str == "back"){
            cout << back() << endl;
        }
        else if(str == "empty"){
            cout << empty() << endl;
        }
        else{
            cout << size() << endl;
        }
        

    }
    return 0;
}