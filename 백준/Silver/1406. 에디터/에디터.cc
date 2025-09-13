#include <bits/stdc++.h>

using namespace std;

struct node {
	char data;
	node* left = NULL;
	node* right = NULL;
};

node* head = new node;
node* tail = new node;
node* cursor = tail;




node* create_temp(char data){
	node* temp = new node;
	temp->data = data;

	return temp;
}

void create_node(char data){
	if(head->right == NULL || tail->left == NULL){
		head->right = tail;
		tail->left = head;
	}
	node* temp = create_temp(data);

	// 항상 tail 노드 전에 끼운다.
	(tail->left)->right = temp;
	temp->left = tail->left;

	temp->right = tail;
	tail->left = temp;

}

void move_left(){
	// 맨 앞이 아닐 경우 
	if(cursor->left != head){
		cursor = cursor->left;
	}

	else return;
}

void move_right(){
	// 맨 뒤가 아닐경우
	if(cursor != tail){
		cursor = cursor->right;
	}
	else return;
}

void erase(){
	// 커서가 맨 문장 앞이면 무시 
	if(cursor->left == head){
		return;
	}
	else{
		node* temp = cursor->left;
		(temp->left)->right = cursor;
		cursor->left = temp->left;

		delete temp;
	}
	
}

void insert(char data){

	node* temp = create_temp(data);
	
	// 왼쪽단 연결
	(cursor->left)->right = temp;
	temp->left = cursor->left;

	// 오른쪽단 연결
	temp->right = cursor;
	cursor->left = temp;

}

void command_handler(char cmd){
    if(cmd == 'L') {move_left();}
    else if(cmd == 'D') {move_right();}
    else if(cmd == 'B') {erase();}
    else{
        char data;
        cin >> data;
        insert(data);
    }
}

void traverse(){
	node* curr = head->right;
	if(head->right == tail){
		return;
	}
	while(curr!= NULL && curr != tail ){
		cout << curr->data;
		// cout << "head : " << head << "\n";
		// cout << "tail : " << tail << "\n";
		// cout << "cursor : " << cursor << "\n";
		curr = curr->right;
	}
	
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    string input;
	cin >> input;

	for(int i = 0; i < input.size(); i++){
		create_node(input[i]);
	}

	int command_size;
	cin >> command_size;
	for(int i = 0; i < command_size; i++){
		char cmd;
		cin >> cmd;
		command_handler(cmd);
	}

	traverse();
	return 0;
}