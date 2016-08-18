package swordoffer;

import java.util.Arrays;

import org.junit.Test;

/**
 * 题目：把数组中奇数放到偶数前面
 */
public class _14 {

	public int[] change(int[] arr) {
		int length = arr.length;
		int i = 0;
		int j = length - 1;
		int temp = 0;
		while (i < j) {
			while ((arr[i] % 2 != 0) && (i < j))
				i++;
			while ((arr[j] % 2 == 0) && (j > i))
				j--;
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
		return arr;
	}

	@Test
	public void testname() throws Exception {
		int arr[] = { 1, 2, 5, 7, 6, 7, 6, 9 };
		System.out.println(Arrays.toString(change(arr)));
	}
}
