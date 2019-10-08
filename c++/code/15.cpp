#include<iostream>
#include<stdlib.h>
#include <stack>
using namespace std;

//题目：删除链表的倒数第k个节点
//本体思路：
//1.遍历链表，计算链表长度为n，然后再遍历一次，在第n-k个位置就是要找的位置
//	缺点：需要遍历两次
//2.指针p1和p2，p1在第k个位置和p2同时开始后移，p1到达末位时候，p2位置就是要找的位置
//	只需遍历一次

typedef struct Node
{
	int data;
	struct Node *next;
}node;

node * traveAadFind(node * list,int k)
{
	//重点在于边界判断
	// k必须大于1，否则k-1为越界，将无线循环;
	// p1前进k位是否合理的判断，因为可能不存在k位，
	if(list == NULL || k < 1){
		return NULL;
	}
	node * p1 = list;
	node * p2 = list;
	for(int i = 0;i< k - 1; i++){
		if(p1->next != NULL){
			p1 = p1->next;
		}else{
			return NULL;
		}
	}
	while(p1->next != NULL){
		p1 = p1->next;
		p2 = p2->next;
	}
	return p2;

}
//创建链表
node * create(){

	node * head = new node();
	bool flag = true;
	node * p = head;
	int data;
	while(flag){
		cout<<"输入一个节点：(-1结束)";
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

int main()
{
	node * list =  create();
	node * k = traveAadFind(list,2);
	cout<< k->data<<endl;

	return 0;
}
