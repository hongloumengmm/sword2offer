package swordoffer;

import org.junit.Test;
//题目：给一个排序数组的旋转组，找到最小值
public class _8_2 {
	int orderFind(int arr [])
	{	
		int min = arr[0];
		int length = arr.length;
		int index1 = 0;
		int index2 = length -1;
		for(int i = 0; i < length; i++)
		{
			if(arr[i] < min)
				min = arr[i];
		}
		return min;
	}

	int findMin(int arr[]){
		int length = arr.length;
		int index1 = 0;
		int index2 = length -1;
		int indexMid = index1;
		while(index1 < index2){
			if(index2 - index1 == 1){
				return arr[index2];
			}
			indexMid = (index1 + index2) / 2;

			if(arr[indexMid] > arr[index2]){
				index1 = indexMid;
			}else if(arr[indexMid] < arr[index2]){
				index2 = indexMid;
			}else if(arr[index1] == arr[index2] && arr[indexMid] == arr[index2]){
				//这种情况下，无法判断中值到底实在前段还是后段，只能顺序查找
				return orderFind(arr );
			}
		}
		return arr[indexMid];
	}
	
	@Test
	public  void test1(){
//		int arr[] = {3,4,5,1,2};
		int arr[] = {5,6,7,8,1,2,3,4};
//		int arr[] ={1,0,1,1,1};
//		int arr[] ={1,1,1,0,1};
		
		int min = findMin(arr);
		System.out.println(min);
	}
}
