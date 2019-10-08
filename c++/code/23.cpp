#include<iostream>
#include<queue>
using namespace std;

//��Ŀ���������Ĳ������

struct Node{
	int data;
	struct Node * lc;
	struct Node * rc;
};


//����������
Node * create(){
	int data;
	Node * node = NULL;
	cout<<"�ڵ㣺";
	cin >> data;
	if(data == 0)
		return node;
	else{
		node = new Node();
		node->data = data;
		node->lc = create();
		node->rc = create();
	}
	return node;
}

//�������
void vTrave(Node * tree){
	if(tree == NULL)
		 return;
	queue<Node *> q;
	q.push(tree);
	while(!q.empty()){
		Node * node = q.front();
		q.pop();
		if(node != NULL){
			cout<<node->data<<"-->";
			if(node->lc != NULL){
				q.push(node->lc);
			}
			if(node->rc != NULL){
				q.push(node->rc);
			}
		}
		
	}
}


int main(){
	Node * tree = create();
	vTrave(tree);
	cout<<endl;
	return 0;
}