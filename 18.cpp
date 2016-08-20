#include<iostream>
#include<stdlib.h>
#include <stack>
using namespace std;

//题目：两棵二叉树A和B，判断B是不是A的子树

typedef struct Node
{
	int data;
	struct Node *lc;
	struct Node *rc;
}node;

//创建二叉树
node * create(){

	int data;
	node * n = NULL;
	cout<<"输入一个节点(0表示空节点): ";
	cin>>data;
	if(data != 0){
		n = new node();
		n->data = data;
		n->lc = create();
		n->rc = create();
	}
	return n;
}

//前序遍历二叉树
void preTrave(node * head){
	if(head == NULL)
		return;
	cout<<head->data<<"-->";
	preTrave(head->lc);
	preTrave(head->rc);
}

//判断
bool subTree(node * A,node * B){

	if(B == NULL)
		return true;
	if(A == NULL)
		return false;
	bool result = false;
	if(A->data == B->data){			//根节点相同，判断左子树和右子树
		result =  subTree(A->lc,B->lc) && subTree(A->rc,B->rc);
	}else{
		result = subTree(A->lc,B);	//左下移一位
		if(result == false){		//右下移一位
			result = subTree(A->rc,B);
		}
	}
	return result;
}

int main()
{
	cout<<"--A--"<<endl;
	node * A =  create();
	cout<<"--B--"<<endl;
	node * B =  create();
	//	cout<<endl<<"数A"<<endl;
	//	preTrave(A);
	//	cout<<endl<<"数B"<<endl;
	//	preTrave(B);
	cout<<endl<<subTree(A,B)<<endl;
	return 0;
}
