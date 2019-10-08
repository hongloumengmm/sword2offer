#include<iostream>
using namespace std;
//��Ŀ��ͳ��һ�����ֵĶ�������1�ĸ���

//����һ����������������һλ����1���룬ÿ���ж�
int transform1(int n)
{
	int count = 0;
	while(n)
	{
		if(n &1)
			count ++;
		n = n >> 1;
	}
	return count;
}

//����2��ת��˼·ÿ���ƶ���־λ�ж�,flag��Ҫ�ƶ�32��
int transform2(int n)
{
	int count = 0;
	int flag = 1;
	while(flag)
	{
		if(n & flag)
			count ++;
		flag = flag << 1;
	}
	return count;
}

//����3��
int transform3(int n)
{
	int count = 0;
	while(n)
	{
		count ++;
		n = n &(n - 1);
	}
	return count;
}

int main()
{
	cout<<transform1(15)<<endl;
	cout<<transform2(15)<<endl;
	cout<<transform3(15)<<endl;
	return 0;
}