
#include<iostream>
using namespace std;
//题目：已知公司有上万人，请对他们的年龄排序

//这里使用桶排序
void ageSort(int ages[]){
	int length = sizeof(ages)/sizeof(ages[0]);
	int oldest = 99 ;
	int timeOfOldest [oldest+1];
	for(int i = 0;i<=oldest;i++){
		timeOfOldest[i] = 0;
	}

	for (int age = 0; age < length; ++age)
	{
		timeOfOldest[age]++;
	}
	int index = 0;
	for (int i = 0; i <= oldest; ++i)
	{
		for (int j = 0; j < timeOfOldest[i]; ++j)
		{
			age[index] = i;
			index++;
		}
	}
		
}

int main()
{
	return 0;
}