#include<iostream>
#include<stdlib.h>
#include <stack>
using namespace std;

//��Ŀ��ɾ������ĵ�����k���ڵ�
//����˼·��
//1.������������������Ϊn��Ȼ���ٱ���һ�Σ��ڵ�n-k��λ�þ���Ҫ�ҵ�λ��
//	ȱ�㣺��Ҫ��������
//2.ָ��p1��p2��p1�ڵ�k��λ�ú�p2ͬʱ��ʼ���ƣ�p1����ĩλʱ��p2λ�þ���Ҫ�ҵ�λ��
//	ֻ�����һ��

typedef struct Node
{
	int data;
	struct Node *next;
}node;

node * traveAadFind(node * list,int k)
{
	//�ص����ڱ߽��ж�
	// k�������1������k-1ΪԽ�磬������ѭ��;
	// p1ǰ��kλ�Ƿ������жϣ���Ϊ���ܲ�����kλ��
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

int main()
{
	node * list =  create();
	node * k = traveAadFind(list,2);
	cout<< k->data<<endl;

	return 0;
}
