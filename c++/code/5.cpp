#include<iostream>
#include<stdlib.h>
#include <stack>
using namespace std;

//Ҫ�������β��ӡ��ͷ��������������

typedef struct Node
{
	int data;
	struct Node *next;
}node;

node * create()
{
	node * head, *newEle,*p;
	head = new node;
	p = head;
	bool flag = true;
	int num;
	while(flag)
	{
		cout<<"����һ�����֣���-1����������: ";
		cin>>num;
		if(num != -1)
		{
			newEle = (node *)malloc(sizeof(node));
			newEle->data = num;
			p->next = newEle;
			p = newEle;
		}else{
			flag = false;
		}
	}
	p->next = NULL;
	p = head;
	head = p->next;
	delete p;

	return head;
}

//������ʾ

void print(node * list)
{
	node * p = list;
	if(p == NULL){
		cout<<"������"<<endl;
		return;
	}
	
	while(p != NULL){
		cout<<p->data<<"-->";
		p = p->next;
	}
}

//����һ��ʹ��ջ
void inversePrint(node * list)
{
	if(list == NULL){
		cout<<"������"<<endl;
		return;
	}

	stack<node *> s;
	node *p = list;
	while(p != NULL){
		s.push(p);
		p = p->next;
	}
	while(!s.empty()){
		p = s.top();
		cout<< p->data<<"-->";
		s.pop();
	}
	cout<<endl;
}
//ʹ�õݹ�
void inversePrint0(node * list)
{
	if(list == NULL){
		return;
	}

	
	if(list ->next != NULL)
	{
		inversePrint0(list->next);
	}
	cout<<list->data<<"-->";

}


int main(){

	//��������
	Node * list = create();
	//��ʾ����
	print(list);
	//����һ
	inversePrint(list);
	//������
	inversePrint0(list);

	return 0;

}
