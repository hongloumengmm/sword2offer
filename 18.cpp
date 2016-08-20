#include<iostream>
#include<stdlib.h>
#include <stack>
using namespace std;

//��Ŀ�����ö�����A��B���ж�B�ǲ���A������

typedef struct Node
{
	int data;
	struct Node *lc;
	struct Node *rc;
}node;

//����������
node * create(){

	int data;
	node * n = NULL;
	cout<<"����һ���ڵ�(0��ʾ�սڵ�): ";
	cin>>data;
	if(data != 0){
		n = new node();
		n->data = data;
		n->lc = create();
		n->rc = create();
	}
	return n;
}

//ǰ�����������
void preTrave(node * head){
	if(head == NULL)
		return;
	cout<<head->data<<"-->";
	preTrave(head->lc);
	preTrave(head->rc);
}

//�ж�
bool subTree(node * A,node * B){

	if(B == NULL)
		return true;
	if(A == NULL)
		return false;
	bool result = false;
	if(A->data == B->data){			//���ڵ���ͬ���ж���������������
		result =  subTree(A->lc,B->lc) && subTree(A->rc,B->rc);
	}else{
		result = subTree(A->lc,B);	//������һλ
		if(result == false){		//������һλ
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
	//	cout<<endl<<"��A"<<endl;
	//	preTrave(A);
	//	cout<<endl<<"��B"<<endl;
	//	preTrave(B);
	cout<<endl<<subTree(A,B)<<endl;
	return 0;
}
