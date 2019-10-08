#include<iostream>
#include<queue>
using namespace std;

//题目：判断一个数组是不是二叉搜索树的后序遍历

//算法实现
bool verfy(int s[],int length){
	if(s == NULL || length <= 0)
		return false;
	int root = s[length - 1];
	int i = 0;
	while(i < length-1){
		if(s[i++] > root)
			break;
	}
	int j = i;
	while(j < length - 1){
		if(s[j++] < root)
			return false;
	}
	//	cout<<i<<endl;
	bool left = true,right = true;
	if(i > 0)//存在左子树
		left = verfy(s,i);
	if(i < length-1)
		right =verfy(s + i,length -i );
	return left && right;
}


int main(){
	int arr [] = {5,7,6,9,11,10,8};
	int length = sizeof(arr)/sizeof(arr[0]);
	cout<<verfy(arr,length)<<endl;
	return 0;
}