#include<iostream>
#include<queue>
using namespace std;


//题目：已知二叉树的前序和中序遍历，重建二叉树
struct Node
{
	int data;
	struct Node * lc;
	struct Node * rc;
};

Node * rebuildCore(int * startPreorder,int * endPreorder,
				   int * startMidorder,int * endMidorder)
{
	//根据前序遍历，创建一个新节点
	int rootValue = startPreorder[0];
	Node * root = new Node();
	root->data = rootValue;
	root->lc = root->rc = NULL;
	
	if(startPreorder == endPreorder){
		if(startMidorder == endMidorder && *startPreorder == * startMidorder){
			return root;
		}
	}

	//根据中序遍历寻找根节点
	int * rootMidorder = startMidorder;
	while(rootMidorder <= endMidorder && *rootMidorder != rootValue ){
		rootMidorder ++;
	}
	int leftLength = rootMidorder - startMidorder;
	//重建左子树
	if(leftLength > 0){
		root->lc = rebuildCore(startPreorder + 1,startPreorder + leftLength,
					startMidorder,rootMidorder-1);
	}
	//重建右子树
	if(leftLength < endPreorder - startPreorder){
		root->rc = rebuildCore(startPreorder + leftLength + 1,endPreorder,
								rootMidorder + 1,endMidorder);
	}

	return root;
}


Node * rebuild(int * preorder,int * midorder,int length)
{
	if(preorder == NULL || midorder == NULL || length <= 0)
	{
		return NULL;
	}
	return rebuildCore(preorder,preorder + length -1,
					   midorder,midorder + length -1);
}

//前序遍历二叉树
void preTrave(Node * list)
{
	if(list == NULL){
		return;
	}
	cout<<list->data<<"-->";
	preTrave(list->lc);
	preTrave(list->rc);
}

//中序遍历二叉树
void midTrave(Node * list){
	if(list == NULL){
		return;
	}
	midTrave(list->lc);
	cout<<list->data<<"-->";
	midTrave(list->rc);
}

//层序遍历二叉树
void htrave(Node * list){
	if(list == NULL){
		return;
	}

	queue<Node *> q;
	cout<<list->data<<"-->";
	q.push(list);

	while(!q.empty()){
		Node * n = q.front();
		if(n != NULL){
			if(n->lc != NULL){
				cout<<n->lc->data<<"-->";
				q.push(n->lc);
					
			}
			if(n->rc != NULL){
				cout<<n->rc->data<<"-->";
				q.push(n->rc);
			}
		}
		q.pop();
	}
}
//创建二叉树

Node * create(){
	Node * node = NULL;
	int data;
	cout<<"输入值:(0作为叶子节点)：";
	cin >>data;
	if(data == 0)
		return NULL;
	else{
		node = new Node();
		node->data = data;
		node->lc = create();
		node->rc = create();
	}
	return node;
}

int main(){

	int preOrder[] = {1,2,4,7,3,5,6,8};
	int midOrder[] = {4,7,2,1,5,3,8,6};
	int length = sizeof(preOrder)/sizeof(preOrder[0]);
	Node * tree = rebuild(preOrder,midOrder,length);
	preTrave(tree);
	cout<<endl;
	midTrave(tree);
	cout<<endl;
	htrave(tree);
	return 0;
}




