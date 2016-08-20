#include<iostream>
#include<stdlib.h>
#include <stack>
using namespace std;

//��Ŀ���������������ϲ���һ�����������

typedef struct Node
{
	int data;
	struct Node *next;
}node;

node * merge(node * list1,node * list2)
{
	if(list1 == NULL){
		return list2;
	}else if(list2 == NULL){
		return list1;
	}
	node * newlist = NULL;

	if(list1->data <= list2->data){
		newlist = list1;
		newlist->next = merge(list1->next,list2);
	}else{
		newlist = list2;
		newlist->next = merge(list1,list2->next);
	}
	return newlist;
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
	node * list1 =  create();
	node * list2 =  create();
	list1 = merge(list1,list2);
	show(list1);
	return 0;
}
