package swordoffer;

import org.junit.Test;

/**
 * Fibonacci数列非递归算法--时间复杂度降低到O(n)
 */
public class _9_1 {
	
	
	public int fibonacci(int n){
		int result [] = {0,1};
		if(n < 2){
			return result[n];
		}
		int f_n2 = result[0];
		int f_n1 = result[1];
		int f_n = 0;
		for (int i = 2; i <= n; i++) {
			f_n = f_n1 + f_n2;
			f_n2 = f_n1;
			f_n1 = f_n;
		}
		return f_n;
	}
	@Test
	public void testFibonacci() throws Exception {
		
		System.out.println(fibonacci(2));
		System.out.println(fibonacci(3));
		System.out.println(fibonacci(4));
		System.out.println(fibonacci(5));
		System.out.println(fibonacci(6));
		System.out.println(fibonacci(7));
	}
}
