#include<iostream>
#include<queue>
#include<stack>
using namespace std;


//题目：使用栈模拟队列
template<typename T> class iQueue
{
public:
	stack<int> s1;
	stack<T> s2;
	void ipush(T t);	//进队列
	T ifront();			//取出队列元素，但是不删除
	void ipop();		//出队列
};
//进队列
template<typename T>   void iQueue<T>::ipush(T t)
{
	s1.push(t);
}
//取出队列元素，但是不删除
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

//出队列
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




