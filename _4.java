package swordoffer;

import java.util.Arrays;

import org.junit.Test;

/**
 * 替换空格
 * @author HQ
 *
 */
public class _4 {

	/**
	 * 要求：把字符串中的空格替换成%20
	 * 书上介绍了两种思路：
	 * 1.遍历字符数组，每遇到空格，插入%20，然后把空格后面的字符全部后移，这样如果有n个空格
	 * 	时间复杂度为n平方
	 * 
	 * 2.思路是：先统计空格的个数，然后计算新数组的长度是多少
	 * 	用两个计数器i和j，i记录原数组的移动的当前位置；j记录新数组的移动的当前位置
	 * 	时间复杂度是n
	 * 
	 * 谁会用第一种方式呢？？
	 */
	public void replace(){
		String str = "we are happy";
		String str0 = "%20";
		
		char[] value = str.toCharArray();
		int count = 0;
		//统计空格数量
		for(int i = 0;i<value.length;i++){
			if(value[i] == ' ')
				count ++;
		}
		//创建新数组----这里特别注意(str0.length()-1)*count 需要减1
		char [] buff = new char[value.length + (str0.length()-1)*count];
		//复制
		for(int i = 0, j = 0;i< value.length;i++){
			if(value[i] == ' '){
				buff[j++] = '%';
				buff[j++] = '2';
				buff[j++] = '0';
			}else{
				buff[j++] = value[i];
			}
		}
		System.out.println(new String(buff));
	}
	
	@Test
	public void testReplace() throws Exception {
		replace();
	}
}
