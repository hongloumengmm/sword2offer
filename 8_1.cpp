
#include<iostream>
using namespace std;
//��Ŀ����֪��˾�������ˣ�������ǵ���������

//����ʹ��Ͱ����
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