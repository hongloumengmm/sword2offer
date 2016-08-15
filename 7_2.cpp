#include<iostream>
#include<queue>

using namespace std;

//��Ŀ��ʹ����������ģ��ջ�Ĳ���
template<typename T> class iStack
{
public:
	queue<T> q1;
	queue<T> q2;

	void ipush(T t);	 //��ջ
	T ipop();			 //��ջ

};
template<typename T> void iStack<T>::ipush(T t)
{
	//����ǿն����в��룬��Ϊ�գ��Ͳ���q1
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
	//���ҵ��ǿն���:ÿ��������һ���ǿն��У�����������Ϊ�ն���
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
	}else{//�������ж�Ϊ��
		throw new exception("�ն��У���");
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