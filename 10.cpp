#include<iostream>
using namespace std;
//题目：统计一个数字的二进制中1的个数

//方法一：对于正数，右移一位，与1相与，每次判断
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

//方法2：转换思路每次移动标志位判断,flag需要移动32次
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

//方法3：
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