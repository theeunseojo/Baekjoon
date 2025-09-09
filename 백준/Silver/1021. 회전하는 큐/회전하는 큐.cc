#include <bits/stdc++.h>

using namespace std;

struct node {
    int data;
    node* prev;
    node* next;
 
};

int N;
node* head = NULL;
node* tail = NULL;
int cnt = 0;

void create(int size){
   
    for(int start = 1; start <= size; start++){
        node* temp = new node;
        temp->data = start;
        // 아예 없는 상태 노드 삽입
        if(start == 1){
            head = temp;
            tail = temp;
        }
        // 여러개 있는 상태에서 노드 삽입 
        else{
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
            
        }
        tail->next = head;
        head->prev = tail;
    }
}

void traverse(){
    node* curr = head;
    for(int i = 0; i < N; i++){
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << "\n";
}

void erase(){

    node* temp = head;
    tail->next = head->next;
    head = head->next;
    head->prev = tail;
    delete temp;
    N--;
}

void move(int target){
    int leftDist = 0;
    int rightDist = 0;
    // 왼쪽 거리 측정
    node* curr = head;
    while(curr->data != target){
        curr = curr->next;
        leftDist++;
    }

    // 오른쪽 거리 측정
    curr = head;
    while(curr->data != target){
        curr = curr->prev;
        rightDist++;
    }

    // 비교해서 거리 처리
    if(leftDist <= rightDist){
        while(head->data != target){
            head = head->next;
            tail = tail->next;
            cnt++;
        }
       
        
    }
    else{
        while(head->data != target){
            head = head->prev;
            tail = tail->prev;
            cnt++;
        }
      
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int M;
    cin >> N >> M;
    create(N);

    cin.ignore(); // 버퍼 비우기 
    string line;
    getline(cin, line);
    stringstream ss(line); 
    
    vector<int> targets;
    int num;
    while (ss >> num) {
        targets.push_back(num);
    }

    for(int i = 0; i < M; i++){
        int target = targets[i];
        move(target);
        erase();
       
    }
   
    

   cout << cnt;
   
    return 0;
}