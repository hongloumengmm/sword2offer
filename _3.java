package swordoffer;

import java.util.Arrays;

import org.junit.Test;

/**
 * 数组查找
 * 
 * @author HQ
 */
public class _3 {

	/**
	 * 方法一：使用递归
	 * @param arr	数组
	 * @param row	开始比较元素所在行：这里是0
	 * @param col	开始比较元素所在列：这里是 列数-1
	 * @param num	寻找的值
	 */
	public boolean find(int[][] arr, int row, int col, int num) {

		if (num < arr[row][col ] && col > 0) {//特别注意越界判断
			col = col - 1;
			return find(arr,row,col,num);
		} else if (num > arr[row][col] && row < arr.length - 1) {//特别注意越界判断
			row = row + 1;
			return find(arr,row,col,num);
		} else if(num == arr[row][col]){
			System.out.println("row:" + row + "   col:" + col);
			return true;
		}
		 return false;
	}
	/**
	 * 方法二：使用while循环
	 * @param arr
	 * @param num
	 * @return
	 */
	public boolean find(int [][] arr,int num){
		int rows = arr.length;
		int cols = arr[0].length;
		int row = 0;
		int col = cols - 1;
		boolean find = false;
		while(row < rows && col >= 0){
			if(num < arr[row][col]){
				col --;
			}else if(num > arr[row][col]){
				row ++;
			}else{
				System.out.println("row:" + row + "   col:" + col);
				find = true;
				break;
			}
		}
		return find;
	}
	
	
//========================================================================
	/**
	 * 方法一：使用递归
	 * @throws Exception
	 */
	@Test
	public void testFind1() throws Exception {
		int arr[][] = { 
				{ 1, 2, 8, 9 }, 
				{ 2, 4, 9, 12 }, 
				{ 4, 7, 10, 13 },
				{ 6, 8, 11, 15 }
		};
		int row = arr.length;
		int col = arr[0].length;
		//开始位置是右上角，所以是0行(col-1)列
		boolean find = find(arr,0,col - 1,7);
		System.out.println(find);

	}
	/**
	 * 方法二：使用while循环
	 * @throws Exception
	 */
	@Test
	public void testFind2() throws Exception {
		int arr[][] = { 
				{ 1, 2, 8, 9 }, 
				{ 2, 4, 9, 12 }, 
				{ 4, 7, 10, 13 },
				{ 6, 8, 11, 15 }
		};
		int row = arr.length;
		int col = arr[0].length;
		//开始位置是右上角，所以是0行(col-1)列
		boolean find = find(arr,7);
		System.out.println(find);
		
	}
}
