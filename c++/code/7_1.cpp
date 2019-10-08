#include<iostream>
#include<queue>
#include<stack>
using namespace std;


//��Ŀ��ʹ��ջģ�����
template<typename T> class iQueue
{
public:
	stack<int> s1;
	stack<T> s2;
	void ipush(T t);	//������
	T ifront();			//ȡ������Ԫ�أ����ǲ�ɾ��
	void ipop();		//������
};
//������
template<typename T>   void iQueue<T>::ipush(T t)
{
	s1.push(t);
}
//ȡ������Ԫ�أ����ǲ�ɾ��
template<typename T> T iQueue<T>::ifront()
{
	if(s2.empty())
	{
		while(!s1.empty())
		{
			s2.push(s1.top());
			s1.pop();
		}
	}
	if(s2.empty()){
		throw new exception("empty queue!!");
	}
	T t = s2.top();
	return t;
}

//������
template<typename T> void iQueue<T>::ipop()
{
	if(s2.empty()){
		while(!s1.empty()){
			s2.push(s1.top());
			s1.pop();
		}
	}
	if(s2.empty()){
		throw new exception("empty queue!!");
	}
	s2.pop();
}


int main(){
	iQueue<int> q;
	q.ipush(1);
	q.ipush(2);
	q.ipush(3);

	cout<<q.ifront()<<endl;;
	q.ipop();
	cout<<q.ifront()<<endl;;
	q.ipop();
	cout<<q.ifront()<<endl;;
	q.ipop();
	cout<<q.ifront()<<endl;;
	return 0;
}




