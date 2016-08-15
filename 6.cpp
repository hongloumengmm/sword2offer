#include<iostream>
#include<queue>
using namespace std;


//��Ŀ����֪��������ǰ�������������ؽ�������
struct Node
{
	int data;
	struct Node * lc;
	struct Node * rc;
};

Node * rebuildCore(int * startPreorder,int * endPreorder,
				   int * startMidorder,int * endMidorder)
{
	//����ǰ�����������һ���½ڵ�
	int rootValue = startPreorder[0];
	Node * root = new Node();
	root->data = rootValue;
	root->lc = root->rc = NULL;
	
	if(startPreorder == endPreorder){
		if(startMidorder == endMidorder && *startPreorder == * startMidorder){
			return root;
		}
	}

	//�����������Ѱ�Ҹ��ڵ�
	int * rootMidorder = startMidorder;
	while(rootMidorder <= endMidorder && *rootMidorder != rootValue ){
		rootMidorder ++;
	}
	int leftLength = rootMidorder - startMidorder;
	//�ؽ�������
	if(leftLength > 0){
		root->lc = rebuildCore(startPreorder + 1,startPreorder + leftLength,
					startMidorder,rootMidorder-1);
	}
	//�ؽ�������
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

//ǰ�����������
void preTrave(Node * list)
{
	if(list == NULL){
		return;
	}
	cout<<list->data<<"-->";
	preTrave(list->lc);
	preTrave(list->rc);
}

//�������������
void midTrave(Node * list){
	if(list == NULL){
		return;
	}
	midTrave(list->lc);
	cout<<list->data<<"-->";
	midTrave(list->rc);
}

//�������������
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
//����������

Node * create(){
	Node * node = NULL;
	int data;
	cout<<"����ֵ:(0��ΪҶ�ӽڵ�)��";
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




