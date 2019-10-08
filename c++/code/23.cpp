#include<iostream>
#include<queue>
using namespace std;

//题目：二叉树的层序遍历

struct Node{
	int data;
	struct Node * lc;
	struct Node * rc;
};


//创建二叉树
Node * create(){
	int data;
	Node * node = NULL;
	cout<<"节点：";
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

//层序遍历
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