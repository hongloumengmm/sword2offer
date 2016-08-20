#include<iostream>
#include<stdlib.h>
#include <stack>
using namespace std;

//��Ŀ������ת

typedef struct Node
{
	int data;
	struct Node *next;
}node;

node * inverse(node * list)
{
	if(list == NULL || list->next == NULL){
		return list;
	}
	node * p1 = list;
	node * p2 = p1->next;
	node * p3 ;

	while(p2 != NULL){
		p3 = p2->next;
		p2->next = p1;
		p1 = p2;
		p2 = p3;
	}
	list->next = NULL;
	list = p1;
	return list;
}
//��������
node * create(){

	node * head = new node();
	bool flag = true;
	node * p = head;
	int data;
	while(flag){
		cout<<"����һ���ڵ㣺(-1����)";
		cin >> data;
		if(data == -1)
			break;
		node * n = new node();
		n->data = data;
		p->next = n;
		p = p->next;
	}

	p->next = NULL;
	p = head;
	head = p->next;
	delete p;
	return head;
}
//����

void show(node * list)
{
	if(list == NULL)
		return;
	node * p = list;
	while(p != NULL){
		cout<<p->data<<"-->";
		p = p->next;
	}
	cout<<endl;
}

int main()
{
	node * list =  create();
	show(list);
		list = inverse(list);
		show(list);
	return 0;
}
