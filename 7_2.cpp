#include<iostream>
#include<queue>

using namespace std;

//题目：使用连个链表模拟栈的操作
template<typename T> class iStack
{
public:
	queue<T> q1;
	queue<T> q2;

	void ipush(T t);	 //进栈
	T ipop();			 //出栈

};
template<typename T> void iStack<T>::ipush(T t)
{
	//先向非空队列中插入，都为空，就插入q1
	if(!q1.empty()){
		cout<<"q1 push==="<<t<<endl;
		q1.push(t);
	}else if(!q2.empty()){
		cout<<"q2 push==="<<t<<endl;
		q2.push(t);
	} else{
		cout<<"q1 push==="<<t<<endl;
		q1.push(t);		
	}
}

template<typename T> T iStack<T>::ipop()
{
	//先找到非空队列:每次至少有一个是空队列，或者两个都为空队列
	if(!q1.empty()){
		int length = q1.size();
		for(int i = 0;i < length -1 ;i++)
		{
			q2.push(q1.front());
			q1.pop();
		}
		T t = q1.front();
		q1.pop();
		return t;
	}else if(!q2.empty()){
		int length = q2.size();
		for(int i = 0;i < length -1 ;i++)
		{
			q1.push(q2.front());
			q2.pop();
		}
		T t = q2.front();
		q2.pop();
		return t;
	}else{//两个队列都为空
		throw new exception("空队列！！");
	}
}
int main()
{
	iStack<int> s ;
	s.ipush(1);
	s.ipush(2);
	s.ipush(3);

	cout<<s.ipop()<<endl;
	cout<<s.ipop()<<endl;
	cout<<s.ipop()<<endl;
	cout<<s.ipop()<<endl;
	return 0;
}