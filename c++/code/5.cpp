#include<iostream>
#include<stdlib.h>
#include <stack>
using namespace std;

//要求：链表从尾打印到头，不是链表逆置

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
		cout<<"输入一个数字：（-1）结束输入: ";
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

//链表显示

void print(node * list)
{
	node * p = list;
	if(p == NULL){
		cout<<"空链表"<<endl;
		return;
	}
	
	while(p != NULL){
		cout<<p->data<<"-->";
		p = p->next;
	}
}

//方法一：使用栈
void inversePrint(node * list)
{
	if(list == NULL){
		cout<<"空链表"<<endl;
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
//使用递归
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

	//创建链表
	Node * list = create();
	//显示链表
	print(list);
	//方法一
	inversePrint(list);
	//方法二
	inversePrint0(list);

	return 0;

}
