#include<iostream>
#include<queue>
using namespace std;

//��Ŀ���������ľ���

struct Node{
	int data;
	struct Node * lc;
	struct Node * rc;
};
//�㷨
Node * mirrow(Node * tree)
{
	if((tree == NULL) || (tree->lc == NULL && tree->rc == NULL))
		return tree;
	Node * temp;
	temp = tree->lc;
	tree->lc = tree->rc;
	tree->rc = temp;
	if(tree->lc != NULL)
		tree->lc = mirrow(tree->lc);
	if(tree->rc != NULL)
		tree->rc = mirrow(tree->rc);
	return tree;
}

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
				//	cout<<node->lc->data<<"-->";
				q.push(node->lc);
			}
			if(node->rc != NULL){
				//	cout<<node->rc->data<<"-->";
				q.push(node->rc);
			}
		}
		
	}
}


int main(){
	Node * tree = create();
	vTrave(tree);
	cout<<endl;
	tree = mirrow(tree);
	vTrave(tree);
	return 0;
}